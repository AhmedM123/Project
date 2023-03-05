/*
 * CFe2.c
 *
 * Created: 2/25/2023 1:50:41 PM
 *  Author: ahmedelqady
 */ 
#define F_CPU 16000000
#include "STD_types.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Timer_int.h"
#include "DIO_int.h"
void pwm_init()
{
TIMER0_void_Init();
 //make sure to make OC0 pin (pin PB3 for atmega32) as output pin
//DDRB |= (1<<3);
}

void main()
{
int duty;
duty = 115;       // duty cycle = 45% of 255 = 114.75 = 115
DIO_voidInit();
 //initialize timer in PWM mode
pwm_init();

 //run forever
while(1)
{
	OCR0 = duty;
	_delay_ms(100000);
}
}
