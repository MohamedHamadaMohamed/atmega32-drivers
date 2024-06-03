/*
 * IR_Sensor.c
 *
 *  Created on: Nov 14, 2021
 *      Author: Mohamed Hamada
 */




#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/00.DIO/DIO.h"

#include "IR_Sensor_Types.h"

#include "IR_Sensor_config.h"

#include "IR_Sensor.h"


extern Dio_ConfigType  IR_Out_Pin_config;

void IR_Sensor_init(void)
{
	Dio_Init(&IR_Out_Pin_config);
}
IR_Type IR_Sensor_ReadSignal(void)
{

	IR_Type flag = IR_BLACK;

	flag = Dio_ReadChannel( IR_OUT_PORT,IR_OUT_PIN );



	return flag;

}

