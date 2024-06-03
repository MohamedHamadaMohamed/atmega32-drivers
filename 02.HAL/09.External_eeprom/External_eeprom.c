/*
 * 09.External_eeprom.c
 *
 *  Created on: Oct 18, 2021
 *      Author: Mohamed Hamada
 */



#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/09.I2C/I2C.h"


#include "External_eeprom.h"


void external_eeprom_init(void)
{

	I2C_init();

}
uint8 external_eeprom_writeByte(uint16 a_address,uint16 a_data)
{

	 I2C_SetAddress(0b1);

	    I2C_Start();
	    if (I2C_getStatus() != TW_START )
	    	return ERROR;
	    I2C_write((uint8)(0XA0|((a_address&0X0700)>>7)));
		if(I2C_getStatus()!=TW_MT_SLA_W_ACK)
			return ERROR;
		I2C_write((uint8)(a_address));
		if(I2C_getStatus()!=TW_MT_DATA_ACK)
			return ERROR;
		I2C_write((a_data));
		if(I2C_getStatus()!=TW_MT_DATA_ACK)
			return ERROR;
		I2C_Stop();
		return SUCCESS;

}
uint8 external_eeprom_readByte(uint16 a_address)
{
       uint16 data;

	   I2C_SetAddress(0b1);

	    I2C_Start();
	    if (I2C_getStatus() != TW_START )
	    	return ERROR;
	    I2C_write((uint8)(0XA0|((a_address&0X0700)>>7)));
		if(I2C_getStatus()!=TW_MT_SLA_W_ACK)
			return ERROR;
		I2C_write((uint8)(a_address));
		if(I2C_getStatus()!=TW_MT_DATA_ACK)
			return ERROR;
		data = I2C_readWithAck();
		if(I2C_getStatus()!=TW_MT_DATA_ACK)
			return ERROR;
		I2C_Stop();
		return SUCCESS;


}

