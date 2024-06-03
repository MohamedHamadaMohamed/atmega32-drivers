/*
 * PWM_PBcfg.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Mohamed Hamada
 */


#include "PWM_Types.h"


/*
 * Gpt_ChannelType Type;
	Gpt_ModeType ModeType;
	Gpt_prescaler prescaler;
    uint16 DutyCycle;
    PWM_generatedForms  generatedForms;
 *
 * */

PWM_ConfigType PWM_Config1 ={TIMER0,Gpt_Fast_PWM,Gpt_clk_divided_1024,100,Non_Inverted};
PWM_ConfigType PWM_Config2 ={TIMER1,Gpt_Timer1_Fast_PWM_OCR1A,Gpt_clk_divided_8,125,Inverted};
PWM_ConfigType PWM_Config3 ={TIMER2,Gpt_Fast_PWM,Gpt_clk_divided_8,125,Inverted};
