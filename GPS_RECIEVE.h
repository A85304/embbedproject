#ifndef GPS_RECIEVE_H
#define GPS_RECIEVE_H

#include"string.h"
#include"stdint.h"
#include"UART_INI.h"
uint8_t *GPS_GET_LINE(void);				//get one line of information from gps
uint8_t *GPS_DATA_RECIVE(void);			//gets $GPGLL line only 




#endif