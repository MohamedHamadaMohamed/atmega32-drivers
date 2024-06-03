/*
 * IR_Sensor.h
 *
 *  Created on: Nov 14, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_02_HAL_13_IR_SENSOR_IR_SENSOR_H_
#define ATMEGA16_02_HAL_13_IR_SENSOR_IR_SENSOR_H_

#include "IR_Sensor_Types.h"


void IR_Sensor_init(void);
IR_Type IR_Sensor_ReadSignal(void);


#endif /* ATMEGA16_02_HAL_13_IR_SENSOR_IR_SENSOR_H_ */
