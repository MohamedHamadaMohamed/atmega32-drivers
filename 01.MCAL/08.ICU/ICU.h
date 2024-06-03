/*
 * ICU.h
 *
 *  Created on: Oct 8, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_08_ICU_ICU_H_
#define ATMEGA16_01_MCAL_08_ICU_ICU_H_

#include "ICU_Types.h"


void ICU_Init( const Icu_ConfigType* ConfigPtr );
void ICU_DeInit(void);

void ICU_setEdgeDetectionType(ICU_ActivationType edge);
uint8 ICU_getInputCaptureValue();

void ICU_clearTimerValue(void);

#endif /* ATMEGA16_01_MCAL_08_ICU_ICU_H_ */
