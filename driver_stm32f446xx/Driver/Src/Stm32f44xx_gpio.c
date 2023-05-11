/******************************************************************************
*****                       STM32 GPIO DRIVER                             *****
******************************************************************************/
/*!
***     \file       Stm32f44xx_gpio.c
***
***     \author     Aditya Subramanian
***                 Email.. aditya.subramanian3005@gmail.com
***
***     \brief      This module is intended to act as the main file for the stm32 GPIO Driver
***     \par        File_description
***                 Main file of the Stm32 GPIO Driver
***
***
*\n*/
/*****************************************************************************/

/*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/

/*------ standard includes -------*/

/*------ project includes --------*/

/*------ module includes --------*/
#include "Stm32f44xx_gpio.h"

/*=============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
=============================================================================*/

/*=============================================================================
=======                       CONSTANTS  &  TYPES                       =======
=============================================================================*/

/*=============================================================================
=======                  PRIVATE FUNCTION DECLARATIONS                  =======
=============================================================================*/

/*=============================================================================
=======                              METHODS                            =======
=============================================================================*/

/*---------------------------------------------------------------------------*/
/*     FUNCTION: GPIO_Init()
 */
/*!    \brief    Initialize the GPIO Peripheral.
 *
 *
 *     \param   GPIO_Handle_t *pGPIOx,uint8_t PinNumber
 *
 *     \returns  void
 *     \pre
 *     \post
 *
 *     \warning
 *//*------------------------------------------------------------------------*/
