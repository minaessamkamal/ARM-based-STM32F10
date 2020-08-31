/**********************************************************/
/* Author: 	Mina Essam									  */
/* Date :	31 August 2020								  */
/* Version:	V01											  */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "DIO_interface.h"
#include "LEDMRX_interface.h"
u8 DataArray[8] = {68, 108, 84, 68, 68, 68, 68, 0};
int main (void){
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 3);

	MSTK_voidInit();
	LEDMRX_voidInit();
	LEDMRX_voidDisplay(DataArray);

	return 0;
}
