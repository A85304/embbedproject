#include"GPIO_INI.h"

void initportf() // enable switches and leds
{

SYSCTL_RCGCGPIO_R |=0x20;
while ((SYSCTL_PRGPIO_R&0x20) == 0){};
GPIO_PORTF_LOCK_R =0x4C4F434B;
GPIO_PORTF_CR_R |=0x1F;
GPIO_PORTF_AFSEL_R = 0;
GPIO_PORTF_PCTL_R = 0;
GPIO_PORTF_AMSEL_R =0;
GPIO_PORTF_DIR_R |=0x0E;
GPIO_PORTF_DEN_R |=0x1F; 
GPIO_PORTF_PUR_R |=0x11;


}

void initportA() // 7 segment"1" (4Pin)
{

SYSCTL_RCGCGPIO_R |=0x01;
while ((SYSCTL_PRGPIO_R&0x01) == 0){};
//GPIO_PORTA_CR_R |=0xFC; //enable change pin 4 to pin7 
GPIO_PORTA_AFSEL_R = 0;
GPIO_PORTA_PCTL_R = 0;
GPIO_PORTA_AMSEL_R =0;  
GPIO_PORTA_DIR_R |=0xFC; //enable digital pin 4 TO pin 7 
GPIO_PORTA_DEN_R |=0xFC;  // pin 4 to pin 7 is output
GPIO_PORTA_PUR_R |=0x00;

}
void initportB() // 7 segment "2" (8Pin)
{

SYSCTL_RCGCGPIO_R |=0x02;
while ((SYSCTL_PRGPIO_R&0x02) == 0){};
//GPIO_PORTB_CR_R |=0xFF; //enable change pin 0 to pin 7
GPIO_PORTB_AFSEL_R = 0;
GPIO_PORTB_PCTL_R = 0;
GPIO_PORTB_AMSEL_R =0;  
GPIO_PORTB_DIR_R |=0xFF; //enable digital pin 0 TO pin 7 
GPIO_PORTB_DEN_R |=0xFF;  // pin 0 to pin 7 is output
GPIO_PORTB_PUR_R =0x00;

}
void initportD() // 7 segment "3" (8Pin)
{

SYSCTL_RCGCGPIO_R |=0x08;
while ((SYSCTL_PRGPIO_R&0x08) == 0){};
GPIO_PORTD_LOCK_R =0x4C4F434B;
GPIO_PORTD_CR_R |=0xFF; //enable change pin 0 to pin 7
GPIO_PORTD_AFSEL_R = 0;
GPIO_PORTD_PCTL_R = 0;
GPIO_PORTD_AMSEL_R =0;  
GPIO_PORTD_DIR_R |=0xFF; //enable digital pin 0 TO pin 7 
GPIO_PORTD_DEN_R |=0xFF;  // pin 0 to pin 7 is output
GPIO_PORTD_PUR_R =0x00;

}


void initportE() 
{

SYSCTL_RCGCGPIO_R |=0x10;
while ((SYSCTL_PRGPIO_R&0x10) == 0){};
//GPIO_PORTE_CR_R |=0X1C; //enable change except for 0 and 1
GPIO_PORTE_AFSEL_R &=~ 0x1C; 
GPIO_PORTE_DIR_R |=0x1C; 
GPIO_PORTE_DEN_R |=0x1C;  


}
