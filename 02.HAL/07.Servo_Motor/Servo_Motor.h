/*
 * Servo_Motor.h
 *
 *  Created on: Sep 22, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_02_HAL_07_SERVO_MOTOR_SERVO_MOTOR_H_
#define ATMEGA16_02_HAL_07_SERVO_MOTOR_SERVO_MOTOR_H_

void Servo_Motor_init();
void Servo_Motor_MoveAngle(uint8 angle);
void Servo_Motor_Stop();

#endif /* ATMEGA16_02_HAL_07_SERVO_MOTOR_SERVO_MOTOR_H_ */
