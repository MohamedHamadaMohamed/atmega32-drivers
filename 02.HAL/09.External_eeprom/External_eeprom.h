/*
 * 09.External_eeprom.h
 *
 *  Created on: Oct 18, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_02_HAL_09_EXTERNAL_EEPROM_EXTERNAL_EEPROM_H_
#define ATMEGA16_02_HAL_09_EXTERNAL_EEPROM_EXTERNAL_EEPROM_H_


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

void external_eeprom_init(void);
uint8 external_eeprom_writeByte(uint16 a_address,uint16 a_data);
uint8 external_eeprom_readByte(uint16 a_address);

#endif /* ATMEGA16_02_HAL_09_EXTERNAL_EEPROM_EXTERNAL_EEPROM_H_ */
