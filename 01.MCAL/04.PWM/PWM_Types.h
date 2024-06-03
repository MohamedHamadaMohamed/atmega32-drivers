/*
 * PWM_Types.h
 *
 *  Created on: Sep 22, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_04_PWM_PWM_TYPES_H_
#define ATMEGA16_01_MCAL_04_PWM_PWM_TYPES_H_

#include "../../00.LIB/Std_types.h"

#include "../../01.MCAL/02.GPT/GPT_Types.h"


typedef enum {Inverted,Non_Inverted}PWM_generatedForms;

typedef struct
{
	Gpt_ChannelType Type;
	Gpt_ModeType ModeType;
	Gpt_prescaler prescaler;
    uint16 DutyCycle;
    PWM_generatedForms  generatedForms;
}PWM_ConfigType;

#endif /* ATMEGA16_01_MCAL_04_PWM_PWM_TYPES_H_ */
