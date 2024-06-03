/*
 * Stepper_Motor.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Mohamed Hamada
 */


#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"



#include "../../01.MCAL/00.DIO/DIO.h"

#include "Stepper_Motor_config.h"
#include "Stepper_Motor.h"


extern Dio_ConfigType  Stepper_Motor_Input_A1 ;
extern Dio_ConfigType  Stepper_Motor_Input_A2 ;
extern Dio_ConfigType  Stepper_Motor_Input_B1 ;
extern Dio_ConfigType  Stepper_Motor_Input_B2 ;

volatile static uint8 iteration =0;
volatile static uint8 step[8]={0b1100,0b0100,0b0110,0b0010,0b0011,0b0001,0b1001,0b1000};
void Stepper_Motor_init(void)
{
	Dio_Init(&Stepper_Motor_Input_A1);
	Dio_Init(&Stepper_Motor_Input_A2);
	Dio_Init(&Stepper_Motor_Input_B1);
	Dio_Init(&Stepper_Motor_Input_B2);

}
void Stepper_Motor_MoveOneStep()
{
  #if HALF_STEP_SEQUENCE==0

	Dio_WriteChannel(DC_MOTOR_INPUT_A1_PORT,DC_MOTOR_INPUT_A1_PIN,GET_BIT(step[iteration],3));
	Dio_WriteChannel(DC_MOTOR_INPUT_A2_PORT,DC_MOTOR_INPUT_A2_PIN,GET_BIT(step[iteration],2));
	Dio_WriteChannel(DC_MOTOR_INPUT_B1_PORT,DC_MOTOR_INPUT_B1_PIN,GET_BIT(step[iteration],1));
	Dio_WriteChannel(DC_MOTOR_INPUT_B2_PORT,DC_MOTOR_INPUT_B2_PIN,GET_BIT(step[iteration],0));

	iteration+=2;
	if(iteration ==8)
	{
		iteration=0;
	}
#else
	Dio_WriteChannel(DC_MOTOR_INPUT_A1_PORT,DC_MOTOR_INPUT_A1_PIN,GET_BIT(step[iteration],3));
	Dio_WriteChannel(DC_MOTOR_INPUT_A2_PORT,DC_MOTOR_INPUT_A2_PIN,GET_BIT(step[iteration],2));
	Dio_WriteChannel(DC_MOTOR_INPUT_B1_PORT,DC_MOTOR_INPUT_B1_PIN,GET_BIT(step[iteration],1));
	Dio_WriteChannel(DC_MOTOR_INPUT_B2_PORT,DC_MOTOR_INPUT_B2_PIN,GET_BIT(step[iteration],0));

	iteration++;
	if(iteration ==8)
	{
		iteration=0;
	}
#endif

}
void Stepper_Motor_Stop(void)
{


	Dio_WriteChannel(DC_MOTOR_INPUT_A1_PORT,DC_MOTOR_INPUT_A1_PIN,LOW);
	Dio_WriteChannel(DC_MOTOR_INPUT_A2_PORT,DC_MOTOR_INPUT_A2_PIN,LOW);
	Dio_WriteChannel(DC_MOTOR_INPUT_B1_PORT,DC_MOTOR_INPUT_B1_PIN,LOW);
	Dio_WriteChannel(DC_MOTOR_INPUT_B2_PORT,DC_MOTOR_INPUT_B2_PIN,LOW);

}