void GPIO_Init(GPIO_Handle_t *pGPIOx)
{

	/* Configure the Given Pin as per Requested structure */
	static uint32_t gpio_temphandler;
	/* Temp Variable to hold the configuration of register settings */
	static uint8_t EXTI_Temp1,EXTI_Temp2;
	/* Set the MODER Register */
	if( pGPIOx->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		gpio_temphandler = (pGPIOx->GPIO_PinConfig.GPIO_PinMode << (2*pGPIOx->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOx->pGPIOx->MODER &= ~(0x3 << pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOx->pGPIOx->MODER |= gpio_temphandler;
	}
	else
	{
		/* Interrupt Handling for rising Edge, Falling Edge or Both */
		if(pGPIOx->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RE)
		{
			EXTI->RTSR |= (1<<pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
			/* Clear the corresponding FTSR Bit */
            EXTI->FTSR &= ~(1<<pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if(pGPIOx->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FE)
		{
			EXTI->FTSR |= (1<<pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
			/* Clear the corresponding RTSR Bit */
			EXTI->RTSR &= ~(1<<pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if(pGPIOx->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
		{
			EXTI->FTSR |= (1<<pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
			/* Set the corresponding RTSR Bit */
			EXTI->RTSR |= (1<<pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
		}

		/* Configure the GPIO selection in SysConfig_EXTICR */
		EXTI_Temp1 = pGPIOx->GPIO_PinConfig.GPIO_PinNumber/FOUR;
		EXTI_Temp2 = pGPIOx->GPIO_PinConfig.GPIO_PinNumber%FOUR;
		SYSCFG_CLK_ENABLE();
		SYSCFG->EXTICR[EXTI_Temp1] |= (GPIO_BASE_TO_EXTIVAL(pGPIOx->pGPIOx) << (EXTI_Temp2*FOUR));

		/* Configure Interrupt Delivery using the IMR        */
		EXTI->IMR |= (1<<pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
	}

	/* Set the Output Type Register */
	gpio_temphandler = RESET;
	gpio_temphandler = (pGPIOx->GPIO_PinConfig.GPIO_PinOPType << (pGPIOx->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOx->pGPIOx->OTYPER &= ~(0x1 << pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOx->pGPIOx->OTYPER |= gpio_temphandler;

	/* Set the Output Speed */
	gpio_temphandler = RESET;
	gpio_temphandler = (pGPIOx->GPIO_PinConfig.GPIO_PinSpeed << (2*pGPIOx->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOx->pGPIOx->OSPEEDER &= ~(0x3 << pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOx->pGPIOx->OSPEEDER |= gpio_temphandler;

	/* Set the Pull-Up Pull-Down Configuration */

	gpio_temphandler = RESET;
	gpio_temphandler = (pGPIOx->GPIO_PinConfig.PIO_PinPUPDControl << (2*pGPIOx->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOx->pGPIOx->PUPDR &= ~(0x3 << pGPIOx->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOx->pGPIOx->PUPDR |= gpio_temphandler;

	if(GPIO_MODE_AF == pGPIOx->GPIO_PinConfig.GPIO_PinMode)
	{
	   /* Configure Alternate Functionality */
		static uint8_t gpio_AfTemp_handlel,gpio_AfTemp_handleh;
		gpio_AfTemp_handlel = pGPIOx->GPIO_PinConfig.GPIO_PinNumber/8;
		gpio_AfTemp_handleh = pGPIOx->GPIO_PinConfig.GPIO_PinNumber%8;

		pGPIOx->pGPIOx->AFR[gpio_AfTemp_handlel] |= (pGPIOx->GPIO_PinConfig.GPIO_PinAltFunMode << (4*gpio_AfTemp_handleh));
	}
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: GPIO_DeInit()
 */
/*!    \brief    De-Initialize the GPIO Peripheral.
 *
 *
 *     \param   GPIO_Handle_t *pGPIOx
 *
 *     \returns  void
 *     \pre
 *     \post
 *
 *     \warning
 *//*------------------------------------------------------------------------*/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(GPIOA == pGPIOx)
		GPIOA_RESET();
	else if(GPIOB == pGPIOx)
		GPIOB_RESET();
	else if(GPIOC == pGPIOx)
		GPIOC_RESET();
	else if(GPIOD == pGPIOx)
		GPIOD_RESET();
	else if(GPIOE == pGPIOx)
		GPIOE_RESET();
	else if(GPIOF == pGPIOx)
		GPIOF_RESET();
	else if(GPIOG == pGPIOx)
		GPIOG_RESET();
	else if(GPIOH == pGPIOx)
		GPIOH_RESET();

}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: GPIO_ClockControl()
 */
/*!    \brief    Control the Clock Access to the respective GPIO Port through RCC Engine
 *
 *
 *     \param   GPIO_RegDef_t *pGPIOx, uint8_t Control
 *
 *     \returns  void
 *     \pre
 *     \post
 *
 *     \warning
 *//*------------------------------------------------------------------------*/
void GPIO_ClockControl(GPIO_RegDef_t *pGPIOx,uint8_t Control)
{
	if(ENABLE == Control)
	{
		/* Enable Requested */
		if(GPIOA == pGPIOx)
			GPIOA_CLK_EN();
		else if(GPIOB == pGPIOx)
			GPIOB_CLK_EN();
		else if(GPIOC == pGPIOx)
			GPIOC_CLK_EN();
		else if(GPIOD == pGPIOx)
			GPIOD_CLK_EN();
		else if(GPIOE == pGPIOx)
			GPIOE_CLK_EN();
		else if(GPIOF == pGPIOx)
			GPIOF_CLK_EN();
		else if(GPIOG == pGPIOx)
			GPIOG_CLK_EN();
		else if(GPIOH == pGPIOx)
			GPIOH_CLK_EN();
		else
		{ /* Error Handling */}
	}
	else
	{
		/* Disable Requested */
		if(GPIOA == pGPIOx)
			GPIOA_CLK_DI();
		else if(GPIOB == pGPIOx)
			GPIOB_CLK_DI();
		else if(GPIOC == pGPIOx)
			GPIOC_CLK_DI();
		else if(GPIOD == pGPIOx)
			GPIOD_CLK_DI();
		else if(GPIOE == pGPIOx)
			GPIOE_CLK_DI();
		else if(GPIOF == pGPIOx)
			GPIOF_CLK_DI();
		else if(GPIOG == pGPIOx)
			GPIOG_CLK_DI();
		else if(GPIOH == pGPIOx)
			GPIOH_CLK_DI();
		else
		{ /* Error Handling */}
	}
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: GPIO_ReadPin()
 */
/*!    \brief    Read Value from the given Pin
 *
 *
 *     \param   GPIO_RegDef_t *pGPIOx,uint8_t PinNumber
 *
 *     \returns  uint8_t Pin Read out Value
 *     \pre
 *     \post
 *
 *     \warning
 *//*------------------------------------------------------------------------*/
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
    uint8_t retVal;
    retVal = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x1 );
	return retVal;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: GPIO_ReadPort()
 */
/*!    \brief    Read Value from the given Port
 *
 *
 *     \param   GPIO_Handle_t *pGPIOx
 *
 *     \returns  uint16_t Port Read out Value
 *     \pre
 *     \post
 *
 *     \warning
 *//*------------------------------------------------------------------------*/
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t retVal;
	retVal = (uint16_t)(pGPIOx->IDR);
    return retVal;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: GPIO_WritePin()
 */
/*!    \brief    Write Value to the given Pin
 *
 *
 *     \param   GPIO_RegDef_t *pGPIOx,uint8_t PinNumber, uint8_t Value
 *
 *     \returns  void
 *     \pre
 *     \post
 *
 *     \warning
 *//*------------------------------------------------------------------------*/

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
		pGPIOx->ODR |=  (GPIO_PIN_SET << PinNumber);
	else
		pGPIOx->ODR &=  ~(GPIO_PIN_SET << PinNumber);

}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: GPIO_WritePort()
 */
/*!    \brief    Write Value to the given Port
 *
 *
 *     \param   GPIO_RegDef_t *pGPIOx, uint8_t Value
 *
 *     \returns  void
 *     \pre
 *     \post
 *
 *     \warning
 *//*------------------------------------------------------------------------*/
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx,uint16_t Value)
{
	pGPIOx->ODR = Value;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: GPIO_TogglePin()
 */
/*!    \brief    Toggle Given GPIO PIN
 *
 *
 *     \param   GPIO_RegDef_t *pGPIOx, uint8_t PinNumber
 *
 *     \returns  void
 *     \pre
 *     \post
 *
 *     \warning
 *//*------------------------------------------------------------------------*/
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR ^= (GPIO_PIN_SET << PinNumber);
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: GPIO_IRQConfig()
 */
/*!    \brief    Configure IRQ for a given GPIO
 *
 *
 *     \param   uint8_t IRQNumber, uint8_t IRQPriority, uint8_t Action
 *
 *     \returns  void
 *     \pre
 *     \post
 *
 *     \warning
 *//*------------------------------------------------------------------------*/
void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t Action )
{
    if(Action == ENABLE)
    {
    	if(IRQNumber <= 31)
    	{
            /* Program ISER0 Register. Refer to ARM Cortex M4 Manual */
            *(NVIC_ISER0) |= (1 << IRQNumber);
    	}
    	else if(IRQNumber >31 && IRQNumber < 64)
    	{
    	    /* Program ISER1 Register. Refer to ARM Cortex M4 Manual */
    		*(NVIC_ISER1) |= (1 << IRQNumber%32);
    	}
    	else if(IRQNumber >=64 && IRQNumber < 96)
    	{
    		/* Program ISER2 Register. Refer to ARM Cortex M4 Manual */
    		*(NVIC_ISER3) |= (1 << IRQNumber%64);
    	}
    }
    else
    {
    	if(IRQNumber <= 31)
    	{
            /* Program ISER0 Register. Refer to ARM Cortex M4 Manual */
            *(NVIC_ICER0) |= (1 << IRQNumber);
    	}
    	else if(IRQNumber >31 && IRQNumber < 64)
    	{
    	    /* Program ISER1 Register. Refer to ARM Cortex M4 Manual */
    		*(NVIC_ICER1) |= (1 << IRQNumber%32);
    	}
    	else if(IRQNumber >=64 && IRQNumber < 96)
    	{
    		/* Program ISER2 Register. Refer to ARM Cortex M4 Manual */
    		*(NVIC_ICER3) |= (1 << IRQNumber%64);
    	}
    }
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: GPIO_IRQPriorityConfig()
 */
/*!    \brief    Set the Priority
 *
 *
 *     \param   uint8_t IRQNumber,uin8_t Priority
 *
 *     \returns  void
 *     \pre
 *     \post
 *
 *     \warning
 *//*------------------------------------------------------------------------*/
void GPIO_IRQPriorityConfig(uint8_t IRQNumber,uint8_t Priority)
{
	static uint8_t iprx,iprx_section,shift_amount;
	/* Calculate which row the insertion needs to take place*/
	iprx = IRQNumber/4;
	/* Calculate the exact section into which data needs to be written. For a figurative description; refer to the NVIC PR table in ARM M4 Manual */
	iprx_section =  IRQNumber%4;
	/* Calculate the exact shift amount by addding 4 (the lower 4 bits are not used as per the manual and hence only higher nibble is written to) */
	shift_amount = (8*iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);
	/* Write to the register's appropriate position based on above calculation */
	*(NVIC_PR_BASE_ADDR + iprx*4) |= (Priority<< shift_amount);

}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: GPIO_IRQHandler()
 */
/*!    \brief    Handle IRQ for a given GPIO
 *
 *
 *     \param   uint8_t PinNumber
 *
 *     \returns  void
 *     \pre
 *     \post
 *
 *     \warning
 *//*------------------------------------------------------------------------*/
void GPIO_IRQHandler(uint8_t PinNumber)
{
	/*Called by Respective IRQ Handler */
	if(EXTI->PR &(1<< PinNumber))
	{
		EXTI->PR |= (1<<PinNumber);
	}
}
