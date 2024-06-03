/*
 * SPI.c
 *
 *  Created on: Oct 5, 2021
 *      Author: Mohamed Hamada
 */


#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"


#include "SPI_Types.h"
#include "SPI.h"

void SPI_Init( const SPI_ConfigType* ConfigPtr )
{
/*
	SPI_TypeMode SPI_TypeMode;
	SPI_Mode Mode;
	SPI_data_transmitted_first data_transmitted_first;
	SPI_Clock_Polarity Clock_Polarity;
	SPI_Clock_Phase Clock_Phase;
	SPI_SCK_Frequency SCK_Frequency;

*/
	switch(ConfigPtr->Mode)
	{
	case SPI_Master: SET_BIT(SPCR,MSTR);  break;
	case SPI_Salve  : CLEAR_BIT(SPCR,MSTR);break;
	}
	switch(ConfigPtr->SPI_TypeMode)
	{
	case SPI_INTERRUPT: SET_BIT(SPCR,SPIE);  break;
	case SPI_POOLING  : CLEAR_BIT(SPCR,SPIE);break;
	}

	switch(ConfigPtr->data_transmitted_first)
	{
	case SPI_LSB: SET_BIT(SPCR,DORD);  break;
	case SPI_MSB  : CLEAR_BIT(SPCR,DORD);break;
	}

	switch(ConfigPtr->Clock_Polarity)
	{
	case SPI_Leading_Edge_Rising:CLEAR_BIT(SPCR,CPOL);  break;
	case  SPI_Leading_Edge_Falling: SET_BIT(SPCR,CPOL);break;
	}

	switch(ConfigPtr->Clock_Phase)
	{
	case SPI_Leading_Edge_Sample:CLEAR_BIT(SPCR,CPHA);  break;
	case  SPI_Leading_Edge_Setup: SET_BIT(SPCR,CPHA);break;
	}

	switch(ConfigPtr->SCK_Frequency)
	{
	case SPI_fosc_div_4:    CLEAR_BIT(SPSR,SPI2X);CLEAR_BIT(SPCR,SPR1);CLEAR_BIT(SPCR,SPR0);break;
	case SPI_fosc_div_16:   CLEAR_BIT(SPSR,SPI2X);CLEAR_BIT(SPCR,SPR1);SET_BIT(SPCR,SPR0);break;
	case SPI_fosc_div_64:   CLEAR_BIT(SPSR,SPI2X);SET_BIT(SPCR,SPR1);CLEAR_BIT(SPCR,SPR0);break;
	case SPI_fosc_div_128:  CLEAR_BIT(SPSR,SPI2X);SET_BIT(SPCR,SPR1);SET_BIT(SPCR,SPR0);break;
	case SPI_fosc_div_2:    SET_BIT(SPSR,SPI2X);CLEAR_BIT(SPCR,SPR1);CLEAR_BIT(SPCR,SPR0);break;
	case SPI_fosc_div_8:    SET_BIT(SPSR,SPI2X);CLEAR_BIT(SPCR,SPR1);SET_BIT(SPCR,SPR0);break;
	case SPI_fosc_div_32:   SET_BIT(SPSR,SPI2X);SET_BIT(SPCR,SPR1);CLEAR_BIT(SPCR,SPR0);break;


	}

	SPDR |= (1<<CPHA) | (1<<CPOL);

	SET_BIT(SPCR,SPE);
}
void SPI_DeInit( void )
{
	SPCR=0;
	CLEAR_BIT(SPCR,SPE);


}

void SPI_SendByte(const uint8 Byte)
{
	SPDR = Byte;
	while(BIT_IS_CLEAR(SPSR,SPIF));

}
void SPI_SendString(const uint8 *Data)
{

	uint8 i=0;
	while(Data[i]!='\0')
	{
		SPI_SendByte(Data[i]);

		i++;
	}

}
uint8 SPI_RecieveByte()
{
	SPDR = 0x00;
	uint8 Byte=0;
	while(BIT_IS_CLEAR(SPSR,SPIF));
	  Byte=SPDR;

	return Byte;
}
void SPI_RecieveString(uint8 *Data )
{

	uint8 i=0;
	Data[i]=  SPI_RecieveByte();

	while(Data[i]!='#')
	{
		i++;
		Data[i]=  SPI_RecieveByte();

	}

}
