/*
 * uart.h
 *
 *  Created on: Sep 23, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_06_UART_UART_H_
#define ATMEGA16_01_MCAL_06_UART_UART_H_


#include "uart_Types.h"

void USART_init(USART_ConfigType *ConfigType );
void USART_SendByte(const uint8 Byte);
void USART_SendString(const uint8 *Data);
char USART_RecieveByte();
void USART_RecieveString(uint8 *Data );

#endif /* ATMEGA16_01_MCAL_06_UART_UART_H_ */
