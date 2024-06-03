/*
 * uart_Types.h
 *
 *  Created on: Sep 23, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_06_UART_UART_TYPES_H_
#define ATMEGA16_01_MCAL_06_UART_UART_TYPES_H_

typedef enum {USART_Asynchronous_Operation,USART_Synchronous_Operation}USART_Mode_Select;
typedef enum { USART_Asynchronous_Normal_Mode,USART_Asynchronous_Double_Speed_Mode,USART_Synchronous_Master_Mode}USART_Operating_Mode;
typedef enum{USART_Disabled_Parity=0,USART_Even_Parity=2,USART_Odd_Parity=3}USART_Parity_Mode;
typedef enum {USART_Stop_1_Bit,USART_Stop_2_Bit}USART_Stop_Bit_Select;
typedef enum {USART_DataSize_5_Bits,USART_DataSize_6_Bits,USART_DataSize_7_Bits,USART_DataSize_8_Bits,USART_DataSize_9_Bits}USART_FrameSize;


typedef enum {USART_Baud_Rate_2400bps=2400,USART_Baud_Rate_4800bps=4800,USART_Baud_Rate_9600bps=9600,USART_Baud_Rate_14_4kbps,USART_Baud_Rate_19_2k,
	          USART_Baud_Rate_28_8k,USART_Baud_Rate_38_4k,USART_Baud_Rate_57_6k,USART_Baud_Rate_115_2k,USART_Baud_Rate_230_4k,USART_Baud_Rate_250k,
			  USART_Baud_Rate_0_5M,USART_Baud_Rate_1M }USART_Baud_Rate;

typedef struct
{
	USART_Mode_Select Mode_Select ;
	USART_Operating_Mode Operating_Mode ;
	USART_Parity_Mode Parity_Mode;
	USART_Stop_Bit_Select Stop_Bit_Select;
	USART_FrameSize FrameSize ;
	USART_Baud_Rate Baud_Rate;

}USART_ConfigType;

#endif /* ATMEGA16_01_MCAL_06_UART_UART_TYPES_H_ */
