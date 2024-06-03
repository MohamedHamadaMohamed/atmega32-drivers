/*
 * SPI.h
 *
 *  Created on: Oct 5, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_07_SPI_SPI_H_
#define ATMEGA16_01_MCAL_07_SPI_SPI_H_

#include "SPI_Types.h"


void SPI_Init( const SPI_ConfigType* ConfigPtr );
void SPI_DeInit( void );

void SPI_SendByte(const uint8 Byte);
void SPI_SendString(const uint8 *Data);
uint8 SPI_RecieveByte();
void SPI_RecieveString(uint8 *Data );


#endif /* ATMEGA16_01_MCAL_07_SPI_SPI_H_ */
