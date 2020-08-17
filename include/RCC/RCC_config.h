/*******************************************************************/
/* Author: Mina Essam											   */
/* Version: V01													   */
/* Date:  8 August 2020											   */		
/*******************************************************************/

#ifndef  _RCC_CONFIG_H
#define _RCC_CONFIG_H
/* Options: RCC_HSE_CRYSTAL   
			RCC_HSE_RC
			RCC_HSI
			RCC_PLL
  */
#define RCC_CLOCK_TYPE  RCC_PLL

/* options:    	RCC_PLL_IN_HSI_DIV_2 	
				RCC_PLL_IN_HSE_DIV_2 	
				RCC_PLL_IN_HSE		 	
*/
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT RCC_PLL_IN_HSE
#endif  





/*  Options 2 to 16 for multipliexar value  */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL		RCC_PLLMUL_X9
#endif


#endif
