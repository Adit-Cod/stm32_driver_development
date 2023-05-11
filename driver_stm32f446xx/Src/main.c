/******************************************************************************
*****                       STM32 DRIVER MAIN                              *****
******************************************************************************/
/*!
***     \file       main.c
***
***     \author     Aditya Subramanian
***                 Email.. aditya.subramanian3005@gmail.com
***
***     \brief      This module is intended to act as the main file for the stm32 Driver
***     \par        File_description
***                 Main file of the Stm32 Driver
***
***
*\n*/
/*****************************************************************************/

/*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/

#include <stdint.h>
#include <stdio.h>
#include "stm32f446xx.h"
#include "Stm32f44xx_gpio.h"
#include "Stm32f44xx_USART.h"
#include "Stm32f44xx_I2C.h"
#include "Stm32f44xx_SPI.h"
#include "Led_Toggle.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	LedToggle_ButtonInit();
	LedToggle_GpioInit();
    /* Loop forever */
	for(;;);
}

void EXTI0_IRQHandler(void)
{
	GPIO_IRQHandler(0);
}
