/*
 * PWM_int.h
 *
 * Created: 3/4/2023 11:43:21 PM
 *  Author: ahmedelqady
 */ 
#include "BIT_math.h"


#include "GLCD_h.h"

#define F_CPU 16000000
#include "STD_types.h"
#include <avr/io.h>
#include <util/delay.h>
#include "DIO_int.h"


#ifndef PWM_INT_H_
#define PWM_INT_H_

void pwm_init(void);

void pwm_duty(s32 duty);
void pwm_wave_show(void);
void pwm_freq(s64 freq);
void pwm_glcd(void);
#endif /* PWM_INT_H_ */