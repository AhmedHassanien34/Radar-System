/**************************************************************************************/
/********************		Author: Ahmed Mohamed		***********************/
/********************		Layer: APP			***********************/
/********************		Component: MASTER ECU	        ***********************/
/********************		Version: 1.00		 	***********************/
/********************		Date: 16-12-2022	 	***********************/
/**************************************************************************************/

#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SvM_interface.h"
#include "Ultrasonic_interface.h"
#include "UART_interface.h"
#include "GIE_interface.h"

void main(void)
{
	u8 itr;
	GIE_voidEnable();
	USART_voidInit();
	SVM_voidServoInit();
	Ultrasonic_voidInit();

	while(1)
	{
		for(itr=10;itr<170;itr++)
		{
			SVM_voidSetAngle2(itr);				// Set Angle
			_delay_ms(30);
			UART_voidSendDecimalNumber(itr);		// Send the Angle By Uart Protocol
			USART_voidSend(',');
			Ultra_voidTriger();				// Send the Distance By Uart Protocol
			USART_voidSend('.');
		}

		for(itr=170;itr>10;itr--)
		{
			SVM_voidSetAngle2(itr);				// Set Angle
			_delay_ms(30);
			UART_voidSendDecimalNumber(itr);		// Send the Angle By Uart Protocol
			USART_voidSend(',');
			Ultra_voidTriger();		          	// Send the Distance By Uart Protocol
			USART_voidSend('.');
		}
		
	}
}
