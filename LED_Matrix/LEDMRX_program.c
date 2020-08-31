/**********************************************************/
/* Author: 	Mina Essam									  */
/* Date :	31 August 2020								  */
/* Version:	V01											  */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"


void LEDMRX_voidInit(void){

	MGPIO_VidSetPinDirection(LEDMRX_ROW0_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_ROW1_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_ROW2_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_ROW3_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_ROW4_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_ROW5_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_ROW6_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_ROW7_PIN, OUTPUT_SPEED_2MHZ_PP);

	MGPIO_VidSetPinDirection(LEDMRX_Cloumn0_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_Cloumn1_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_Cloumn2_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_Cloumn3_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_Cloumn4_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_Cloumn5_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_Cloumn6_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(LEDMRX_Cloumn7_PIN, OUTPUT_SPEED_2MHZ_PP);
}


void LEDMRX_voidDisplay(u8 *Copy_u8Data){
	while(1)
	{
		/* Column 0 */
		DisableAllColumns();
		SetRowValues(Copy_u8Data[0]);
		MGPIO_VidSetPinValue(LEDMRX_Cloumn0_PIN, LOW);
		MSTK_voidSetBusyWait(2500); //2.5 msec



		/* Column 1 */

		DisableAllColumns();
		SetRowValues(Copy_u8Data[1]);
		MGPIO_VidSetPinValue(LEDMRX_Cloumn1_PIN, LOW);
		MSTK_voidSetBusyWait(2500); //2.5 msec


		/* Column 1 */
		DisableAllColumns();
		SetRowValues(Copy_u8Data[2]);
		MGPIO_VidSetPinValue(LEDMRX_Cloumn2_PIN, LOW);
		MSTK_voidSetBusyWait(2500); //2.5 msec


		/*Disable Column */
		DisableAllColumns();
		SetRowValues(Copy_u8Data[3]);
		MGPIO_VidSetPinValue(LEDMRX_Cloumn3_PIN, LOW);
		MSTK_voidSetBusyWait(2500); //2.5 msec


		DisableAllColumns();
		SetRowValues(Copy_u8Data[4]);
		MGPIO_VidSetPinValue(LEDMRX_Cloumn4_PIN, LOW);
		MSTK_voidSetBusyWait(2500); //2.5 msec


		DisableAllColumns();
		/* Enable Column 0 */

		SetRowValues(Copy_u8Data[5]);
		MGPIO_VidSetPinValue(LEDMRX_Cloumn5_PIN, LOW);
		MSTK_voidSetBusyWait(2500); //2.5 msec

		/* Column 1 */
		/*Disable Column */
		DisableAllColumns();
		/* Enable Column 0 */
		SetRowValues(Copy_u8Data[6]);
		MGPIO_VidSetPinValue  (LEDMRX_Cloumn6_PIN, LOW);
		MSTK_voidSetBusyWait(2500); //2.5 msec

		/* Column 1 */
		/*Disable Column */
		DisableAllColumns();
		/* Enable Column 0 */
		SetRowValues(Copy_u8Data[7]);
		MGPIO_VidSetPinValue  (LEDMRX_Cloumn7_PIN, LOW);
		MSTK_voidSetBusyWait(2500); //2.5 msec

	}
}
static void DisableAllColumns(void){

	MGPIO_VidSetPinValue  (LEDMRX_Cloumn0_PIN, HIGH);
	MGPIO_VidSetPinValue  (LEDMRX_Cloumn1_PIN, HIGH);
	MGPIO_VidSetPinValue  (LEDMRX_Cloumn2_PIN, HIGH);
	MGPIO_VidSetPinValue  (LEDMRX_Cloumn3_PIN, HIGH);
	MGPIO_VidSetPinValue  (LEDMRX_Cloumn4_PIN, HIGH);
	MGPIO_VidSetPinValue  (LEDMRX_Cloumn5_PIN, HIGH);
	MGPIO_VidSetPinValue  (LEDMRX_Cloumn6_PIN, HIGH);
	MGPIO_VidSetPinValue  (LEDMRX_Cloumn7_PIN, HIGH);
}
static void SetRowValues(u8 Copy_u8Value){
	u8 Local_u8BIT;
	Local_u8BIT = GET_BIT(Copy_u8Value, 0);
	MGPIO_VidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 1);
	MGPIO_VidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 2);
	MGPIO_VidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 3);
	MGPIO_VidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 4);
	MGPIO_VidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 5);
	MGPIO_VidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 6);
	MGPIO_VidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
	Local_u8BIT = GET_BIT(Copy_u8Value, 7);
	MGPIO_VidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
}
