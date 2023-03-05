/*
 * PWM.c
 *
 * Created: 3/4/2023 11:41:50 PM
 *  Author: ahmedelqady
 */ 
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\Util\ATmega32_Register.h"
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\Util\BIT_math.h"
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\MCAL\TIMER\Timer_int.h"
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\MCAL\TIMER\Timer_priv.h"
#include "PWM_int.h"
#include "PWM_priv.h"
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\HALL\GLCD\GLCD_h.h"
#include <stdio.h>
#define F_CPU 16000000
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\Util\STD_types.h"
#include <avr/io.h>
#include <util/delay.h>
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\MCAL\DIO\DIO_int.h"
s8 freq_s[10];
s8 duty_s[10];
void pwm_init()
{
	TIMER0_void_Init();
	DDRC=DDRD=0xff;
	_delay_ms(2);
	PORTD&=~(1<<5);
	_delay_ms(10);
	PORTD|=(1<<5);
	_delay_ms(2);
}
void pwm_duty(s32 duty){
	duty = 150;       // duty cycle = 45% of 255 = 114.75 = 115
	s32 Duty_int = (duty/2.55);
	s8 duty_s[10];
	sprintf(duty_s, "%d", Duty_int);
	OCR0 = duty;
	GLCD_String(2,1,duty_s);
}
void pwm_wave_show(void){
	while (1)
	{
		GLCD_String(1,7,waves);
		_delay_ms(10);
		GLCD_String(1,7,inwaves);
	};
	while(1);
}
void pwm_freq(s64 freq)
{//choose to divide on 1024(61) or 256(245) or 64(980) or 8(7840) or 1(62700) from "Timer_config"
	s64 feq_int = 62700;
	s8 freq_s[100];
	sprintf(freq_s, "%ld", feq_int);

	GLCD_String(2,0,freq_s);
}

void pwm_glcd(void){
	GLCD_String(1,0,"Freq:");
	
	GLCD_String(1,1,"Dutycycl:");
	GLCD_String(1,4,"[ T ]");
	GLCD_String(1,5,"[   ]");
	
}