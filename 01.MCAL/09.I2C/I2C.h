/*
 * I2C.h
 *
 *  Created on: Oct 14, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_09_I2C_I2C_H_
#define ATMEGA16_01_MCAL_09_I2C_I2C_H_

#include "I2C_Types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* I2C Status Bits in the TWSR Register */
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave




void I2C_init();

void I2C_Start(void);
void I2C_SetAddress(I2C_address a_address);
void I2C_Stop(void);

void I2C_write(uint8 a_data);


uint8 I2C_readWithAck(void);
uint8 I2C_readWithNack(void);

uint8 I2C_getStatus(void);





#endif /* ATMEGA16_01_MCAL_09_I2C_I2C_H_ */
