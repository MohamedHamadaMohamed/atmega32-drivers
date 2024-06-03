/*
 * GPT_Types.h
 *
 *  Created on: Sep 20, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_02_GPT_GPT_TYPES_H_
#define ATMEGA16_01_MCAL_02_GPT_GPT_TYPES_H_

#include "../../00.LIB/Std_types.h"


typedef enum {TIMER0,TIMER1,TIMER2}Gpt_ChannelType;
typedef enum {Gpt_Normal_mode,Gpt_PWM_Phase_Correct,Gpt_compare_mode,Gpt_Fast_PWM}Gpt_ModeType;

typedef enum {Gpt_Timer1_Normal=0,Gpt_Timer1_PWM_Phase_Correct_8_bit=1,Gpt_Timer1_PWM_Phase_Correct_9_bit=2,Gpt_Timer1_PWM_Phase_Correct_10_bit=3,
	          Gpt_Timer1_compare_mode_Top_OCR1A=4,Gpt_Timer1_Fast_PWM_8_bit=5,Gpt_Timer1_Fast_PWM_9_bit=6,Gpt_Timer1_Fast_PWM_10_bit=7,
			  Gpt_Timer1_PWM_Phase_and_Frequency_Correct_Top_ICR1=8,Gpt_Timer1_PWM_Phase_and_Frequency_Correct_Top_OCR1A=9,
			  Gpt_Timer1_PWM_Phase_Correct_Top_ICR1=10,Gpt_Timer1_PWM_Phase_Correct_Top_OCR1A=11, Gpt_Timer1_compare_mode_Top_ICR1=12,
			  Gpt_Timer1_Fast_PWM_ICR1=14, Gpt_Timer1_Fast_PWM_OCR1A=15
              }Gpt_Timer1_ModeType;

typedef enum {Gpt_No_clock_source=0,Gpt_clk_No_prescaling=1,Gpt_clk_divided_8=2,Gpt_clk_divided_64=3,Gpt_clk_divided_256=4,
	          Gpt_clk_divided_1024=5,
			  Gpt_External_clock_source_on_T_pin_Clock_on_falling_edge=6,Gpt_External_clock_source_on_T_pin_Clock_on_rising_edge=7
             }Gpt_prescaler;


typedef uint16        Gpt_ValueType;
typedef struct{
	Gpt_ChannelType ChannelType ;
	Gpt_ModeType ModeType;
	Gpt_prescaler prescaler;
	Gpt_ValueType compareValue;
	Gpt_Timer1_ModeType Timer1_ModeType ;
	void (*callBackFun)(void);
}Gpt_ConfigType;
#endif /* ATMEGA16_01_MCAL_02_GPT_GPT_TYPES_H_ */
