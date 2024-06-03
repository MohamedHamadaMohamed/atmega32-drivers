/*
 * RainSensor.c
 *
 *  Created on: Nov 15, 2021
 *      Author: Mohamed Hamada
 */




#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/00.DIO/DIO.h"

#include "RainSensor_config.h"
#include "RainSensor.h"

extern Dio_ConfigType  RainSensor_Out_Pin_config;

void RainSensor_init(void)
{
	Dio_Init( &RainSensor_Out_Pin_config );
}
bool RainSensor_CheckRain(void)
{
	bool flag = LOW;
	flag =Dio_ReadChannel( RainSensor_OUT_PORT,RainSensor_OUT_PIN );

	return flag;


}
