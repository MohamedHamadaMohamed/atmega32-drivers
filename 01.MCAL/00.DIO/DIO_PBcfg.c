/*
 * DIO_PBcfg.c
 *
 *  Created on: Aug 21, 2021
 *      Author: Mohamed Hamada
 */

#include "../00.DIO/DIO_Types.h"

Dio_ConfigType  LED_Config ={PORT_C,PIN_0,OUTPUT,OFF,LOW};
Dio_ConfigType switch_Config ={PORT_D,PIN_1,INPUT,OFF,LOW};

Dio_ConfigType  PWM_0_Config ={PORT_B,PIN_3,OUTPUT,OFF,LOW};
Dio_ConfigType  PWM_1_Config ={PORT_D,PIN_5,OUTPUT,OFF,LOW};
Dio_ConfigType  PWM_2_Config ={PORT_D,PIN_7,OUTPUT,OFF,LOW};

Dio_ConfigType  DC_Motor_Input_1 ={PORT_A,PIN_0,OUTPUT,OFF,LOW};
Dio_ConfigType  DC_Motor_Input_2 ={PORT_A,PIN_1,OUTPUT,OFF,LOW};
Dio_ConfigType  DC_Motor_Enable  ={PORT_A,PIN_2,OUTPUT,OFF,LOW};

Dio_ConfigType  Stepper_Motor_Input_A1 ={PORT_A,PIN_0,OUTPUT,OFF,LOW};
Dio_ConfigType  Stepper_Motor_Input_A2 ={PORT_A,PIN_1,OUTPUT,OFF,LOW};
Dio_ConfigType  Stepper_Motor_Input_B1  ={PORT_A,PIN_2,OUTPUT,OFF,LOW};
Dio_ConfigType  Stepper_Motor_Input_B2  ={PORT_A,PIN_3,OUTPUT,OFF,LOW};

Dio_ConfigType  SPI_Master_SS_config    ={PORT_B,PIN_4,OUTPUT,OFF,LOW};
Dio_ConfigType  SPI_Master_MOSI_config  ={PORT_B,PIN_5,OUTPUT,OFF,LOW};
Dio_ConfigType  SPI_Master_MISO_config  ={PORT_B,PIN_6,INPUT,OFF,LOW};
Dio_ConfigType  SPI_Master_SCK_config   ={PORT_B,PIN_7,OUTPUT,OFF,LOW};

Dio_ConfigType  SPI_Slave_SS_config    ={PORT_B,PIN_4,INPUT,OFF,LOW};
Dio_ConfigType  SPI_Slave_MOSI_config  ={PORT_B,PIN_5,INPUT,OFF,LOW};
Dio_ConfigType  SPI_Slave_MISO_config  ={PORT_B,PIN_6,OUTPUT,OFF,LOW};
Dio_ConfigType  SPI_Slave_SCK_config   ={PORT_B,PIN_7,INPUT,OFF,LOW};

Dio_ConfigType  ICU_echo_Pin_config   ={PORT_D,PIN_6,INPUT,OFF,LOW};
Dio_ConfigType  ICU_trig_Pin_config   ={PORT_D,PIN_5,OUTPUT,OFF,LOW};

Dio_ConfigType  IR_Out_Pin_config   ={PORT_A,PIN_0,INPUT,OFF,LOW};
Dio_ConfigType  RainSensor_Out_Pin_config   ={PORT_A,PIN_0,INPUT,OFF,LOW};


Dio_ConfigType  keypad_Col0  ={PORT_A,PIN_4,OUTPUT,OFF,LOW};
Dio_ConfigType  keypad_Col1  ={PORT_A,PIN_5,OUTPUT,OFF,LOW};
Dio_ConfigType  keypad_Col2  ={PORT_A,PIN_6,OUTPUT,OFF,LOW};
Dio_ConfigType  keypad_Col3  ={PORT_A,PIN_7,OUTPUT,OFF,LOW};
Dio_ConfigType  keypad_Row0  ={PORT_A,PIN_0,INPUT,OFF,LOW};
Dio_ConfigType  keypad_Row1  ={PORT_A,PIN_1,INPUT,OFF,LOW};
Dio_ConfigType  keypad_Row2  ={PORT_A,PIN_2,INPUT,OFF,LOW};
Dio_ConfigType  keypad_Row3  ={PORT_A,PIN_3,INPUT,OFF,LOW};

Dio_ConfigType  Servo_Motor_control_config  ={PORT_C,PIN_0,OUTPUT,OFF,LOW};


Dio_ConfigType seven_segment_pin0_Config ={PORT_D,PIN_0,OUTPUT,OFF,LOW};
Dio_ConfigType seven_segment_pin1_Config ={PORT_D,PIN_1,OUTPUT,OFF,LOW};
Dio_ConfigType seven_segment_pin2_Config ={PORT_D,PIN_2,OUTPUT,OFF,LOW};
Dio_ConfigType seven_segment_pin3_Config ={PORT_D,PIN_3,OUTPUT,OFF,LOW};

Dio_ConfigType seven_segment_pin4_Config ={PORT_D,PIN_4,OUTPUT,OFF,LOW};
Dio_ConfigType seven_segment_pin5_Config ={PORT_D,PIN_5,OUTPUT,OFF,LOW};
Dio_ConfigType seven_segment_pin6_Config ={PORT_D,PIN_6,OUTPUT,OFF,LOW};
Dio_ConfigType seven_segment_pin7_Config ={PORT_D,PIN_7,OUTPUT,OFF,LOW};


Dio_ConfigType LCD_CTL_RS_Config ={PORT_D,PIN_4,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_CTL_RW_Config ={PORT_D,PIN_5,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_CTL_EN_Config ={PORT_D,PIN_7,OUTPUT,OFF,LOW};


Dio_ConfigType LCD_pin0_Config ={PORT_C,PIN_0,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_pin1_Config ={PORT_C,PIN_1,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_pin2_Config ={PORT_C,PIN_2,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_pin3_Config ={PORT_C,PIN_3,OUTPUT,OFF,LOW};

Dio_ConfigType LCD_pin4_Config ={PORT_C,PIN_4,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_pin5_Config ={PORT_C,PIN_5,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_pin6_Config ={PORT_C,PIN_6,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_pin7_Config ={PORT_C,PIN_7,OUTPUT,OFF,LOW};
