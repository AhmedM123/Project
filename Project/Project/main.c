/*
 * try.c
 *
 * Created: 2/16/2023 4:19:10 AM
 * Author : ahmedelqady
 */ 
#include "BIT_math.h"
#include "Timer_int.h"
#include "Font_Header.h"
#include <stdio.h>			/* Include std i/o library file */

#define F_CPU 16000000
#include "STD_types.h"
#include <avr/io.h>
#include <util/delay.h>
#include "DIO_int.h"




#define waves         "}|{@}|{@}|{@}|{@}|{@"
#define inwaves	      "|{@}|{@}|{@}|{@}|{@}"
typedef enum {
	GLCD_DISPLAY_OFF				= (0x3EU),
	GLCD_DISPLAY_ON					= (0x3FU),
	GLCD_SET_Y_ADDRESS_PREFIX		= (0x40U),
	GLCD_SET_X_ADDRESS_PREFIX		= (0xB8U),
	GLCD_SET_Z_ADDRESS_PREFIX		= (0xC0U)
}GLCD_CommandType;

int gu8_Curr_X_Address = 0;
int gu8_Curr_Y_Address = 0;
int gu8_Curr_Page = 0;
#define GLCD_MAX_LINES							(8U)
#define GLCD_MAX_LINE_PIXEL_WIDTH				(128U)
#define GLCD_MAX_PAGE_PIXEL_WIDTH				(64U)

int i;
void glcd_cmd(unsigned char cmd);
void glcd_data(unsigned char dat);
void GLCD_SelectPage(int chip);

void glcd_cmd(unsigned char cmd) //subroutine for command
{
	PORTC=cmd;
	_delay_ms(2);
	PORTD&=~(1<<2);
	PORTD&=~(1<<1);
	PORTD|=(1<<0);
	_delay_ms(2);
	PORTD&=~(1<<0);
}

void glcd_data(unsigned char dat)  //subroutine for data
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
	unsigned char command[4]={0x10,0xb8,0x40,0x3f};
	GLCD_SelectPage(1);                      //Chip selection
	for(i=0;i<4;i++)
	glcd_cmd(command[i]);
	GLCD_SelectPage(0);
	for(i=0;i<4;i++)
	glcd_cmd(command[i]);
}

void GLCD_SelectPage(int chip)    //Chip selection
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

void GLCD_String(int chip,char page_no, char *str)/* GLCD string write function */
{
	unsigned int i, column;
	unsigned int Page = ((0xB8) + page_no);
	unsigned int Y_address = 0;
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
				if ((Y_address+column)==(128*((int)(Page_inc+0.5))))
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

void GLCD_GoToLine(uint8_t Line) {
	if (Line < GLCD_MAX_LINES) {
		GLCD_SelectPage(1);
		gu8_Curr_X_Address = Line;
		glcd_cmd(GLCD_SET_X_ADDRESS_PREFIX + gu8_Curr_X_Address);
		gu8_Curr_Y_Address = 0;
		glcd_cmd(GLCD_SET_Y_ADDRESS_PREFIX + gu8_Curr_Y_Address);
	}
}
void pwm_init()
{
	TIMER0_void_Init();
}

int main(void){
{
	
	int duty;
	duty = 150;       // duty cycle = 45% of 255 = 114.75 = 115
	int myInt = 60;
	char myStg[10];
	sprintf(myStg, "%d", myInt);
	
	int myfeq = round(6.1);
	char myfreq[10];
	sprintf(myfreq, "%d", myfeq);
	
	DIO_voidInit();
	//initialize timer in PWM mode
	pwm_init();
glcd_init();		/* Initialize GLCD */
	//run forever
	DDRC=DDRD=0xff;
	_delay_ms(2);
	PORTD&=~(1<<5);
	_delay_ms(10);
	PORTD|=(1<<5);
	_delay_ms(2);
	while(1){
		

		GLCD_String(1,0,"Freq:");		
		GLCD_String(2,0,myfreq);
		GLCD_String(1,1,"Duty:");
		GLCD_String(2,1,myStg);
		OCR0 = duty;
		_delay_ms(1000);
	while (1)
		{
		GLCD_String(1,7,waves);
		_delay_ms(10);
		GLCD_String(1,7,inwaves);
		};
		while(1);
		}
	}
}
	
