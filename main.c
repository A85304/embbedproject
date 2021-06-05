#include"tm4c123gh6pm.h"
#include"Seven_Segment_Display.h"
#include"UART_INI.h"
#include"Distance.h"
#include"GPIO_INI.h"
#include"tm4c123.h"
void SystemInit(){}
	int main(void){
		SCB->CPACR |=((3UL<<10*2)|(3UL<<11*2));
		
		//activating all needed peripherals
		initportf();
		initportA();
    initportB();
    initportD();
    initportE();
		//////////////////////////////////////////
		Seven_Segment_Display(125);
		TURN_ON_MAX_DISTANCE(125,100);
		return 0;
}

