/******************************************************************************
*****                    STM MAIN USART HEADER FILE                       *****
******************************************************************************/
/*!
***     \file       Stm32f44xx_USART.h
***
***     \author     Aditya Subramanian
***
***
***     \brief      This module is intended to provide key USART/UART specific details.
***     \par        File_description
***
***
***
*\n*/
/*****************************************************************************/

/*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/
#ifndef INC_STM32F44XX_USART_H_
#define INC_STM32F44XX_USART_H_

/*------ standard includes -------*/
#include<stdint.h>
/*------ project includes --------*/

/*------ module includes ---------*/
#include "stm32f446xx.h"

/*=============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
=============================================================================*/

/* USART Peripheral Clock Enable Macro */

#define USART1_CLK_EN()    (RCC->APB2ENR |= (1<<4))
#define USART2_CLK_EN()    (RCC->APB1ENR |= (1<<17))
#define USART3_CLK_EN()    (RCC->APB1ENR |= (1<<18))
#define UART4_CLK_EN()     (RCC->APB1ENR |= (1<<19))
#define UART5_CLK_EN()     (RCC->APB1ENR |= (1<<20))
#define USART6_CLK_EN()    (RCC->APB2ENR |= (1<<5))

/* USART Peripheral Clock Disable Macro */

#define USART1_CLK_DI()    (RCC->APB2ENR &= ~(1<<4))
#define USART2_CLK_DI()    (RCC->APB1ENR &= ~(1<<17))
#define USART3_CLK_DI()    (RCC->APB1ENR &= ~(1<<18))
#define UART4_CLK_DI()     (RCC->APB1ENR &= ~(1<<19))
#define UART5_CLK_DI()     (RCC->APB1ENR &= ~(1<<20))
#define USART6_CLK_DI()    (RCC->APB2ENR &= ~(1<<5))

#endif /* INC_STM32F44XX_USART_H_ */
