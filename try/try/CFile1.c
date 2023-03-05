/*
 * CFile1.c
 *
 * Created: 2/24/2023 11:17:34 PM
 *  Author: ahmedelqady
 */ 
#define F_CPU 16000000UL
#include "Timer_priv.h"
#include "BIT_math.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "STD_types.h"
#include "ATmega32_Register.h"
#include "Timer_int.h"
int main(){
	DIO_voidInit();
	//SET_BIT(TCCR1A, 6);
	//CLEAR_BIT(TCCR1A , 7);
	//
	//CLEAR_BIT(TCCR1A,0);
	//SET_BIT(TCCR1A,1);
	//SET_BIT(TCCR1B,4);
	//SET_BIT(TCCR1B,3);
	//
	//ICR1= 10000;
	//
	//OCR1A= 5000;
	//
	//CLEAR_BIT(TCCR1B,0);
	//SET_BIT(TCCR1B,1);
	//SET_BIT(TCCR1B,2);
	//
	TIMER0_void_Init();
	
	                          //set PD7 as PWM output
	while (1)
	{int count;
		for (count=500;count<=1500;count++)
		{
		OCR0=count;
		//_delay_ms(2);
		if (count=1500)
		{count=500;
		}
	while(1);
		}
	}
}