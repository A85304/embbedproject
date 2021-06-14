#include"LED_SWITCH.h"

void TURN_ON_MAX_DISTANCE(float distance,float max_distance)
{
if(distance>=max_distance)
{
	GPIO_PORTF_DATA_R =0x02;
}
else
{
	GPIO_PORTF_DATA_R &=~0x02;
}
}
void init_interrupt(void)
{
	GPIO_PORTF_IS_R &= ~0x10;//The edge is detected
	GPIO_PORTF_IBE_R &= ~0x10;//The interrupt made only on falling or rising edge according to GPIO_PORTF_IEV_R
	GPIO_PORTF_IEV_R &= ~0x10;//The interrupt made on the falling edge;
	GPIO_PORTF_ICR_R = 0x10;//The corresponding interrupt is cleared
	GPIO_PORTF_IM_R |= 0x10;//enable the interrupt on  pin 4 in the port F
	NVIC_PRI7_R=(NVIC_PRI7_R&0xFF00FFFF)|0X00A00000;//it make the priorty 5
	NVIC_EN0_R = 0x40000000;//enable the interrupt on the port F as awhole;
}
void clear_interrupt(void){
	GPIO_PORTF_ICR_R = 0x10;
}