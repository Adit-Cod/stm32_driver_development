/******************************************************************************
*****                    STM MAIN HEADER FILE                             *****
******************************************************************************/
/*!
***     \file       stm32f446xx.h
***
***     \author     Aditya Subramanian
***
***
***     \brief      This module is intended to provide key microcontroller specific details.
***     \par        File_description
***
***
***
*\n*/
/*****************************************************************************/

/*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/
#ifndef STM32F446XX_H_
#define STM32F446XX_H_

/*------ standard includes -------*/
#include<stdint.h>
/*------ project includes --------*/

/*------ module includes ---------*/

/*=============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
=============================================================================*/
/* Common Macros */
#define __VO                         volatile
#define __ui32                       uint32_t
#define ENABLE                       0x1
#define DISABLE                      0x0
#define SET                          ENABLE
#define RESET                        DISABLE

/* Processor Specific Macros */
#define NVIC_ISER0                  ((__VO __ui32*)0xE000E100)
#define NVIC_ISER1                  ((__VO __ui32*)0xE000E104)
#define NVIC_ISER2                  ((__VO __ui32*)0xE000E108)
#define NVIC_ISER3                  ((__VO __ui32*)0xE000E10C)

#define NVIC_ICER0                  ((__VO __ui32*)0xE000E180)
#define NVIC_ICER1                  ((__VO __ui32*)0xE000E184)
#define NVIC_ICER2                  ((__VO __ui32*)0xE000E188)
#define NVIC_ICER3                  ((__VO __ui32*)0xE000E18C)

#define NVIC_PR_BASE_ADDR           ((__VO __ui32*)0xE000E400)
#define NO_PR_BITS_IMPLEMENTED      0x4

/* NVIC Priorities */
#define NVIC_IRQ_PRIO0            0
#define NVIC_IRQ_PRIO1            1
#define NVIC_IRQ_PRIO2            2
#define NVIC_IRQ_PRIO3            3
#define NVIC_IRQ_PRIO4            4
#define NVIC_IRQ_PRIO5            5
#define NVIC_IRQ_PRIO6            6
#define NVIC_IRQ_PRIO7            7
#define NVIC_IRQ_PRIO8            8
#define NVIC_IRQ_PRIO9            9
#define NVIC_IRQ_PRIO10           10
#define NVIC_IRQ_PRIO11           11
#define NVIC_IRQ_PRIO12           12
#define NVIC_IRQ_PRIO13           13
#define NVIC_IRQ_PRIO14           14
#define NVIC_IRQ_PRIO15           15

/* Flash Base Address */
#define FLASH_BASEADDR            0x08000000U
#define SRAM1_BASEADDR            0x20000000U
#define SRAM2_BASEADDR            0x2001C000U
#define ROM_BASEADDR              0x1FFF0000U
#define SRAM                      SRAM1_BASEADDR

/* Base Address of Busses */
#define PERIPH_BASEADDR           0x40000000U
#define AHB1_BASEADDR             0x40020000U
#define AHB2_BASEADDR             0x50000000U
#define APB1_BASEADDR             0x40000000U
#define APB2_BASEADDR             0x40010000U

/* Peripheral Base Address */

/* GPIO Base Addresses */
#define GPIOA_BASEADDR             AHB1_BASEADDR
#define GPIOB_BASEADDR            (AHB1_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR            (AHB1_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR            (AHB1_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR            (AHB1_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR            (AHB1_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR            (AHB1_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR            (AHB1_BASEADDR + 0x1C00U)

/* SPI Base Address */
#define SPI1_BASEADDR             (APB2_BASEADDR + 0x3000U)
#define SPI2_BASEADDR             (APB1_BASEADDR + 0x3800U)
#define SPI3_BASEADDR             (APB1_BASEADDR + 0x3C00U)
#define SPI4_BASEADDR             (APB2_BASEADDR + 0x3400U)

/* I2C Base Address */
#define I2C1_BASEADDR             (APB1_BASEADDR + 0x5400U)
#define I2C2_BASEADDR             (APB1_BASEADDR + 0x5800U)
#define I2C3_BASEADDR             (APB1_BASEADDR + 0x5C00U)

