/*
 * tempSensor.c
 *
 *  Created on: Sep 1, 2021
 *      Author: Mohamed Hamada
 */


#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/03.ADC/ADC.h"
#include "../04.tempSensor/tempSensor.h"


extern volatile uint16 g_adcresult;
extern ADC_ConfigType tempSensor;

void tempSensor_init()
{
	ADC_init(&tempSensor);
}
uint16 tempSensor_readTempValue()
{
	uint16 temp =0;
	float32 cal =0;

	ADC_readChannel(ADC_CHANNEL2);

	cal = (5*150)/(1.5*1023);
	temp = (g_adcresult*cal);//*5)/(1023*1.5);


	return temp;
}
