/*
 * GPT.c
 *
 *  Created on: Sep 20, 2021
 *      Author: Mohamed Hamada
 */

#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "GPT.h"

static void(*Gpt_callBackptr[3])(void) ={NULL,NULL,NULL};

void Gpt_Init( const Gpt_ConfigType* ConfigPtr )
{

	switch(ConfigPtr->ChannelType)
	{
	case TIMER0 :
		TCCR0 =0;
		Gpt_callBackptr[0]= ConfigPtr->callBackFun;
		switch(ConfigPtr->ModeType )
		{
		case Gpt_Normal_mode:
			SET_BIT(TIMSK,TOIE0);     /* Timer/Counter0 Overflow Interrupt Enable */

			SET_BIT(TCCR0,FOC0);

			CLEAR_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);


			break;
		case Gpt_PWM_Phase_Correct:
			SET_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);
			break;
		case Gpt_compare_mode :
			CLEAR_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);

			SET_BIT(TCCR0,FOC0);


			OCR0 = ConfigPtr->compareValue;
			SET_BIT(TIMSK,OCIE0);     /* Timer/Counter0 Output Compare Match Interrupt Enable  */
			break;
		case Gpt_Fast_PWM :
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			break;
		}
		TCCR0 &=0b11111000;
		TCCR0 |=ConfigPtr->prescaler;
		break;
	case TIMER1 :
		TCCR1A = 0;
		TCCR1B =0;
		Gpt_callBackptr[1]= ConfigPtr->callBackFun;
		TCNT1 =0;

		switch(ConfigPtr->Timer1_ModeType)
		{
		case Gpt_Timer1_Normal:

			SET_BIT(TIMSK,TOIE1);      /* Timer/Counter1 Overflow Interrupt Enable */

			SET_BIT(TCCR1A,FOC1A);
			SET_BIT(TCCR1A,FOC1B);

			CLEAR_BIT(TCCR1A,WGM10);
			CLEAR_BIT(TCCR1A,WGM11);
			CLEAR_BIT(TCCR1B,WGM12);
			CLEAR_BIT(TCCR1B,WGM13);



			break;

		case Gpt_Timer1_PWM_Phase_Correct_8_bit:
			SET_BIT(TCCR1A,WGM10);
			CLEAR_BIT(TCCR1A,WGM11);
			CLEAR_BIT(TCCR1B,WGM12);
			CLEAR_BIT(TCCR1B,WGM13);
			break;
		case Gpt_Timer1_PWM_Phase_Correct_9_bit:
			CLEAR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLEAR_BIT(TCCR1B,WGM12);
			CLEAR_BIT(TCCR1B,WGM13);
			break;
		case Gpt_Timer1_PWM_Phase_Correct_10_bit:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLEAR_BIT(TCCR1B,WGM12);
			CLEAR_BIT(TCCR1B,WGM13);
			break;
		case Gpt_Timer1_compare_mode_Top_OCR1A:
			CLEAR_BIT(TCCR1A,WGM10);
			CLEAR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLEAR_BIT(TCCR1B,WGM13);

			SET_BIT(TCCR1A,FOC1A);
			SET_BIT(TCCR1A,FOC1B);

			OCR1A = ConfigPtr->compareValue;

			SET_BIT(TIMSK,OCIE1A);
			break;
		case Gpt_Timer1_Fast_PWM_8_bit:
			SET_BIT(TCCR1A,WGM10);
			CLEAR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLEAR_BIT(TCCR1B,WGM13);
			break;
		case Gpt_Timer1_Fast_PWM_9_bit:
			CLEAR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLEAR_BIT(TCCR1B,WGM13);
			break;
		case Gpt_Timer1_Fast_PWM_10_bit:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLEAR_BIT(TCCR1B,WGM13);
			break;
		case Gpt_Timer1_PWM_Phase_and_Frequency_Correct_Top_ICR1:
			CLEAR_BIT(TCCR1A,WGM10);
			CLEAR_BIT(TCCR1A,WGM11);
			CLEAR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case Gpt_Timer1_PWM_Phase_and_Frequency_Correct_Top_OCR1A:
			SET_BIT(TCCR1A,WGM10);
			CLEAR_BIT(TCCR1A,WGM11);
			CLEAR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case Gpt_Timer1_PWM_Phase_Correct_Top_ICR1:
			CLEAR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLEAR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case Gpt_Timer1_PWM_Phase_Correct_Top_OCR1A:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLEAR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case Gpt_Timer1_compare_mode_Top_ICR1:
			CLEAR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLEAR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);

			SET_BIT(TCCR1A,FOC1A);
			SET_BIT(TCCR1A,FOC1B);

			OCR1A = ConfigPtr->compareValue;


			SET_BIT(TIMSK,OCIE1A);
			break;
		case Gpt_Timer1_Fast_PWM_ICR1:
			CLEAR_BIT(TCCR1A,WGM10);
			CLEAR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case Gpt_Timer1_Fast_PWM_OCR1A:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;

		}

		 TCCR1B &=0b11111000;
		 TCCR1B |=ConfigPtr->prescaler;  break;


		break;

		case TIMER2 :
			TCCR2 =0;
			Gpt_callBackptr[2]= ConfigPtr->callBackFun;
			switch(ConfigPtr->ModeType )
			{
			case Gpt_Normal_mode:
				SET_BIT(TIMSK,TOIE2);     /* Timer/Counter0 Overflow Interrupt Enable */

				SET_BIT(TCCR2,FOC2);

				CLEAR_BIT(TCCR2,WGM20);
				CLEAR_BIT(TCCR2,WGM21);
				break;
		case Gpt_PWM_Phase_Correct:
			SET_BIT(TCCR2,WGM20);
			CLEAR_BIT(TCCR2,WGM21);
			break;
		case Gpt_compare_mode :
			SET_BIT(TIMSK,OCIE2);     /* Timer/Counter2 Output Compare Match Interrupt Enable  */

			SET_BIT(TCCR2,FOC2);

			CLEAR_BIT(TCCR2,WGM20);
			SET_BIT(TCCR2,WGM21);



			OCR2 = ConfigPtr->compareValue;
			break;
		case Gpt_Fast_PWM :
			SET_BIT(TCCR2,WGM20);
			SET_BIT(TCCR2,WGM21);
			break;
		}
		TCCR2 &=0b11111000;
		TCCR2 |=ConfigPtr->prescaler;
		break;


	}

}
void Gpt_DeInit( void )/* Deinitializes all hardware timer channels*/
{


}
Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel ) /*Returns the time already elapsed.*/
{
	Gpt_ValueType data =0;
	switch(Channel)
	{
	case TIMER0:  data = TCNT0 ;break;
	case TIMER1:  data = TCNT1 ;break;
	case TIMER2:  data = TCNT2 ;break;

	}
	return data;
}
Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel ) /*  Returns the time remaining until the target time is reached.*/
{
	Gpt_ValueType data =0;
	switch(Channel)
	{
	case TIMER0:  data = 0XFF-TCNT0   ;break;
	case TIMER1:  data = 0XFFFF-TCNT1 ;break;
	case TIMER2:  data = 0XFF-TCNT2   ;break;

	}
	return data;
}


