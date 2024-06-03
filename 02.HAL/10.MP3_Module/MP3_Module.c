/*
 * MP3_Module.c
 *
 *  Created on: Nov 1, 2021
 *      Author: Mohamed Hamada
 */




#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/06.uart/uart.h"


#include "MP3_Module.h"

#define MP3_FRAME_SIZE 			10


#define MP3_START_BYTE 			0x7E

#define MP3_VERSION 			0xFF

#define MP3_NUMBER_OF_BYTE		0x06

#define MP3_NO_FEEDBACK			0x00
#define MP3_FEEDBACK			0x01

#define MP3_END_BYTE 			0xEF


/*		commands 		*/
#define MP3_MH_CMD_PLAY_NEXT			0x01
#define MP3_MH_CMD_PLAY_PREVIOUS		0x02
#define MP3_MH_CMD_PLAYBACK				0x03
#define MP3_MH_CMD_INCREASE_VOLUME		0x04
#define MP3_MH_CMD_DECREASEVOLUME		0x05
#define MP3_MH_CMD_VOLUME 				0x06
#define MP3_MH_CMD_RESET    			0x0C
#define MP3_MH_CMD_PLAY    			    0x0D
#define MP3_MH_CMD_PAUSE                0x0E





uint8 MP3_FRAME[MP3_FRAME_SIZE]={MP3_START_BYTE,MP3_VERSION,MP3_NUMBER_OF_BYTE,0,MP3_NO_FEEDBACK,0,0,0,0,MP3_END_BYTE};

extern USART_ConfigType uartConfig;

static void MP3_sendFrame(void);


void MP3_init()
{
	USART_init(&uartConfig );

	MP3_FRAME[3]=MP3_MH_CMD_RESET;

	MP3_sendFrame();
	MP3_FRAME[3]=0;
	
	_delay_ms(1000);

}
void MP3_playTrack(uint16 TrackNumber )
{
	MP3_FRAME[3]=MP3_MH_CMD_PLAYBACK;
	MP3_FRAME[5]= TrackNumber>>8 ;
	MP3_FRAME[6]= (uint8)TrackNumber;
	
	MP3_sendFrame();
	
	MP3_FRAME[3]=0;
	MP3_FRAME[5]=0;
	MP3_FRAME[6]=0;

	_delay_ms(1000);
}
void MP3_selectVolume(uint8 volumeLevel)
{
	MP3_FRAME[3]=MP3_MH_CMD_VOLUME;
	MP3_FRAME[5]= volumeLevel>>8 ;
	MP3_FRAME[6]= (uint8)volumeLevel;
	
	MP3_sendFrame();
	
	MP3_FRAME[3]=0;
	MP3_FRAME[5]=0;
	MP3_FRAME[6]=0;

	_delay_ms(1000);



}
static void MP3_sendFrame(void)
{
	uint8  i =0;
	uint16 CheckSum = 0;
	uint16 Add_Frame = 0;
	for(i=0;i<10;i++)
	{
		
		if ( i > 0 && i < 7 )
		{
			Add_Frame += MP3_FRAME[i];
		}
		else if ( i == 7)
		{
		  	CheckSum = 0xFFFF  -  Add_Frame  + 1 ;
			
			MP3_FRAME[7] = CheckSum >> 8 ;
			MP3_FRAME[8] = (unsigned char) CheckSum;
	 	}
		USART_SendByte(MP3_FRAME[i]);
	}	
	
	
	
}
