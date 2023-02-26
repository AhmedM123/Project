/************************************************/
/* Title       : Timer Private file             */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/


#ifndef _TIMER0_PRIV
#define _TIMER0_PRIV

#define TIMSK (*(volatile u8 * )0x59)
#define OCR0 (*(volatile u8 * )0x5C)
#define TCCR0 (*(volatile u8 * )0x53)
#define TCNT0 (*(volatile u8 * )0x52)
#define TIFR (*(volatile u8 * )0x58)
#define TCCR1A (*(volatile u8 *)0x4F)
#define TCCR1B (*(volatile u8 *)0x4E)
#define ICR1 (*(volatile int *)0x46)
#define OCR1A (*(volatile int *)0x4A)

#define TIMER0_NORMAL 		1
#define TIMER0_CTC 			2
#define TIMER0_FAST_PWM 	3
#define TIMER0_PHASE_PWM 	4

#define TIMER0_DIV_BY_1			1
#define TIMER0_DIV_BY_8			5
#define TIMER0_DIV_BY_64		8
#define TIMER0_DIV_BY_256		10
#define TIMER0_DIV_BY_1024		15


#define TIMER0_NO_ACTION	100
#define TIMER0_TOGGLE		12
#define TIMER0_SET			20
#define TIMER0_CLEAR		25

#define TIMER0_INVERTED      1
#define TIMER0_NON_INVERTED  2
#endif
