/*
 * switch.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed Hamada
 */


#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"


#include "../../01.MCAL/00.DIO/DIO.h"

#include "../01.switch/switch_config.h"
#include "../01.switch/switch.h"


extern Dio_ConfigType switch_Config ;

void switch_init()
{

	Dio_Init(&switch_Config);

}
bool switch_readSwitch()
{

bool pressed = 0;
#if SWITCH_PULL_UP == 1

    pressed =(! Dio_ReadChannel( SWITCH_PORT,SWITCH_PIN) );


#else

	pressed = Dio_ReadChannel( SWITCH_PORT,SWITCH_PIN );
#endif

return pressed;
}
