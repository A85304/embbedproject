#include "stdint.h"
#include "tm4c123gh6.h"
void SystemInit(){}


	void TURN_ON(float distance,float max_distance)
{
if(distance>=max_distance)
{
	GPIO_PORTF_DATA_R =0x02;
}
else
{
	GPIO_PORTF_DATA_R =0x00;
}
}


	
	

