/*
 * DC_Motor.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Mohamed Hamada
 */

#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"



#include "../../01.MCAL/00.DIO/DIO.h"

#include "DC_Motor_config.h"
#include "DC_Motor.h"

extern Dio_ConfigType  DC_Motor_Input_1 ;
extern Dio_ConfigType  DC_Motor_Input_2 ;
extern Dio_ConfigType  DC_Motor_Enable  ;

void DC_Motor_init(void)
{

	Dio_Init(&DC_Motor_Input_1);
	Dio_Init(&DC_Motor_Input_2);
	Dio_Init(&DC_Motor_Enable);

	Dio_WriteChannel(DC_MOTOR_ENABLE_PORT,DC_MOTOR_ENABLE_PIN,LOW);


}
void DC_Motor_RotateClockwiseMode(void)
{
	Dio_WriteChannel(DC_MOTOR_ENABLE_PORT,DC_MOTOR_ENABLE_PIN,HIGH);
	Dio_WriteChannel(DC_MOTOR_INPUT_1_PORT,DC_MOTOR_INPUT_1_PIN,HIGH);
	Dio_WriteChannel(DC_MOTOR_INPUT_2_PORT,DC_MOTOR_INPUT_2_PIN,LOW);

}
void DC_Motor_RotateAntiClockwise(void)
{

	Dio_WriteChannel(DC_MOTOR_ENABLE_PORT,DC_MOTOR_ENABLE_PIN,HIGH);
	Dio_WriteChannel(DC_MOTOR_INPUT_1_PORT,DC_MOTOR_INPUT_1_PIN,LOW);
	Dio_WriteChannel(DC_MOTOR_INPUT_2_PORT,DC_MOTOR_INPUT_2_PIN,HIGH);

}
void DC_Motor_Stop(void)
{
	Dio_WriteChannel(DC_MOTOR_INPUT_1_PORT,DC_MOTOR_INPUT_1_PIN,LOW);
	Dio_WriteChannel(DC_MOTOR_INPUT_2_PORT,DC_MOTOR_INPUT_2_PIN,LOW);

}
