/*
 * try.c
 *
 * Created: 2/16/2023 4:19:10 AM
 * Author : ahmedelqady
 */ 
#include "BIT_math.h"
#include "Timer_priv.h"

#include "GLCD_h.h"
#include <stdio.h>	
#define F_CPU 16000000
#include "STD_types.h"
#include "ATmega32_Register.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "PWM_int.h"





s32 main(void){

	
	
	DIO_voidInit();
	//initialize timer in PWM mode
	pwm_init();
glcd_init();		/* Initialize GLCD */
	//run forever
	pwm_duty(150); // duty cycle = 45% of 255 = 114.75 = 115
	pwm_freq(62700);
	while(1){
		 pwm_glcd();
		_delay_ms(1000);
	pwm_wave_show();
	}
}
	