void Gpt_StopTimer( Gpt_ChannelType Channel ) /* Stops a timer channel.*/
{
	CLEAR_BIT(TIMSK,TOIE0);     /* Timer/Counter0 Overflow Interrupt disable */
	CLEAR_BIT(TIMSK,OCIE0);     /* Timer/Counter0 Output Compare Match Interrupt disable  */

	CLEAR_BIT(TIMSK,TOIE1);      /* Timer/Counter1 Overflow Interrupt Enable */
	SET_BIT(TIMSK,OCIE1A);       /* Timer/Counter1 Output Compare Match Interrupt Enable  */


	CLEAR_BIT(TIMSK,TOIE2);     /* Timer/Counter2 Overflow Interrupt Enable */
	CLEAR_BIT(TIMSK,OCIE2);     /* Timer/Counter2 Output Compare Match Interrupt Enable  */

}


 ISR(TIMER0_OVF_vect)
{

	if(Gpt_callBackptr[0] != NULL)
		Gpt_callBackptr[0]();

}

ISR(TIMER0_COMP_vect)
{

	if(Gpt_callBackptr[0] != NULL)
		Gpt_callBackptr[0]();
}
ISR(TIMER1_OVF_vect)
{
	if(Gpt_callBackptr[1] != NULL)
		Gpt_callBackptr[1]();
}
ISR(TIMER1_COMPA_vect)
{
	if(Gpt_callBackptr[1] != NULL)
		Gpt_callBackptr[1]();
}
ISR(TIMER2_OVF_vect)
{
	if(Gpt_callBackptr[2] != NULL)
		Gpt_callBackptr[2]();
}
ISR(TIMER2_COMP_vect)
{
	if(Gpt_callBackptr[2] != NULL)
		Gpt_callBackptr[2]();
}
