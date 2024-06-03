/*
 * File:   GPS.c
 * Author: Mohamed Hamada
 *
 * Created on October 19, 2020, 11:16 AM
 */

#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include<string.h>
#include<stdlib.h>

#include "../../01.MCAL/00.DIO/DIO.h"
#include "../../01.MCAL/06.uart/uart.h"

#include "GPS.h"

extern USART_ConfigType uartConfig;

static void GPS_setLocationAndDirection(uint8 *longitude, uint8 *longitudeDirection ,uint8 *latitude,uint8 *latitudeDirection);


void GPS_init(void)
{
	USART_init(&uartConfig);
}
void GPS_setLocation(float32 *longitude ,float32 *latitude)
{
    uint8 longitudeDirection=0;
	uint8 latitudeDirection =0;
	
	uint8 longitudeStr[13] ={0};
	uint8 latitudeStr[13] ={0};
		
    GPS_setLocationAndDirection(longitudeStr, &longitudeDirection ,latitudeStr,&latitudeDirection);

	 *longitude = atof(longitudeStr) / 100;
	 *latitude =  atof(latitudeStr)  / 100;
		
	
	if (longitudeDirection == 'W')
	{
		(*longitude) *=(-1);
	} 
	else if (longitudeDirection == 'E')
	{
			(*longitude) *=(1);

	} 
	else
	{
		/*   error   */
	}
	
	if (latitudeDirection == 'S')
	{
				(*longitude) *=(-1);
	}
	else if (latitudeDirection == 'N')
	{
		(*longitude) *=(1);
	}
	else
	{
		/*   error   */
	}
	
}
static void GPS_setLocationAndDirection(uint8 *longitude, uint8 *longitudeDirection ,uint8 *latitude,uint8 *latitudeDirection)
{
	
	uint8 received_data = 0;
	received_data= USART_RecieveByte();
	while(received_data !='$')
	{
		received_data= USART_RecieveByte();
	}
	if(received_data == '$')
	{   received_data= USART_RecieveByte();
		
		if(received_data == 'G')
		{
			received_data= USART_RecieveByte();
			if(received_data == 'P')
			{
				received_data= USART_RecieveByte();
				if(received_data == 'R')
				{
					received_data= USART_RecieveByte();
					if(received_data == 'M')
					{
						received_data= USART_RecieveByte();
						if(received_data == 'C')
						{
							received_data= USART_RecieveByte();
							if(received_data == ',')
							{
								received_data= USART_RecieveByte();
								while(received_data !='A')
								{
									received_data= USART_RecieveByte();
								}
								received_data= USART_RecieveByte();
								received_data= USART_RecieveByte();
								for(uint8 i=0;received_data!=',';i++)
								{
									latitude[i]=received_data;
									received_data= USART_RecieveByte();
								}
								
								received_data= USART_RecieveByte();
								if((received_data == 'N')||(received_data == 'S'))
								{
									*latitudeDirection = received_data;
									received_data= USART_RecieveByte();
									if(received_data == ',')
									{
										received_data= USART_RecieveByte();
										for(uint8 i=0;received_data!=',';i++)
										{
											longitude[i]=received_data;
											received_data= USART_RecieveByte();
										}
										received_data= USART_RecieveByte();
										if((received_data == 'E')||(received_data == 'W'))
										{
											*longitudeDirection = received_data; 
										}
										
									}
									
									
									
								}
							}
						}
					}
				}
			}
		}
	}

}
