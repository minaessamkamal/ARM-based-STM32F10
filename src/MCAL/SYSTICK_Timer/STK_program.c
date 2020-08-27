/*****************************************/
/* Author  :  Mina Essam                 */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"
void (*Callback) (void);

void STK_voidInit(void){
#if Clock_Source == Clock_Source_AHB_8
	CLR_BIT(systick_ptr->STK_CTRL, CLKSOURCE);
	CLR_BIT(systick_ptr->STK_CTRL, TICKINT);
	CLR_BIT(systick_ptr->STK_CTRL, Counter_Enable);
#elif Clock_Source == Clock_Source_AHB
	SET_BIT(systick_ptr->STK_CTRL, CLKSOURCE);
	CLR_BIT(systick_ptr->STK_CTRL, TICKINT);
	CLR_BIT(systick_ptr->STK_CTRL, Counter_Enable);
#endif
}

void STK_voidSetBusyWait(u32 Copy_u32Ticks){
	if(Copy_u32Ticks <= Max_Number_Count){
		systick_ptr->STK_VALUE = Clear_Register;
		systick_ptr->STK_LOAD |= Copy_u32Ticks;
		systick_ptr->STK_CTRL = 0x00000003;
		while (GET_BIT(systick_ptr->STK_CTRL, Count_Flag) == 0);
	}
	else
	{

	}
}
u32  STK_u32GetELapsedTime(void){
	volatile u32 Copy_u32ElapsedValue;
	Copy_u32ElapsedValue = (systick_ptr->STK_LOAD) - (systick_ptr->STK_VALUE);
	return Copy_u32ElapsedValue;
}
u32  STK_u32GetRemainingTime(void){
	volatile u32 Copy_u32RemainingValue;
	Copy_u32RemainingValue = systick_ptr->STK_VALUE;
	return  Copy_u32RemainingValue;
}

void STK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void)){
	if(Copy_u32Ticks <= Max_Number_Count){
		systick_ptr->STK_VALUE = Clear_Register;
		systick_ptr->STK_LOAD |= Copy_u32Ticks;
		systick_ptr->STK_CTRL = 0x00000003;
		Callback = Copy_ptr;
	}
	else{

	}
}
void STK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr) (void)){
	if(Copy_u32Ticks <= Max_Number_Count){
	systick_ptr->STK_VALUE = Clear_Register;
	systick_ptr->STK_LOAD |= Copy_u32Ticks;
	systick_ptr->STK_CTRL = 0x00000003;
	Callback = Copy_ptr;
	}
	else{

	}
}
void STK_voidStopIntervalPeriodic(void){
systick_ptr->STK_VALUE = Clear_Register;
CLR_BIT(systick_ptr->STK_CTRL, CLKSOURCE);
}
void STK_voidStopIntervalSingle(void){
	systick_ptr->STK_VALUE = Clear_Register;
	CLR_BIT(systick_ptr->STK_CTRL, CLKSOURCE);
}


void SysTick_Handler(void){

}
