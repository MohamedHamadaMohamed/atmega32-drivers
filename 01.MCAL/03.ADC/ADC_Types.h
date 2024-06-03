/*
 * ADC_Types.h
 *
 *  Created on: Sep 1, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_03_ADC_ADC_TYPES_H_
#define ATMEGA16_01_MCAL_03_ADC_ADC_TYPES_H_

#include "../../00.LIB/Std_types.h"




typedef enum {
	ADC_CHANNEL0 =0,
	ADC_CHANNEL1 =1,
	ADC_CHANNEL2 =2,
	ADC_CHANNEL3 =3,
	ADC_CHANNEL4 =4,
	ADC_CHANNEL5 =5,
	ADC_CHANNEL6 =6,
	ADC_CHANNEL7 =7
}ADC_channelType;

typedef enum { Internal_Vref_turned_off,
	           AVCC_with_external_capacitor,
	           Internal_2_56V_Voltage

}ADC_Reference;

typedef enum
{
	DIVISION_BY_2 = 0b000,
	DIVISION_BY_4 = 0b010,
	DIVISION_BY_8 = 0b011,
	DIVISION_BY_16= 0b100,
	DIVISION_BY_32= 0b101,
	DIVISION_BY_64= 0b110,
	DIVISION_BY_128=0b111

}ADC_Prescaler_Selections;


typedef struct
{
	ADC_channelType initialChannelType ;
	ADC_Prescaler_Selections Prescaler_Selections;
	ADC_Reference Reference;


}ADC_ConfigType;

#endif /* ATMEGA16_01_MCAL_03_ADC_ADC_TYPES_H_ */
