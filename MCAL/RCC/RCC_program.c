/*******************************************************************/
/* Author: Mina Essam											   */
/* Version: V01													   */
/* Date:  8 August 2020											   */		
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"


void RCC_voidEnableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID){
	if(Copy_u8PeripheralID <=31)
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB: 
			SET_BIT(RCC_AHBENR, Copy_u8PeripheralID);
			break;
		case RCC_APB1: 
			SET_BIT(RCC_APB1ENR, Copy_u8PeripheralID);
			break;
		case RCC_APB2: 
			SET_BIT(RCC_APB2ENR, Copy_u8PeripheralID);
			break;
		}
	}
	else
	{
		/* Return Error  */
	}

}	

void RCC_voidDisableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID){
	if(Copy_u8PeripheralID <=31)
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB: 
			CLR_BIT(RCC_AHBENR, Copy_u8PeripheralID);
			break;
		case RCC_APB1: 
			CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralID);
			break;
		case RCC_APB2: 
			CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralID);
			break;
		}
	}
	else
	{
		/* Return Error  */
	}

}	

void RCC_voidInitSysClock(void){
#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	RCC_CR 		= 0x00010000;    /*  Enable HSE with no bypass */
	RCC_CFGR	= 0x00000001;


#elif RCC_CLOCK_TYPE == RCC_HSE_RC
	RCC_CR 		= 0x00050000;	/* Enable HSE with Bypass */
	RCC_CFGR	= 0x00000001;
#elif RCC_CLOCK_TYPE == RCC_HSI
	RCC_CR 		= 0x000000081; /* Enable HSI  + Trimming =0 */
	RCC_CFGR	= 0x00000000;

#elif RCC_CLOCK_TYPE == RCC_PLL
#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	//RCC_CFGR &=  ~((0x0f) << 18);
	RCC_CFGR = 	0x0000002;
	RCC_CFGR |= ((RCC_PLLMUL_X9) <<18);
	RCC_CR 	 =   0X01000081;


#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	//RCC_CFGR &=  ~((0x0f) << 18);
	RCC_CFGR = 0x00030002;
	RCC_CFGR |= ((RCC_PLLMUL_X9) <<18);
	RCC_CR		= 0x01010000;


#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
	//RCC_CFGR &=  ~((0x0f) << 18);
	RCC_CFGR = 0x00010002;
	RCC_CFGR |= ((RCC_PLLMUL_X9) <<18);
	RCC_CR		= 0x01010000;

#endif
#else
#error("You chose Wrong Clock Type")

#endif
}
