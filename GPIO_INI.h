#ifndef GPIO_INI_H
#define GPIO_INI_H

#include"tm4c123gh6pm.h"

void initportf(void); // enable switches and leds
void initportA(void); // 7 segment"1" (4Pin)
void initportC(void); // 7 segment "1" (4 Pin)
void initportB(void); // 7 segment "2" (8Pin)
void initportD(void);  // 7 segment "3" (8Pin)
void initportE(void); // GPS 
#endif

