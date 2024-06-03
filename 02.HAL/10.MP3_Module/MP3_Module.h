/*
 * MP3_Module.h
 *
 *  Created on: Nov 1, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_02_HAL_10_MP3_MODULE_MP3_MODULE_H_
#define ATMEGA16_02_HAL_10_MP3_MODULE_MP3_MODULE_H_


void MP3_init();
void MP3_playTrack(uint16 TrackNumber );
void MP3_selectVolume(uint8 volumeLevel);



#endif /* ATMEGA16_02_HAL_10_MP3_MODULE_MP3_MODULE_H_ */
