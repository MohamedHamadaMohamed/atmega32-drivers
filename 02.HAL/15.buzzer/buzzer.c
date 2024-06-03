/*
 * buzzer.c
 *
 *  Created on: Nov 18, 2021
 *      Author: Mohamed Hamada
 */


#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"


#include "../../01.MCAL/00.DIO/DIO.h"

#include"buzzer_config.h"
#include "buzzer.h"

extern Dio_ConfigType buzzer_Config;


void buzzer_init(void)
{

	Dio_Init( &buzzer_Config );
}
void buzzer_Enable(void)
{
	Dio_WriteChannel( BUZZER_PORT,BUZZER_PIN, HIGH );
}

void buzzer_Disable(void)
{
	Dio_WriteChannel( BUZZER_PORT,BUZZER_PIN, LOW );
}
