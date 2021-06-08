#ifndef UART_INI_H
#define UART_INI_H

#include"tm4c123gh6pm.h"
#include"stdint.h"
void UART_INI(void);
uint8_t READ_UART(void);
void WRITE_UART(uint8_t);
#endif
