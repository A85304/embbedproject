//name:omar hassanien
// ID:1809513   sec:3  
#include "stdint.h"
#include "tm4c123gh6.h"
void SystemInit(){}

/* THis function take two parameters the first is the calculated distance from another function 
and the second parameter is the max distance that if total distance exceed The red led will turn on 
and in the project it must be 100 but i left it as general*/
	void TURN_ON(float distance,float max_distance)
{
if(distance>=max_distance)
{
	GPIO_PORTF_DATA_R =0x02; //the led red turn on by set PF1 equal 1 if total distance greater than max_distance
}
else
{
	GPIO_PORTF_DATA_R =0x00;//the led red turn off by set PF1 equal 0 if total distance not greater than max_distance
}
}