/* USART Base Address */
#define USART1_BASEADDR            (APB2_BASEADDR + 0x1000U)
#define USART2_BASEADDR            (APB1_BASEADDR + 0x4400U)
#define USART3_BASEADDR            (APB1_BASEADDR + 0x4800U)
#define UART4_BASEADDR             (APB1_BASEADDR + 0x4C00U)
#define UART5_BASEADDR             (APB1_BASEADDR + 0x5000U)
#define USART6_BASEADDR            (APB2_BASEADDR + 0x1400U)

/* CAN Base Address */
#define CAN1_BASEADDR              (APB1_BASEADDR + 0x6400U)
#define CAN2_BASEADDR              (APB2_BASEADDR + 0x6800U)

/* EXTI Base Address */
#define EXTI_BASEADDR              (APB2_BASEADDR + 0x3C00U)

/* SYSCFG Base Address */
#define SYSCFG_BASEADDR             (APB2_BASEADDR + 0x3800U)

/* RCC Engine Base Address */
#define RCC_BASEADDR                (AHB1_BASEADDR + 0x3800U)

/* RCC Register Access                                   */
#define RCC                         ((RCC_RegDef_t*)RCC_BASEADDR)
/* EXTI Register Access                                  */
#define EXTI                        ((EXTI_RegDef_t*)EXTI_BASEADDR)
/* SYSCFG Register Access                                */
#define SYSCFG                       ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)
/* Clock Access Definition to GPIO ports through RCC Engine */

#define SYSCFG_CLK_ENABLE()         ((RCC->APB2ENR |= 1<<14))

/* Function to assign appropriate value based on Gpio Base Address. used for EXTI Register Assignment */
#define GPIO_BASE_TO_EXTIVAL(pGpiox)   ( (pGpiox == GPIOA)? 0:\
		                                 (pGpiox == GPIOB)? 1:\
		                                 (pGpiox == GPIOC)? 2:\
		                                 (pGpiox == GPIOD)? 3:\
		                                 (pGpiox == GPIOE)? 4:\
		                                 (pGpiox == GPIOF)? 5:\
		                                 (pGpiox == GPIOG)? 6:\
		                                 (pGpiox == GPIOH)? 7:0 )
/* IRQ Numbers EXTI LINE */
#define EXTI0_IRQ_NO                 6
#define EXTI1_IRQ_NO                 7
#define EXTI2_IRQ_NO                 8
#define EXTI3_IRQ_NO                 9
#define EXTI4_IRQ_NO                 10
#define EXTI9_5_IRQ_NO               23
#define EXTI15_10_IRQ_NO             40

/*=============================================================================
=======                       CONSTANTS  &  TYPES                       =======
=============================================================================*/

/* Peripheral Structure Definitions */

/* GPIO structure definition */

typedef struct
{
	/* Port ModeR Register               */
	__VO __ui32 MODER;
    /* Port Output Type Register         */
	__VO __ui32 OTYPER;
    /* Port output Speed Register        */
	__VO __ui32 OSPEEDER;
    /* Port Pull-Up Pull-Down Register   */
	__VO __ui32 PUPDR;
    /* Port Input Data Register          */
	__VO __ui32 IDR;
    /* Port Output Data Register         */
	__VO __ui32 ODR;
    /* Port Bit Set/Reset Register       */
	__VO __ui32 BSRR;
    /* Configuration Lock Register       */
	__VO __ui32 LCKR;
    /* Alternate Function Register       */
	__VO __ui32 AFR[2];
}GPIO_RegDef_t;

/* RCC structure Definition */

