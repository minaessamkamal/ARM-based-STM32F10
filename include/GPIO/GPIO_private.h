/********************************************************************/
/* Author: Mina Essam											    */
/* Version: V01													    */
/* Date:  12 August 2020											*/		
/********************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define GPIO_PortA_BASE_ADDRESS				 	0x40010800
#define GPIO_PortB_BASE_ADDRESS				  	0x40010C00
#define GPIO_PortC_BASE_ADDRESS					0x40011000


/*				ADDRESSES OF Port A                                      	 */
#define GPIOA_CRL			*((volatile u32*) (GPIO_PortA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH			*((volatile u32*) (GPIO_PortA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR			*((volatile u32*) (GPIO_PortA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR			*((volatile u32*) (GPIO_PortA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSR			*((volatile u32*) (GPIO_PortA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR			*((volatile u32*) (GPIO_PortA_BASE_ADDRESS + 0x14))
#define GPIOA_LCK			*((volatile u32*) (GPIO_PortA_BASE_ADDRESS + 0x18))


/*				ADDRESSES OF PORT B                                     	 */
#define GPIOB_CRL			*((volatile u32*) (GPIO_PortB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH			*((volatile u32*) (GPIO_PortB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR			*((volatile u32*) (GPIO_PortB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR			*((volatile u32*) (GPIO_PortB_BASE_ADDRESS + 0x0C))
#define GPIOB_BSR			*((volatile u32*) (GPIO_PortB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR			*((volatile u32*) (GPIO_PortB_BASE_ADDRESS + 0x14))
#define GPIOB_LCK			*((volatile u32*) (GPIO_PortB_BASE_ADDRESS + 0x18))


/*				ADDRESSES OF PORT C                                    		*/
#define GPIOC_CRL			*((volatile u32*) (GPIO_PortC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH			*((volatile u32*) (GPIO_PortC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR			*((volatile u32*) (GPIO_PortC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR			*((volatile u32*) (GPIO_PortC_BASE_ADDRESS + 0x0C))
#define GPIOC_BSR			*((volatile u32*) (GPIO_PortC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR			*((volatile u32*) (GPIO_PortC_BASE_ADDRESS + 0x14))
#define GPIOC_LCK			*((volatile u32*) (GPIO_PortC_BASE_ADDRESS + 0x18))


#endif
