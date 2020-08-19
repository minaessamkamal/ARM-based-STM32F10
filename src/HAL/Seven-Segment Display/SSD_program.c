#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"
#include "Delay.h"
static u8 SSD_Numbers[10] = {0x3f, 0x06, 0x5B, 0x4f, 0x66, 0x6D, 0x7D, 0x07, 0x7f, 0x6f};

void SSD_Display(u8 Copy_u8Number)
{

#if SSD_TYPE == COMMON_ANODE
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_A, 		~GET_BIT(SSD_Numbers[Copy_u8Number] , 0));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_B, 		~GET_BIT(SSD_Numbers[Copy_u8Number] , 1));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_C, 		~GET_BIT(SSD_Numbers[Copy_u8Number] , 2));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_D, 		~GET_BIT(SSD_Numbers[Copy_u8Number] , 3));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_E, 		~GET_BIT(SSD_Numbers[Copy_u8Number] , 4));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_F, 		~GET_BIT(SSD_Numbers[Copy_u8Number] , 5));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_G, 		~GET_BIT(SSD_Numbers[Copy_u8Number] , 6));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_DOT, 	~GET_BIT(SSD_Numbers[Copy_u8Number] , 7));
#elif SSD_TYPE == COMMON_CATHODE
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_A, 		GET_BIT(SSD_Numbers[Copy_u8Number] , 0));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_B, 		GET_BIT(SSD_Numbers[Copy_u8Number] , 1));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_C, 		GET_BIT(SSD_Numbers[Copy_u8Number] , 2));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_D, 		GET_BIT(SSD_Numbers[Copy_u8Number] , 3));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_E, 		GET_BIT(SSD_Numbers[Copy_u8Number] , 4));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_F, 		GET_BIT(SSD_Numbers[Copy_u8Number] , 5));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_G, 		GET_BIT(SSD_Numbers[Copy_u8Number] , 6));
	GPIO_voidSetPinValue(SSD_ConnectedPORT, PIN_DOT, 	GET_BIT(SSD_Numbers[Copy_u8Number] , 7));

#endif
}

void SSD_Multiplexing(u8 Cop_u8Number/*15*/){
	GPIO_voidSetPinValue(SSD_ConnectedPORT, Segment2_COM, GPIO_HIGH);
	GPIO_voidSetPinValue(SSD_ConnectedPORT, Segment1_COM, GPIO_LOW);
	SSD_Display((Cop_u8Number % 10)); //5
	delay_ms(10);
	GPIO_voidSetPinValue(SSD_ConnectedPORT, Segment1_COM, GPIO_HIGH);
	GPIO_voidSetPinValue(SSD_ConnectedPORT, Segment2_COM, GPIO_LOW);
	SSD_Display((Cop_u8Number/10)); //1
	delay_ms(10);
}
