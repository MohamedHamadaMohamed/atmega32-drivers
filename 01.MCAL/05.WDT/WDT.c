/*
 * WDT.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Mohamed Hamada
 */

#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "WDT_Types.h"
#include "WDT.h"

void WDT_Enable(uint8 duration)
{
	WDTCR =0;
	WDTCR &= 0b11111000;
	WDTCR |= duration;

	SET_BIT(WDTCR, WDE);
}
void WDT_Disable(void)
{

    SET_BIT(WDTCR,WDE);
    SET_BIT(WDTCR,WDTOE);
    _delay_us(4);
    WDTCR =0;
}
