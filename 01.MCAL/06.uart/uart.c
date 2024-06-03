/*
 * uart.c
 *
 *  Created on: Sep 23, 2021
 *      Author: Mohamed Hamada
 */



#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "uart_Types.h"
#include "uart.h"

#define BAUD_PRESCALE_NORMAL_MODE             (((F_CPU / (ConfigType->Baud_Rate * 16UL))) - 1)
#define BAUD_PRESCALE_DOUBLE_SPEED_MODE       (((F_CPU / (ConfigType->Baud_Rate * 8UL ))) - 1)
#define BAUD_PRESCALE_SYNCHRONOUS_MASTER_MODE (((F_CPU / (ConfigType->Baud_Rate * 2UL ))) - 1)

void USART_init(USART_ConfigType *ConfigType )
{
/*
	USART_Parity_Mode Parity_Mode;
	USART_Stop_Bit_Select Stop_Bit_Select;
	USART_FrameSize FrameSize ;
	USART_Baud_Rate Baud_Rate;
	*/
	uint8 Baud_Prescale =0 ;
	SET_BIT(UCSRC,URSEL);  /*enable UCSRC*/

	switch(ConfigType->Mode_Select)
	{
	case USART_Asynchronous_Operation:CLEAR_BIT(UCSRC,UMSEL);	 break;
	case USART_Synchronous_Operation :SET_BIT(UCSRC,UMSEL);	     break;

	}
	switch(ConfigType->Operating_Mode)
	{
	case USART_Asynchronous_Normal_Mode: CLEAR_BIT(UCSRA,U2X);     Baud_Prescale = BAUD_PRESCALE_NORMAL_MODE ;          break;
	case USART_Asynchronous_Double_Speed_Mode: SET_BIT(UCSRA,U2X);  Baud_Prescale = BAUD_PRESCALE_DOUBLE_SPEED_MODE;           break;
	case USART_Synchronous_Master_Mode:                             Baud_Prescale=BAUD_PRESCALE_SYNCHRONOUS_MASTER_MODE;   break;
	}



	UCSRC &=0b11001111;
	UCSRC |=(ConfigType->Parity_Mode<<4);

	UCSRC &=0b11110111;
	UCSRC |=(ConfigType->Stop_Bit_Select<<3);

	switch(ConfigType->FrameSize)
	{
	case USART_DataSize_5_Bits:  CLEAR_BIT(UCSRB,UCSZ2);CLEAR_BIT(UCSRC,UCSZ1);		CLEAR_BIT(UCSRC,UCSZ0);	break;
	case USART_DataSize_6_Bits:  CLEAR_BIT(UCSRB,UCSZ2);CLEAR_BIT(UCSRC,UCSZ1);		SET_BIT(UCSRC,UCSZ0);	break;
	case USART_DataSize_7_Bits:  CLEAR_BIT(UCSRB,UCSZ2);SET_BIT(UCSRC,UCSZ1);		CLEAR_BIT(UCSRC,UCSZ0);	break;
	case USART_DataSize_8_Bits:  CLEAR_BIT(UCSRB,UCSZ2);SET_BIT(UCSRC,UCSZ1); 	    SET_BIT(UCSRC,UCSZ0);	break;
	case USART_DataSize_9_Bits:  SET_BIT(UCSRB,UCSZ2);  SET_BIT(UCSRC,UCSZ1);       SET_BIT(UCSRC,UCSZ0);	break;
	}

	CLEAR_BIT(UBRRH,URSEL);
	UBRRH = (Baud_Prescale)>> 8;
	UBRRL = Baud_Prescale ;


	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}
void USART_SendByte(const uint8 Byte)
{
	UDR =Byte;
	while(BIT_IS_CLEAR(UCSRA,TXC));
	SET_BIT(UCSRA,TXC);

}

void USART_SendString(const uint8 *Data)
{
	uint8 i=0;
	while(Data[i]!='\0')
	{
		USART_SendByte(Data[i]);
		i++;

	}
}
char USART_RecieveByte()
{
	while(BIT_IS_CLEAR(UCSRA,RXC));
return UDR;
}
void USART_RecieveString(uint8 *Data )
{
	uint8 i=0;
	Data[0]= USART_RecieveByte();
	while(Data[i]!='#');
	{
		i++;
		Data[i]= USART_RecieveByte();

	}
	Data[i] ='\0';



}
