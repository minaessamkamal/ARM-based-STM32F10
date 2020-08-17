/*******************************************************************/
/* Author: Mina Essam											                         */
/* Version: V01													                           */
/* Date:  8 August 2020											                       */		
/*******************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*   Register Definition*/

#define RCC_CR 				*((volatile u32*) 0x40021000)
#define RCC_CFGR  			*((volatile u32*) 0x40021004)
#define RCC_CIR				*((volatile u32*) 0x40021008)
#define RCC_APB2RSTR		*((volatile u32*) 0x4002100C)
#define RCC_APB1RSTR		*((volatile u32*) 0x40021010)
#define RCC_AHBENR			*((volatile u32*) 0x40021014)
#define RCC_APB2ENR			*((volatile u32*) 0x40021018)
#define RCC_APB1ENR			*((volatile u32*) 0x4002101C)
#define RCC_BDCR			*((volatile u32*) 0x40021020)
#define RCC_CSR				*((volatile u32*) 0x40021024)


/* Clock Types */
#define RCC_HSE_CRYSTAL 		0
#define RCC_HSE_RC				1
#define RCC_HSI					2
#define RCC_PLL					3

/* PLL Options */

#define RCC_PLL_IN_HSI_DIV_2 	0
#define RCC_PLL_IN_HSE_DIV_2 	1
#define RCC_PLL_IN_HSE		 	2

/* PLL Multiplier */
#define RCC_PLLMUL_X2			0
#define RCC_PLLMUL_X3			1
#define RCC_PLLMUL_X4			2
#define RCC_PLLMUL_X5			3
#define RCC_PLLMUL_X6			4
#define RCC_PLLMUL_X7			5
#define RCC_PLLMUL_X8			6
#define RCC_PLLMUL_X9			7
#define RCC_PLLMUL_X10			8
#define RCC_PLLMUL_X11			9
#define RCC_PLLMUL_X12			10
#define RCC_PLLMUL_X13			11
#define RCC_PLLMUL_X14			12
#define RCC_PLLMUL_X15			13
#define RCC_PLLMUL_X16			14



/* AHB Prescaler */
#define AHB_Prescaler

#endif
