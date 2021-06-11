#include "tm4c123gh6pm.h"
#include "Seven_Segment_Display.h"
#include "UART_INI.h"
#include "Distance.h"
#include "GPIO_INI.h"
#include "tm4c123.h"
#include "LCD.h"
#include "string.h"
#include "GPS_RECIEVE.h"
#include "KEY_PAD.h"
#include "LED_SWITCH.h"
//extern variables from distance.c
extern double Lat1  ;						
extern double Long1 ;
extern float Total_Distance;			
extern int f;	

//global variable
uint8_t Global_falg=0;

void SystemInit(){}
	int main(void){
		////////////////////////////////////////
		//variables 
		uint8_t *buffer;//gets data from gps

		
		
		
		///////////////////////////////////////////
		//initialization
		SCB->CPACR |=((3UL<<10*2)|(3UL<<11*2));
			
		LCD_Init();
		LCD_Command(lcd_SetCursor_1);
		_delay_ms(2);
		
		UART_INI();
		keypad_Init();
		initportf();
		init_interrupt();
	///////////////////////////////////////////
	//program
	while(1){
		if(Global_falg==0){//when program is runing

			//geting lat and long and calculating distance
			buffer=GPS_DATA_RECIVE();
			Gps_Reading(buffer);
			Distance(Lat1,Long1);
			
			
			//printing distance
			LCD_Command(lcd_SetCursor_1);
			_delay_ms(2);
			LCD_String("Distance:",9,Total_Distance);
			_delay_ms(255);
			
			
			
			
			//checking max distance and turning on led
			TURN_ON_MAX_DISTANCE(Total_Distance,100);
				
		}
		
		
		else if(Global_falg==1){//when program is paused
			f=0;
		}
	}

	//////////////////////////////////////////////
	//tests if needed
	
	//distance and gps_read
	/*
	Gps_Reading("$GPGLL,5107.0013414,N,11402.3279144,W,205412.00,A,A*7");
	Distance(Lat1,Long1);
	Gps_Reading("$GNGLL,5107.0014143,N,11402.3278489,W,205122.00,A,A*6E");
	Distance(Lat1,Long1);
	Gps_Reading("$GPGLL,5107.0013414,N,11402.3279144,W,205412.00,A,A*7");
	Distance(Lat1,Long1);
	*/

	
	
	//gps test print lcd massege on gps
	/*
	while(1){
	buffer=GPS_DATA_RECIVE();
	LCD_Command(lcd_SetCursor_1);
	_delay_ms(2);
	LCD_String(buffer,16,0);
	_delay_ms(255);
	}
	*/
		
	//keypad test
	/*
	while(j<16){
	i=KPD_GetKey();
	LCD_Char(i);
		j++;
	};*/
	
}
void GPIOF_Handler(){
	clear_interrupt();
	if(Global_falg==0)Global_falg=1;
	else Global_falg=0;
}
