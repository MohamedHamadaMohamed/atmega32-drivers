/*
 * Ultrasonic.c
 *
 *  Created on: Nov 8, 2021
 *      Author: Mohamed Hamada
 */



#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/00.DIO/DIO.h"
#include "../../01.MCAL/08.ICU/ICU.h"


#include "Ultrasonic_config.h"
#include "Ultrasonic.h"




extern Dio_ConfigType  ICU_echo_Pin_config  ;
extern Dio_ConfigType  ICU_trig_Pin_config  ;

extern void Ultrasonic_edgeProcessing(void);


uint8 g_edgeCount = 0;
uint16 g_duration = 0;
uint32 g_distance = 0;


void Ultrasonic_init(void)
{

	Dio_Init(&ICU_echo_Pin_config);
	Dio_Init(&ICU_trig_Pin_config);

	Icu_ConfigType Icu_Config = {1,1,Ultrasonic_edgeProcessing};
	ICU_Init(&Icu_Config);

	Ultrasonic_CalcDistance();


}
uint16 Ultrasonic_CalcDistance(void)
{

	Dio_WriteChannel( ULTRASONIC_TRIG_PORT,ULTRASONIC_TRIG_PIN , LOW );
	_delay_us(2);
	Dio_WriteChannel( ULTRASONIC_TRIG_PORT,ULTRASONIC_TRIG_PIN , HIGH );
	_delay_us(15);
	Dio_WriteChannel( ULTRASONIC_TRIG_PORT,ULTRASONIC_TRIG_PIN , LOW );

	return g_distance;


}


void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(0);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_duration = ICU_getInputCaptureValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(1);

		g_edgeCount = 0;
		g_distance = ((float)g_duration/2)/(28.7) ;

	}

}
