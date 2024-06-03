/*
 * Led.c
 *
 *  Created on: Aug 21, 2021
 *      Author: Mohamed Hamada
 */



#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/00.DIO/DIO_Types.h"
#include "../../01.MCAL/00.DIO/DIO.h"

#include "../00.LED/Led_config.h"
#include "../00.LED/Led.h"

extern Dio_ConfigType LED_Config ;

void LED_init()
{
	Dio_Init(&LED_Config );
}
void LED_ON()
{
#if NEGATIVE_LOGIC==1

	Dio_WriteChannel( LED_PORT,LED_PIN, LOW );

#else

	Dio_WriteChannel( LED_PORT,LED_PIN, HIGH );

#endif

}
void LED_OFF()
{
#if NEGATIVE_LOGIC==1

	Dio_WriteChannel( LED_PORT,LED_PIN, HIGH );

#else

	Dio_WriteChannel( LED_PORT,LED_PIN, LOW );

#endif


}
