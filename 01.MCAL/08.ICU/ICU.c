/*
 * ICU.c
 *
 *  Created on: Oct 8, 2021
 *      Author: Mohamed Hamada
 */


#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"


#include "ICU.h"



#ifndef NULL
#define NULL            ((void*)0)
#endif


void (*g_ICU_CAllBackPtr)(void) =NULL;
void ICU_Init( const Icu_ConfigType* ConfigPtr )
{

	SET_BIT(TCCR1A,FOC1A);
	SET_BIT(TCCR1A,FOC1B);



	/*set clock prescalar*/
	TCCR1B &= 0XF8;
	TCCR1B |=ConfigPtr->Clk_prescaler;

	TCCR1B &= 0XBF;
	TCCR1B |=(ConfigPtr->ActivationType<<6);

	ICR1 =0;
	TCNT1 =0;

	g_ICU_CAllBackPtr = ConfigPtr->CAllBackPtr;

	/*enable input capture unit*/
	SET_BIT(TIMSK,TICIE1);

}
void ICU_DeInit(void)
{
	TCCR1A =0;
	TCCR1B =0;
	ICR1 =0;
	TCNT1 =0;
	CLEAR_BIT(TIMSK,TICIE1);

}

void ICU_setEdgeDetectionType(ICU_ActivationType edge)
{

	TCCR1B &= 0XBF;
	TCCR1B |=(edge<<6);



}
uint8 ICU_getInputCaptureValue()
{
    return ICR1;

}

void ICU_clearTimerValue(void)
{

	TCNT1 =0;

}

ISR(TIMER1_CAPT_vect)
{

	if( g_ICU_CAllBackPtr !=  NULL)
	{

		g_ICU_CAllBackPtr();
	}

}
