/*
 * SPI_PBcfg.c
 *
 *  Created on: Oct 6, 2021
 *      Author: Mohamed Hamada
 */


#include "SPI_Types.h"

SPI_ConfigType SPI_Master_Config ={SPI_POOLING,SPI_Master,SPI_LSB,SPI_Leading_Edge_Rising,SPI_Leading_Edge_Sample,SPI_fosc_div_2};
SPI_ConfigType SPI_Slave_Config ={SPI_POOLING,SPI_Salve,SPI_LSB,SPI_Leading_Edge_Rising,SPI_Leading_Edge_Sample,SPI_fosc_div_2};


SPI_ConfigType SPI_EEPROM_Config ={SPI_POOLING,SPI_Master,SPI_MSB,SPI_Leading_Edge_Rising,SPI_Leading_Edge_Sample,SPI_fosc_div_4};
