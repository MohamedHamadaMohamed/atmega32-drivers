/*
 * ADC.c
 *
 *  Created on: Sep 1, 2021
 *      Author: Mohamed Hamada
 */

#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"



#include "ADC_config.h"
#include "ADC.h"

volatile uint16 g_adcresult =0;



void ADC_init(ADC_ConfigType *config)
{

ADMUX =0;
 ADC =0;



 switch(config->Reference)
 {
 case Internal_Vref_turned_off :   CLEAR_BIT(ADMUX,REFS0);
 	 	 	 	 	 	 	 	   CLEAR_BIT(ADMUX,REFS1);
 	 	 	 	 	 	 	 	   break;
 case AVCC_with_external_capacitor:SET_BIT(ADMUX,REFS0);
 	 	 	 	 	 	 	 	   CLEAR_BIT(ADMUX,REFS1);
	 	                           break;
 case Internal_2_56V_Voltage : 	   SET_BIT(ADMUX,REFS0);
 	 	 	 	 	 	 	       SET_BIT(ADMUX,REFS1);
 	 	 	 	 	 	 	       break;
 }
 CLEAR_BIT(ADMUX,ADLAR);


 ADMUX &= 0b11100000;
 ADMUX |= config->initialChannelType;




#if ADC_TYPE == ADC_POLLING
 	 CLEAR_BIT(ADCSRA,ADIE);
#elif ADC_TYPE == ADC_INTERRUPT
     SET_BIT(ADCSRA,ADIE);
#endif

ADCSRA &=0b11111000;
ADCSRA |=config->Prescaler_Selections;


SET_BIT(ADCSRA,ADEN);



}
void ADC_readChannel(ADC_channelType channel)
{


ADMUX &= 0b11100000;
ADMUX |= channel;


	/* start conversion  */
	 SET_BIT(ADCSRA,ADSC);

#if (ADC_TYPE == ADC_POLLING)

	 while(BIT_IS_CLEAR(ADCSRA,ADIF));

	 SET_BIT(ADCSRA,ADIF);
	 g_adcresult = ADC;


#endif


}

#if ADC_TYPE == ADC_INTERRUPT

ISR(ADC_vect)
{
	 g_adcresult = ADC;


}
#endif