typedef struct
{
	/* RCC Clock Control Register   */
	__VO __ui32 CR;
	/* PLL configuration Register   */
	__VO __ui32 PLL_CFGR;
	/* Clock configuration Register */
	__VO __ui32 CFGR;
	/* Clock Interrupt Register     */
	__VO __ui32 CIR;
	/* AHB1 Reset Register          */
	__VO __ui32 AHB1_RSTR;
	/* AHB2 Reset Register          */
	__VO __ui32 AHB2_RSTR;
	/* AHB3 Reset Register          */
	__VO __ui32 AHB3_RSTR;
	/* Reserved                     */
	__VO __ui32 Reserved1;
	/* APB1 Reset Register          */
	__VO __ui32 APB1_RSTR;
	/* APB2 Reset Register          */
	__VO __ui32 APB2_RSTR;
	/* Reserved                     */
	__VO __ui32 Reserved2;
	/* Reserved                     */
	__VO __ui32 Reserved3;
	/* AHB1 clock Enable Register   */
	__VO __ui32 AHB1ENR;
	/* AHB2 clock Enable Register   */
	__VO __ui32 AHB2ENR;
	/* AHB3 clock Enable Register   */
	__VO __ui32 AHB3ENR;
	/* Reserved                     */
	__VO __ui32 Reserved4;
	/* APB1 clock Enable Register   */
	__VO __ui32 APB1ENR;
	/* APB2 clock Enable Register   */
	__VO __ui32 APB2ENR;
	/* Reserved                     */
	__VO __ui32 Reserved5;
	/* Reserved                     */
	__VO __ui32 Reserved6;
	/* AHB1 Low power Mode Enable   */
	__VO __ui32 AHB1_LPENR;
	/* AHB2 Low power Mode Enable   */
	__VO __ui32 AHB2_LPENR;
	/* AHB3 Low power Mode Enable   */
	__VO __ui32 AHB3_LPENR;
	/* Reserved                     */
	__VO __ui32 Reserved7;
	/* APB1 Low power Mode Enable   */
	__VO __ui32 APB1_LPENR;
	/* APB2 Low power Mode Enable   */
	__VO __ui32 APB2_LPENR;
	/* Reserved                     */
	__VO __ui32 Reserved8;
	/* Reserved                     */
	__VO __ui32 Reserved9;
	/* Backup Domain Control Reg    */
    __VO __ui32 BDCR;
	/* clock Control and Status Reg */
    __VO __ui32 CSR;
	/* Reserved                     */
    __VO __ui32 Reserved10;
	/* Reserved                     */
    __VO __ui32 Reserved11;
	/* Spread Spectrum Clock Gen    */
    __VO __ui32 SS_CGR;
    /* PLL I2S configuration Reg    */
    __VO __ui32 PLLI2_SCFGR;
	/* PLL SA1 Configuration Reg    */
    __VO __ui32 PLL_SA1_CFGR;
    /* PLL Configuration Reg        */
    __VO __ui32 DCK_CFGR;
	/* Dedicated Clock Config Reg   */
    __VO __ui32 CK_GATENR;
    /*  clock Gate Enable Register  */
    __VO __ui32 DCK_CFGR2;

}RCC_RegDef_t;

/* Peripheral Register Definition Structure  for EXTI */
typedef struct
{
	/* Interrupt Mask Register           */
     __VO __ui32 IMR;
    /* Event Mask Register               */
    __VO __ui32  EMR;
    /* Rising trigger selection register */
    __VO __ui32  RTSR;
    /* Falling trigger selection register*/
    __VO __ui32  FTSR;
    /* Software interrupt event register */
    __VO __ui32  SWIER;
    /* Pending Register */
    __VO __ui32  PR;

}EXTI_RegDef_t;

/* Peripheral Register Definition Structure for SysCfg */

typedef struct
{
	/* SYSCFG memory re-map register                      */
	__VO __ui32 MEMRMP;
	/* SYSCFG peripheral mode configuration register      */
	__VO __ui32 PMC;
	/* SYSCFG external interrupt configuration register   */
	__VO __ui32 EXTICR[4];
	/* Reserved                                           */
	__VO __ui32 Reserved1[2];
	/* Compensation cell control register                 */
	__VO __ui32 CMPCR;
	/* Reserved                                           */
	__VO __ui32 Reserved2[2];
	/* SYSCFG configuration register                      */
	__VO __ui32 CFGR;

}SYSCFG_RegDef_t;

/* SPI Peripheral Register Definition */
typedef struct
{
	/* Control Register 1                                  */
    __VO __ui32 SPI_CR1;
    /* Control Register 2                                  */
    __VO __ui32 SPI_CR2;
    /* Status Register                                     */
    __VO __ui32 SPI_SR;
    /* Data Register                                       */
    __VO __ui32 SPI_DR;
    /* SPI CRC Polynomial Register                         */
    __VO __ui32 SPI_CRCPR;
    /* SPI CRC Rx Register                                 */
    __VO __ui32 SPI_RXCRCR;
    /* SPI CRC Tx Register                                 */
    __VO __ui32 SPI_TXCRCR;
    /* SPI I2S Configuration Register                      */
    __VO __ui32 SPI_I2SCFGR;
    /* Pre-Scalar Register                                 */
    __VO __ui32 SPI_I2SPR;
}SPI_RegDef_t;

#endif /* STM32F446XX_H_ */
