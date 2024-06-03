/*
 * GPT.h
 *
 *  Created on: Sep 20, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_02_GPT_GPT_H_
#define ATMEGA16_01_MCAL_02_GPT_GPT_H_

#include "GPT_Types.h"


void Gpt_Init( const Gpt_ConfigType* ConfigPtr );
void Gpt_DeInit( void );/* Deinitializes all hardware timer channels*/
Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel ); /*Returns the time already elapsed.*/
Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel ); /*  Returns the time remaining until the target time is reached.*/
void Gpt_StopTimer( Gpt_ChannelType Channel ); /* Stops a timer channel.*/

#endif /* ATMEGA16_01_MCAL_02_GPT_GPT_H_ */
