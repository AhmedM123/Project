/************************************************/
/* Title       : Timer interface file           */
/* Author      : Ahmed                */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#ifndef _TIMER0_INT_H
#define _TIMER0_INT_H


#include "STD_types.h"

void TIMER0_void_Init(void);

void TIMER0_void_SetTimerReg(u8 Copy_u8Val);

void TIMER0_void_SetCompareVal(u8 Copy_u8Val);

void TIMER0_void_EnableOVInt(void);

void TIMER0_void_DisableOVInt(void);

void TIMER0_void_EnableCTCInt(void);

void TIMER0_void_DisableCTCInt(void);

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) );

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) );


#endif