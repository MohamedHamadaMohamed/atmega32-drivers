/*
 * PWM.h
 *
 *  Created on: Sep 22, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_04_PWM_PWM_H_
#define ATMEGA16_01_MCAL_04_PWM_PWM_H_

#include "PWM_Types.h"


void PWM_init(const PWM_ConfigType* ConfigPtr);
void PWM_setDutyCycle (Gpt_ChannelType ChannelType ,uint8 DutyCycle);

#endif /* ATMEGA16_01_MCAL_04_PWM_PWM_H_ */
