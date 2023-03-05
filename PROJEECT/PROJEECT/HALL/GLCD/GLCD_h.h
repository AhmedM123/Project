/*
 * GLCD_h.h
 *
 * Created: 3/4/2023 11:08:36 PM
 *  Author: ahmedelqady
 */ 


#ifndef GLCD_H_H_
#define GLCD_H_H_
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\Util\BIT_math.h"
#define F_CPU 16000000
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\Util\STD_types.h"
#include <util/delay.h>
#include "C:\Users\ahmedelqady\Desktop\PROJEECT\PROJEECT\MCAL\DIO\DIO_int.h"


void glcd_init(void);
void GLCD_String(s32 chip,s8 page_no, s8 *str);
void glcd_cmd(u8 cmd);
void glcd_data(u8 dat);
void GLCD_SelectPage(s32 chip);
void GLCD_GoToLine(u8 Line);

typedef enum {
	GLCD_DISPLAY_OFF				= (0x3EU),
	GLCD_DISPLAY_ON					= (0x3FU),
	GLCD_SET_Y_ADDRESS_PREFIX		= (0x40U),
	GLCD_SET_X_ADDRESS_PREFIX		= (0xB8U),
	GLCD_SET_Z_ADDRESS_PREFIX		= (0xC0U)
}GLCD_CommandType;



#define GLCD_MAX_LINES							(8U)
#define GLCD_MAX_LINE_PIXEL_WIDTH				(128U)
#define GLCD_MAX_PAGE_PIXEL_WIDTH				(64U)

#endif /* GLCD_H_H_ */