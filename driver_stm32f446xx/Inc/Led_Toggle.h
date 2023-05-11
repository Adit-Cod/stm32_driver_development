/******************************************************************************
*****                    STM TOGGLE HEADER FILE                           *****
******************************************************************************/
/*!
***     \file       Led_Toggle.h
***
***     \author     Aditya Subramanian
***
***
***     \brief      This module is intended to provide as header for toggle application.
***     \par        File_description
***
***
***
*\n*/
/*****************************************************************************/

#ifndef LED_TOGGLE_H_
#define LED_TOGGLE_H_

/*------ standard includes -------*/
#include<stdint.h>
/*------ project includes --------*/

/*------ module includes ---------*/

/*=============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
=============================================================================*/
#define USER_BUTTON_PRESSED  0x0
/*=============================================================================
=======                       PUBLIC  FUNCTION DECLARATIONS             =======
=============================================================================*/

void LedToggle_GpioInit(void);
void LedToggle_ButtonInit(void);


#endif /* LED_TOGGLE_H_ */
