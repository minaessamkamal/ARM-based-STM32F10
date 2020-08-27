/*****************************************/
/* Author  :  Mina Essam                 */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#ifndef STK_CONFIG_H_
#define STK_CONFIG_H_
/* Options: AHB/8
 * 			AHB
 */
#define Clock_Source 	Clock_Source_AHB_8
#define Clear_Register		0x00


#endif /* STK_CONFIG_H_ */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_
void STK_voidInit(void);
void STK_voidSetBusyWait(u32 Copy_u32Ticks);
void STK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void));
void STK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr) (void));
void STK_voidStopIntervalPeriodic(void);
void STK_voidStopIntervalSingle(void);
u32  STK_u32GetELapsedTime(void);
u32  STK_u32GetRemainingTime(void);



#endif /* STK_INTERFACE_H_ */
