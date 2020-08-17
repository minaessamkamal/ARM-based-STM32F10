/*******************************************************************/
/* Author: Mina Essam											   */
/* Version: V01													   */
/* Date: 8 August 2020											   */		
/*******************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H
#define 	RCC_AHB		0
#define		RCC_APB1	1
#define 	RCC_APB2	2

void RCC_voidEnableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);
void RCC_voidDisableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);
void RCC_voidInitSysClock(void);




#endif
