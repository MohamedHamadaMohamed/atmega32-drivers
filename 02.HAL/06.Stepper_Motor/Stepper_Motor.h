/*
 * Stepper_Motor.h
 *
 *  Created on: Sep 22, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_02_HAL_06_STEPPER_MOTOR_STEPPER_MOTOR_H_
#define ATMEGA16_02_HAL_06_STEPPER_MOTOR_STEPPER_MOTOR_H_

void Stepper_Motor_init(void);
void Stepper_Motor_MoveOneStep();

void Stepper_Motor_Stop(void);
#endif /* ATMEGA16_02_HAL_06_STEPPER_MOTOR_STEPPER_MOTOR_H_ */
