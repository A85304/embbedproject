#ifndef KEY_PAD_H
#define KEY_PAD_H

#include "LCD.h"
#include "tm4c123gh6pm.h"
#include "STD_TYPES.h"

	
u16 KPD_GetKey(void);
void keypad_Init(void);
void _delay_ms(u8 mill_sec);






#endif