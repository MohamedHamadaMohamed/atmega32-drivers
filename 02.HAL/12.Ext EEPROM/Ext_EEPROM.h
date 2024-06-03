/*
 * External_EEPROM.h
 *
 *  Created on: Nov 11, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_02_HAL_12_EXT_EEPROM_EXT_EEPROM_H_
#define ATMEGA16_02_HAL_12_EXT_EEPROM_EXT_EEPROM_H_

#include "../../00.LIB/Std_types.h"

void  EEPROM_init(void);
void  EEPROM_WriteByte(uint16 a_address,uint8 a_data);
uint8 EEPROM_ReadByte( uint16 a_address);

#endif /* ATMEGA16_02_HAL_12_EXT_EEPROM_EXT_EEPROM_H_ */
