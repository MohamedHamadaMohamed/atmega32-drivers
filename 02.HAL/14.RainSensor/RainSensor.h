/*
 * RainSensor.h
 *
 *  Created on: Nov 15, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_02_HAL_14_RAINSENSOR_RAINSENSOR_H_
#define ATMEGA16_02_HAL_14_RAINSENSOR_RAINSENSOR_H_

#include "../../00.LIB/Std_types.h"


void RainSensor_init(void);
bool RainSensor_CheckRain(void);

#endif /* ATMEGA16_02_HAL_14_RAINSENSOR_RAINSENSOR_H_ */
