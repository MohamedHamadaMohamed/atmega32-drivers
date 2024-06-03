/*
 * PWM.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Mohamed Hamada
 */

#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/00.DIO/DIO.h"

#include "../../01.MCAL/02.GPT/GPT.h"

#include "PWM.h"

extern Dio_ConfigType  PWM_0_Config;
extern Dio_ConfigType  PWM_1_Config;
extern Dio_ConfigType  PWM_2_Config;

void PWM_init(const PWM_ConfigType* ConfigPtr)
{

	Gpt_ConfigType PWM_timer_Config ={ConfigPtr->Type,ConfigPtr->ModeType,ConfigPtr->prescaler,ConfigPtr->DutyCycle,ConfigPtr->ModeType,NULL};
    Gpt_Init(&PWM_timer_Config);

	switch(ConfigPtr->Type)
	{
	case TIMER0:
		 Dio_Init(&PWM_0_Config);
		 SET_BIT(TCCR0,COM01);
		 switch(ConfigPtr->generatedForms)
		 {
		 case  Inverted:     SET_BIT(TCCR0,COM00);   break;
		 case Non_Inverted:	 CLEAR_BIT(TCCR0,COM00); break;
		 default :          /*  error */             break;
		 }
		 break;
	case TIMER1:
		 Dio_Init(&PWM_1_Config);
		 SET_BIT(TCCR1A,COM1A1);
		 switch(ConfigPtr->generatedForms)
		 {
		 case  Inverted:     SET_BIT(TCCR1A,COM1A0);   break;
		 case Non_Inverted:	 CLEAR_BIT(TCCR1A,COM1A0); break;
		 default :          /*  error */             break;
		 }
		break;
	case TIMER2:
		 Dio_Init(&PWM_2_Config);
		 SET_BIT(TCCR2,COM21);
		 switch(ConfigPtr->generatedForms)
		 {
		 case  Inverted:     SET_BIT(TCCR2,COM20);   break;
		 case Non_Inverted:	 CLEAR_BIT(TCCR2,COM20); break;
		 default :          /*  error */             break;
		 }
	    break;

	}
}
void PWM_setDutyCycle (Gpt_ChannelType ChannelType ,uint8 DutyCycle)
{
	switch(ChannelType)
	{
	case TIMER0:	OCR0 = DutyCycle;  break;
	case TIMER1:	OCR1A = DutyCycle; break;
	case TIMER2:	OCR2 = DutyCycle;  break;


	}

}


