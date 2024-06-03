

#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/00.DIO/DIO.h"
#include "../../01.MCAL/07.SPI/SPI.h"


#include "Ext_EEPROM.h"

extern Dio_ConfigType  SPI_Master_SS_config    ;
extern Dio_ConfigType  SPI_Master_MOSI_config  ;
extern Dio_ConfigType  SPI_Master_MISO_config  ;
extern Dio_ConfigType  SPI_Master_SCK_config   ;

extern SPI_ConfigType SPI_EEPROM_Config;

#define WREN_OPCODE		    0X06
#define WRITE_OPCODE		0X02
#define READ_OPCODE			0X03


void  EEPROM_init(void)
{
	Dio_Init(  &SPI_Master_SS_config );
	Dio_Init(  &SPI_Master_MOSI_config );
	Dio_Init(  &SPI_Master_MISO_config );
	Dio_Init(  &SPI_Master_SCK_config );

	Dio_WriteChannel( PORT_B,PIN_7, HIGH );


	SPI_Init(&SPI_EEPROM_Config );
	 _delay_ms(10);

}
void EEPROM_WriteByte(uint16 a_address,uint8 a_data)
{

	Dio_WriteChannel( PORT_B,PIN_4, LOW );

	SPI_SendByte(WREN_OPCODE);

	Dio_WriteChannel( PORT_B,PIN_4, HIGH );
    _delay_ms(5);
	Dio_WriteChannel( PORT_B,PIN_4, LOW );
	SPI_SendByte(WRITE_OPCODE);
	SPI_SendByte(a_address);
	SPI_SendByte(a_data);

	Dio_WriteChannel( PORT_B,PIN_4, HIGH );
    _delay_ms(5);


	 _delay_ms(10);


}

uint8 EEPROM_ReadByte( uint16 a_address)
{
	 _delay_ms(1);

	uint8 data =0;

	Dio_WriteChannel( PORT_B,PIN_4, LOW );

	SPI_SendByte(READ_OPCODE);
	SPI_SendByte(a_address);

	data = SPI_RecieveByte();
	Dio_WriteChannel( PORT_B,PIN_4, HIGH );


    return data;
}
