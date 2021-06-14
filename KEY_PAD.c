
#include "KEY_PAD.h"
/***************************************************************************************/

/************* KeyPad Key Index ***************/                         
/*         Col_0    Col_1   Col_2   Col_3     */
/*	                                          */              
/* row_0      1        2      3       10      */             
/*	                                          */               
/* row_1  	  4        5      6       11      */
/*	                                          */
/* row_2	  7        8      9       12      */
/*	                                          */
/* row_3	  15       0      14      13      */
/**********************************************/

/*
 ------------- 
 |  TM4C123  |                 ------------------------
 |           |                 |   		KEYPAD        |
 |           |                 |                      |
 |        PA4|---------------->|P8(R1)                |
 |        PA5|---------------->|P7(R2)                |
 |        PA6|---------------->|P6(R3)                |
 |        PA7|---------------->|P5(R4)                |
 |        PC0|<----------------|P4(C1)                |
 |        PC1|<----------------|P3(C2)                |
 |        PC2|<----------------|P2(C3)                |
 |        PC3|<----------------|P1(C4)                |
 |           |                 |                      |
 |           |                 |                      |
 |           |                 ------------------------                
 -------------          
 
 */
/***************************************************************************************/


const u8 KPD_Keys[4][4]= {{ '1', '2', '3', 'A'},
						  { '4', '5', '6', 'B'},
						  { '7', '8', '9', 'C'},
					      { '*', '0', '#', 'D'},
							                  };
						  

int main ()
{
	u8 Keypad_return = 0;
	keypad_Init();

	Keypad_return = KPD_GetKey();

}


void keypad_Init(void)
{
  SYSCTL_RCGCGPIO_R |= 0x05;            //Enable clock to PORTA and PORTC  
  while ((SYSCTL_PRGPIO_R &0x05)==0);   //wait for clock to be setted
  
  //////////output pins////////////// rows
  
  GPIO_PORTA_LOCK_R   = 0x4C4F434B;     //unlock GPIO port A
  GPIO_PORTA_CR_R    |= 0xF0;           //Allow settings for pins of PORTA (PA4-PA7)
  GPIO_PORTA_AMSEL_R &= 0x0F;           //disable analog on(PA4-PA7)
  GPIO_PORTA_DIR_R   |= 0xF0;           //(PA4-PA7) are used with rows and set them as digital output
  GPIO_PORTA_PCTL_R  &= 0x0000FFFF;     //PCTL GPIO on (PA4-PA7)
  GPIO_PORTA_AFSEL_R &= 0x0F;           //diable alt funct on (PA4-PA7)
  GPIO_PORTA_DEN_R   |= 0xF0;           //Set PORTA as digital pins(PA4-PA7)
  GPIO_PORTA_DATA_R  |= 0xF0;
  
  //////////input pins////////////// cols
  
  GPIO_PORTC_LOCK_R   = 0x4C4F434B;   //unlock GPIO port C
  GPIO_PORTC_CR_R    |= 0xF0;           //Allow settings for pins of PORTC (PC4-PC7)
  GPIO_PORTC_AMSEL_R &= 0x0F;           //disable analog on(PC4-PC7)
  GPIO_PORTC_DIR_R   &= 0x0F;           //(PC4-PC7)are used with cols and set them as digital input
  GPIO_PORTC_PCTL_R  &= 0x0000FFFF;     //PCTL GPIO on(PC4-PC7)
  GPIO_PORTC_AFSEL_R &= 0x0F;           //diable alt funct on(PC4-PC7)
  GPIO_PORTC_DEN_R   |= 0xF0;           //Set PORTC as digital pins(PC4-PC7)
  GPIO_PORTC_PUR_R   |= 0xF0;           //Enable pull up resistor on(PC4-PC7)
  GPIO_PORTC_DATA_R  |= 0xF0;
  
}

u16 KPD_GetKey(void)
{
	u8 RowsCounter,ColsCounter;
	u8 Keypad_return ;
	
	
	while ((((GPIO_PORTC_DATA_R &0xF0)>>4)==0x0F)&&(((GPIO_PORTA_DATA_R &0xF0)>>4)==0x0F));
			
	for (RowsCounter = 0; RowsCounter <= 3 ; RowsCounter++)
	{
		GPIO_PORTA_DATA_R &= (~(1<<(RowsCounter+4)));
		for (ColsCounter = 0; ColsCounter <= 3 ; ColsCounter++)
		{
			if (((GPIO_PORTC_DATA_R &0xF0)>> 4)!=0x0F)
			{
				/* Debouncing */
				_delay_ms(10);
					
				while(((GPIO_PORTC_DATA_R &0xF0)>> 4)!=0x0F);
						
				Keypad_return = KPD_Keys[RowsCounter][ColsCounter];
			
				break;
			}
			_delay_ms(2);
		}
		_delay_ms(2);
		GPIO_PORTA_DATA_R |=(1<<(RowsCounter+4));
	}	
		
	return Keypad_return;
}


void _delay_ms(u8 mill_sec)
{
	u16 i,j;
	for(i=0;i<mill_sec;i++)
	for(j=0;j<3180;j++)
	{}
}

