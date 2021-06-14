#ifndef LED_SWITCH_H
#define LED_SWITCH_H

#include"tm4c123gh6pm.h"
void TURN_ON_MAX_DISTANCE(float distance,float max_distance); //turns on led if distance is more than max distance
void init_interrupt(void); //initiate interupt fo 
void clear_interrupt(void);

#endif