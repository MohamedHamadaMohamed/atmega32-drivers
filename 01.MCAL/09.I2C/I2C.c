/*
 * I2C.c
 *
 *  Created on: Oct 14, 2021
 *      Author: Mohamed Hamada
 */


#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"


#include"I2C_config.h"
#include"I2C.h"



void I2C_init()
{
	TWBR = I2C_SCL_FREQUENCY;
	TWSR =0;

	SET_BIT(TWCR,TWEN);



}

void I2C_Start(void)
{

	/*clear flag*/
	SET_BIT(TWCR,TWINT);

	/*set start bit*/
	SET_BIT(TWCR,TWSTA);

	/*enable I2C */
	SET_BIT(TWCR,TWEN);

	while(BIT_IS_CLEAR(TWCR,TWINT));

}
void I2C_SetAddress(I2C_address a_address)
{

	TWAR = (a_address<<1);

}
void I2C_Stop(void)
{
	/*clear flag*/
	SET_BIT(TWCR,TWINT);

	/*set stop bit*/
	SET_BIT(TWCR,TWSTO);

	/*enable I2C */
	SET_BIT(TWCR,TWEN);

	while(BIT_IS_CLEAR(TWCR,TWINT));
}

void I2C_write(uint8 a_data)
{
	TWDR =a_data;
	/*clear flag*/
	SET_BIT(TWCR,TWINT);
	/*enable I2C */
	SET_BIT(TWCR,TWEN);

	while(BIT_IS_CLEAR(TWCR,TWINT));

}

uint8 I2C_readWithAck(void)
{
	/*clear flag*/
	SET_BIT(TWCR,TWINT);

	SET_BIT(TWCR,TWEA);
	/*enable I2C */
	SET_BIT(TWCR,TWEN);

		while(BIT_IS_CLEAR(TWCR,TWINT));
	return TWDR;
}
uint8 I2C_readWithNack(void)
{
	/*clear flag*/
	SET_BIT(TWCR,TWINT);
	/*enable I2C */
	SET_BIT(TWCR,TWEN);

	while(BIT_IS_CLEAR(TWCR,TWINT));
	return TWDR;
}

uint8 I2C_getStatus(void)
{
	 uint8 status=0;

	 status = TWSR & 0XF8 ;

	 return status;

}

