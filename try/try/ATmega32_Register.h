/*
 * ATmega32_Register.h
 *
 * Created: 8/24/2022 4:54:10 AM
 *  Author: ahmedelqady
 */ 


#ifndef ATMEGA32_REGISTER_H_
#define ATMEGA32_REGISTER_H_
#include "STD_types.h"
//*pind*/
#define PIND (*(volatile u8*)(0x30))
#define DDRD (*(volatile u8*)(0x31))
#define PORTD (*(volatile u8*)(0x32))
//*pinc*/
#define PINC (*(volatile u8*)(0x33))
#define DDRC (*(volatile u8*)(0x34))
#define PORTC (*(volatile u8*)(0x35))
//*pinb*/
#define PINB (*(volatile u8*)(0x36))
#define DDRB (*(volatile u8*)(0x37))
#define PORTB (*(volatile u8*)(0x38))

#define PINA  (*(volatile u8*)(0x39))
#define DDRA  (*(volatile u8*)(0x3A))
#define PORTA (*(volatile u8*)(0x3B))


#endif /* ATMEGA32_REGISTER_H_ */