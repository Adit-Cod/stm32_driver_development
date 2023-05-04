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

#endif /* INC_STM32F44XX_GPIO_H_ */
