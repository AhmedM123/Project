/*
 * GLCD.c
 *
 * Created: 3/4/2023 11:07:47 PM
 *  Author: ahmedelqady
 */ 
#include "GLCD_h.h"
#include "GLCD_priv.h"
#include "BIT_math.h"
#include "GLCD_h.h"
#include "ATmega32_Register.h"
#define F_CPU 16000000
#include "STD_types.h"
#include <util/delay.h>


s32 gu8_Curr_X_Address = 0;
s32 gu8_Curr_Y_Address = 0;
s32 gu8_Curr_Page = 0;


s32 i;
void glcd_cmd(u8 cmd) //subroutine for command
{
	PORTC=cmd;
	_delay_ms(2);
	PORTD&=~(1<<2);
	PORTD&=~(1<<1);
	PORTD|=(1<<0);
	_delay_ms(2);
	PORTD&=~(1<<0);
}

void glcd_data(u8 dat)  //subroutine for data
{
	PORTC=dat;
	_delay_ms(2);
	PORTD|=(1<<2);
	PORTD&=~(1<<1);
	PORTD|=(1<<0);
	_delay_ms(2);
	PORTD&=~(1<<0);
}

void glcd_init()                //subroutine for initialization
{
	u8 command[4]={0x10,0xb8,0x40,0x3f};
	GLCD_SelectPage(1);                      //Chip selection
	for(i=0;i<4;i++)
	glcd_cmd(command[i]);
	GLCD_SelectPage(0);
	for(i=0;i<4;i++)
	glcd_cmd(command[i]);
}

void GLCD_SelectPage(s32 chip)    //Chip selection
{
	if(chip==1)
	{
		PORTD|=(1<<4);
		PORTD&=~(1<<3);
	}
	else
	{
		PORTD&=~(1<<4);
		PORTD|=(1<<3);
	}
}

void GLCD_String(s32 chip,s8 page_no, s8 *str)/* GLCD string write function */
{
	 u8 i, column;
	 u8 Page = ((0xB8) + page_no);
	 u8 Y_address = 0;
	float Page_inc = 0.5;
	GLCD_SelectPage(chip);
	
	glcd_cmd(Page);
	for(i = 0; str[i] != 0; i++)	/* Print char in string till null */
	{
		if (Y_address > (1024-(((page_no)*128)+FontWidth)))
		break;
		if (str[i]!=32)
		{
			for (column=1; column<=FontWidth; column++)
			{
				if ((Y_address+column)==(128*((s32)(Page_inc+0.5))))
				{
					if (column == (FontWidth))
					break;
					glcd_cmd(0x40);
					Y_address = Y_address + column;
					PORTD ^= (1 << 4);
					PORTD ^= (1 << 3);
					glcd_cmd(Page + Page_inc);
					Page_inc = Page_inc + 0.5;
				}
			}
		}
		if (Y_address>(1024-(((page_no)*128)+FontWidth)))
		break;
		if((font[((str[i]-32)*FontWidth)+4])==0 || str[i]==32)
		{
			for(column=0; column<FontWidth; column++)
			{
				glcd_data(font[str[i]-32][column]);
				if((Y_address+1)%64==0)
				{
					PORTD ^= (1 << 4);
					PORTD ^= (1 << 3);
					glcd_cmd((Page+Page_inc));
					Page_inc = Page_inc + 0.5;
				}
				Y_address++;
			}
		}
		else
		{
			for(column=0; column<FontWidth; column++)
			{
				glcd_data(font[str[i]-32][column]);
				if((Y_address+1)%64==0)
				{
					PORTD ^= (1 << 4);
					PORTD ^= (1 << 3);
					glcd_cmd((Page+Page_inc));
					Page_inc = Page_inc + 0.5;
				}
				Y_address++;
			}
			glcd_data(0);
			Y_address++;
			if((Y_address)%64 == 0)
			{
				PORTD ^= (1 << 4);
				PORTD ^= (1 << 3);
				glcd_cmd((Page+Page_inc));
				Page_inc = Page_inc + 0.5;
			}
		}
	}
	glcd_cmd(0x40);	/* Set Y address (column=0) */
}

void GLCD_GoToLine(u8 Line) {
	if (Line < GLCD_MAX_LINES) {
		GLCD_SelectPage(1);
		gu8_Curr_X_Address = Line;
		glcd_cmd(GLCD_SET_X_ADDRESS_PREFIX + gu8_Curr_X_Address);
		gu8_Curr_Y_Address = 0;
		glcd_cmd(GLCD_SET_Y_ADDRESS_PREFIX + gu8_Curr_Y_Address);
	}
}