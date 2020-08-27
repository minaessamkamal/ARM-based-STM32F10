/*****************************************/
/* Author  :  Mina Essam                 */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_


#define Clock_Source_AHB 	1
#define Clock_Source_AHB_8	0

#define Count_Flag 		16
#define Counter_Enable 	0
#define TICKINT			1
#define CLKSOURCE		2


#define Max_Number_Count	16777216


typedef struct {
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VALUE;
}SYSTick_registerConfig;

#define systick_ptr ((volatile SYSTick_registerConfig  *) 0xE000E010)


#endif /* STK_PRIVATE_H_ */
