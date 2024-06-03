/*
 * keypad.c
 *
 *  Created on: Oct 6, 2021
 *      Author: Mohamed Hamada
 */


#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/00.DIO/DIO.h"


#include "keypad_config.h"
#include "keypad.h"

#if (N_col == 3)
static uint8 KeyPad_4x3_adjustKeyNumber(uint8 button_number);
#elif (N_col == 4)
static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number);
#endif

extern Dio_ConfigType  keypad_Col0   ;
extern Dio_ConfigType  keypad_Col1   ;
extern Dio_ConfigType  keypad_Col2   ;
extern Dio_ConfigType  keypad_Col3   ;
extern Dio_ConfigType  keypad_Row0   ;
extern Dio_ConfigType  keypad_Row1   ;
extern Dio_ConfigType  keypad_Row2   ;
extern Dio_ConfigType  keypad_Row3   ;


uint8 KeyPad_getPressedKey(void)
{

	Dio_Init(&keypad_Col0);
	Dio_Init(&keypad_Col1);
	Dio_Init(&keypad_Col2);
	#if (N_col == 4)
		Dio_Init(&keypad_Col3);
	#endif
	Dio_Init(&keypad_Row1);
	Dio_Init(&keypad_Row2);
	Dio_Init(&keypad_Row3);
	Dio_Init(&keypad_Row0);

	uint8 col =0;
	uint8 row =0;
	uint8 temp=0;
	while(1)
	{
		for(col =0;col<N_col;col++)
		{
			Dio_WritePort( KEYPAD_PORT, (~(0b00010000<<col)) );

			for(row=0;row<N_row;row++) /* loop for rows */
			{
				temp=Dio_ReadChannel(KEYPAD_PORT,row);
				if(temp == 0) /* if the switch is press in this row */
				{
					#if (N_col == 3)
						return KeyPad_4x3_adjustKeyNumber((row*N_col)+col+1);
					#elif (N_col == 4)
						return KeyPad_4x4_adjustKeyNumber((row*N_col)+col+1);
					#endif
				}
			}


		}


	}
}

	#if (N_col == 3)
	static uint8 KeyPad_4x3_adjustKeyNumber(uint8 button_number)
	{
		switch(button_number)
		{
			case 10: return '*'; // ASCII Code of *
					 break;
			case 11: return 0;
					 break;
			case 12: return '#'; // ASCII Code of #
					 break;
			default: return button_number;
		}
		return button_number;
	}
	#elif (N_col == 4)
	static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number)
	{

		switch(button_number)
		{
			case 1: return 7;
					break;
			case 2: return 8;
					break;
			case 3: return 9;
					break;
			case 4: return '%'; // ASCII Code of %
					break;
			case 5: return 4;
					break;
			case 6: return 5;
					break;
			case 7: return 6;
					break;
			case 8: return '*'; /* ASCII Code of '*' */
					break;
			case 9: return 1;
					break;
			case 10: return 2;
					break;
			case 11: return 3;
					break;
			case 12: return '-'; /* ASCII Code of '-' */
					break;
			case 13: return 13;  /* ASCII of Enter */
					break;
			case 14: return 0;
					break;
			case 15: return '='; /* ASCII Code of '=' */
					break;
			case 16: return '+'; /* ASCII Code of '+' */
					break;
			default: return button_number;
		}
		return button_number;
	}
	#endif

