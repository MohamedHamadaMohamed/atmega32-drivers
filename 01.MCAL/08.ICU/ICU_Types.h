/*
 * ICU_Types.h
 *
 *  Created on: Oct 8, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_07_SPI_ICU_TYPES_H_
#define ATMEGA16_01_MCAL_07_SPI_ICU_TYPES_H_

#include "../../00.LIB/Std_types.h"


typedef enum { ICU_FALLING_EDGE=0,ICU_RISING_EDGE=1,ICU_BOTH_EDGES}ICU_ActivationType;

typedef uint16 Icu_ValueType;

typedef enum {ICU_No_clock_source=0,ICU_clk_No_prescaling=1,ICU_clk_divided_8=2,ICU_clk_divided_64=3,ICU_clk_divided_256=4,
	          ICU_clk_divided_1024=5 }ICU_Clk_prescaler;

typedef struct
{
	ICU_ActivationType ActivationType;
	ICU_Clk_prescaler Clk_prescaler;

	void (*CAllBackPtr)(void);

}Icu_ConfigType;
#endif /* ATMEGA16_01_MCAL_07_SPI_ICU_TYPES_H_ */
