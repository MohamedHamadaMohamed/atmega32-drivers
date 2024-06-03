/*
 * uart_PBcfg.c
 *
 *  Created on: Sep 26, 2021
 *      Author: Mohamed Hamada
 */

#include "uart_Types.h"

/*
 	USART_Mode_Select Mode_Select ;
	USART_Operating_Mode Operating_Mode ;
	USART_Parity_Mode Parity_Mode;
	USART_Stop_Bit_Select Stop_Bit_Select;
	USART_FrameSize FrameSize ;
	USART_Baud_Rate Baud_Rate;
 * */

USART_ConfigType uartConfig ={USART_Asynchronous_Operation,USART_Asynchronous_Double_Speed_Mode,USART_Disabled_Parity,USART_Stop_1_Bit,USART_DataSize_8_Bits
							,USART_Baud_Rate_9600bps};
