/*
 * SPI_Types.h
 *
 *  Created on: Oct 5, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_07_SPI_SPI_TYPES_H_
#define ATMEGA16_01_MCAL_07_SPI_SPI_TYPES_H_

#include "../../00.LIB/Std_types.h"


typedef enum {SPI_INTERRUPT,SPI_POOLING}SPI_TypeMode;

typedef enum {SPI_Master,SPI_Salve}SPI_Mode;

typedef enum {SPI_LSB=1,SPI_MSB=0}SPI_data_transmitted_first;

typedef enum {SPI_Leading_Edge_Rising=0,SPI_Leading_Edge_Falling=1}SPI_Clock_Polarity;

typedef enum {SPI_Leading_Edge_Sample,SPI_Leading_Edge_Setup}SPI_Clock_Phase;

typedef enum{ SPI_fosc_div_4,SPI_fosc_div_16,SPI_fosc_div_64,SPI_fosc_div_128,SPI_fosc_div_2,SPI_fosc_div_8,SPI_fosc_div_32}SPI_SCK_Frequency;


typedef struct
{
	SPI_TypeMode SPI_TypeMode;
	SPI_Mode Mode;
	SPI_data_transmitted_first data_transmitted_first;
	SPI_Clock_Polarity Clock_Polarity;
	SPI_Clock_Phase Clock_Phase;
	SPI_SCK_Frequency SCK_Frequency;

}SPI_ConfigType;

#endif /* ATMEGA16_01_MCAL_07_SPI_SPI_TYPES_H_ */
