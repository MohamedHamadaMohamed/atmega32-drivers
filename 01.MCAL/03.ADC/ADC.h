/*
 * ADC.h
 *
 *  Created on: Sep 1, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_03_ADC_ADC_H_
#define ATMEGA16_01_MCAL_03_ADC_ADC_H_

#include "ADC_Types.h"



void ADC_init(ADC_ConfigType *config);
void ADC_readChannel(ADC_channelType channel);


#endif /* ATMEGA16_01_MCAL_03_ADC_ADC_H_ */
