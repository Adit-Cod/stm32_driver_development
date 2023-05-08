/******************************************************************************
*****                    STM MAIN GPIO HEADER FILE                        *****
******************************************************************************/
/*!
***     \file       stm32f44xx_gpio.h
***
***     \author     Aditya Subramanian
***
***
***     \brief      This module is intended to provide key GPIO specific details.
***     \par        File_description
***
***
***
*\n*/
/*****************************************************************************/

/*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/
#ifndef INC_STM32F44XX_GPIO_H_
#define INC_STM32F44XX_GPIO_H_


/*------ standard includes -------*/
#include<stdint.h>
/*------ project includes --------*/

/*------ module includes ---------*/
#include "stm32f446xx.h"

/*=============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
=============================================================================*/
/* GPIO MACRO Definitions */

/* Access to GPIO A structure with corresponding address */
#define GPIOA    ((GPIO_RegDef_t*)GPIOA_BASEADDR)
/* Access to GPIO B structure with corresponding address */
#define GPIOB    ((GPIO_RegDef_t*)GPIOB_BASEADDR)
/* Access to GPIO C structure with corresponding address */
#define GPIOC    ((GPIO_RegDef_t*)GPIOC_BASEADDR)
/* Access to GPIO D structure with corresponding address */
#define GPIOD    ((GPIO_RegDef_t*)GPIOD_BASEADDR)
/* Access to GPIO E structure with corresponding address */
#define GPIOE    ((GPIO_RegDef_t*)GPIOE_BASEADDR)
/* Access to GPIO F structure with corresponding address */
#define GPIOF    ((GPIO_RegDef_t*)GPIOF_BASEADDR)
/* Access to GPIO G structure with corresponding address */
#define GPIOG    ((GPIO_RegDef_t*)GPIOG_BASEADDR)
/* Access to GPIO H structure with corresponding address */
#define GPIOH    ((GPIO_RegDef_t*)GPIOH_BASEADDR)
/* RCC Register Access=                                  */
#define RCC                         ((RCC_RegDef_t*)RCC_BASEADDR)

/* Clock Access Definition to GPIO ports through RCC Engine*/
#define GPIOA_CLK_EN()     ((RCC->AHB1ENR |= 1<<0))
#define GPIOB_CLK_EN()     ((RCC->AHB1ENR |= 1<<1))
#define GPIOC_CLK_EN()     ((RCC->AHB1ENR |= 1<<2))
#define GPIOD_CLK_EN()     ((RCC->AHB1ENR |= 1<<3))
#define GPIOE_CLK_EN()     ((RCC->AHB1ENR |= 1<<4))
#define GPIOF_CLK_EN()     ((RCC->AHB1ENR |= 1<<5))
#define GPIOG_CLK_EN()     ((RCC->AHB1ENR |= 1<<6))
#define GPIOH_CLK_EN()     ((RCC->AHB1ENR |= 1<<7))

/* Disable GPIO Ports WHEN not needed. Note: By Default Register holds a 0 by default */

#define GPIOA_CLK_DI()     ((RCC->AHB1ENR &= ~(1<<0)))
#define GPIOB_CLK_DI()     ((RCC->AHB1ENR &= ~(1<<1)))
#define GPIOC_CLK_DI()     ((RCC->AHB1ENR &= ~(1<<2)))
#define GPIOD_CLK_DI()     ((RCC->AHB1ENR &= ~(1<<3)))
#define GPIOE_CLK_DI()     ((RCC->AHB1ENR &= ~(1<<4)))
#define GPIOF_CLK_DI()     ((RCC->AHB1ENR &= ~(1<<5)))
#define GPIOG_CLK_DI()     ((RCC->AHB1ENR &= ~(1<<6)))
#define GPIOH_CLK_DI()     ((RCC->AHB1ENR &= ~(1<<7)))

#define GPIO_PIN_SET       SET
#define GPIO_PIN_RESET     RESET
/*=============================================================================
=======                       CONSTANTS  &  TYPES                       =======
=============================================================================*/

/* GPIO PIN Configuration Structure Definition */

typedef struct
{
	/* GPIO Pin Number      */
   uint8_t GPIO_PinNumber;
   /* GPIO Pin Mode         */
   uint8_t GPIO_PinMode;
   /* GPIO Pin Speed        */
   uint8_t GPIO_PinSpeed;
   /* GPIO Pin PuPd Control */
   uint8_t PIO_PinPUPDControl;
   /* GPIO Pin Output Type  */
   uint8_t GPIO_PinOPType;
   /* GPIO Pin AF Mode      */
   uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/* GPIO Handle Structure Definition */

typedef struct
{
	/* Pointer to the Base Address of the GPIO Peripheral. */
	GPIO_RegDef_t *pGPIOx;
	/* Structure to hold the Pin configurations            */
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

/*=============================================================================
=======                       PUBLIC  FUNCTION DECLARATIONS             =======
=============================================================================*/

uint8_t GPIO_ReadPin(GPIO_Handle_t *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadPort(GPIO_Handle_t *pGPIOx);
void GPIO_ClockControl(GPIO_RegDef_t *pGPIOx,uint8_t Control);
void GPIO_Init(GPIO_Handle_t *pGPIOx);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
void GPIO_WritePin(GPIO_Handle_t *pGPIOx,uint8_t PinNumber, uint8_t Value);
void GPIO_WritePort(GPIO_Handle_t *pGPIOx,uint16_t Value);
void GPIO_TogglePin(GPIO_Handle_t *pGPIOx,uint8_t PinNumber);
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t Action );
void GPIO_IRQHandler(uint8_t PinNumber);

#endif /* INC_STM32F44XX_GPIO_H_ */
