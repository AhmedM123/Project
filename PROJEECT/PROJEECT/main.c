/*
 * try.c
 *
 * Created: 2/16/2023 4:19:10 AM
 * Author : ahmedelqady
 */ 
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\MCAL\TIMER\Timer_int.h"
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\HALL\GLCD\GLCD_h.h"
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\APP\PWM_int.h"
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\MCAL\DIO\DIO_int.h"

#define F_CPU 16000000
#include <util/delay.h>





int main(void){
	DIO_voidInit();            
	pwm_init();               //initialize timer in PWM mode
	glcd_init();		      /* Initialize GLCD */
	pwm_duty(150);           // duty cycle = 45% of 255 = 114.75 = 115
	pwm_freq(62700);
	while(1){
		 pwm_glcd();
		_delay_ms(1000);
		pwm_wave_show();
	}
}
	
