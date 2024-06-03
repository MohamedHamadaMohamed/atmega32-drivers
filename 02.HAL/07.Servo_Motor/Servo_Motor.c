/*
 * Servo_Motor.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Mohamed Hamada
 */


#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/00.DIO/DIO.h"

#include "../../01.MCAL/04.PWM/PWM.h"


#include "Servo_Motor_config.h"
#include "Servo_Motor.h"


extern Dio_ConfigType  Servo_Motor_control_config;
extern PWM_ConfigType PWM_Config1;
void Servo_Motor_init()
{

	 PWM_init(&PWM_Config1);



}
void Servo_Motor_MoveAngle(uint8 angle)
{
	PWM_setDutyCycle (TIMER0 ,150);

}
void Servo_Motor_Stop()
{

 	Dio_WriteChannel(SERVO_MOTOR_CONTROL_PORT,SERVO_MOTOR_CONTROL_PIN,LOW);


}
