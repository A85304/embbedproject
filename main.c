#include "tm4c123gh6pm.h"
#include "Seven_Segment_Display.h"
#include "UART_INI.h"
#include "Distance.h"
#include "GPIO_INI.h"
#include "tm4c123.h"
#include "LCD.h"
#include "string.h"
#include "GPS_RECIEVE.h"


void SystemInit(){}
	int main(void){
		////////////////////////////////////////
		//variables 
		uint8_t *buffer;//gets data from gps
		int i;
		
		
		
		///////////////////////////////////////////
		//initialization
		SCB->CPACR |=((3UL<<10*2)|(3UL<<11*2));
		LCD_Init();
		LCD_Command(lcd_SetCursor_1);
		_delay_ms(2);
		UART_INI();
		
		
	///////////////////////////////////////////
	//program
	
		
}
