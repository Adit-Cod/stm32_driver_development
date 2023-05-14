/******************************************************************************
*****                    STM INTERRUPT HEADER FILE                        *****
******************************************************************************/
/*!
***     \file       Led_InterruptHandle.h
***
***     \author     Aditya Subramanian
***
***
***     \brief      This module is intended to provide as header for toggle application using .
***                 the concpept of Interrupt (GPIO Interrupt)
***     \par        File_description
***
***
***
*\n*/
/*****************************************************************************/
#ifndef LED_INTERRUPTHANDLE_H_
#define LED_INTERRUPTHANDLE_H_

/*------ standard includes -------*/
#include<stdint.h>
/*------ project includes --------*/

/*------ module includes ---------*/

/*=============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
=============================================================================*/

/*=============================================================================
=======                       PUBLIC  FUNCTION DECLARATIONS             =======
=============================================================================*/
void LedInterrupt_ButtonInit(void);

#endif /* LED_INTERRUPTHANDLE_H_ */
