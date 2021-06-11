#include"Seven_Segment_Display.h"

void clear_seven_segment_display(void){
		GPIO_PORTB_DATA_R &= ~0xFF;		//all Pins of the (units, Tenth, Hundreds) seven segment display will be set to 0
		GPIO_PORTE_DATA_R &= ~0x3C;
		GPIO_PORTD_DATA_R &= ~0xCE;		
		GPIO_PORTA_DATA_R &= ~0xFC;
}

//This function takes one parameter (the distance) as a float then casted to integer, it displays the distance on the three seven segment displays
			
void Seven_Segment_Display(float distance){
	
		int Distance  = (int)distance;
		int Units = (Distance % 10);	
		int Tenth = (Distance % 100)/10;
		int Hundreds = (Distance % 1000)/100;

		
		if(Distance >= 1000)				//Maximum available distance = 999, 000 indicates that the maximum available distance is exceeded
			{
			GPIO_PORTB_DATA_R |= 0x3F;		//the units seven segment display will be set to 0
			GPIO_PORTA_DATA_R |= 0xF0;		//the tenth seven segment display will be set to 0
			GPIO_PORTE_DATA_R |= 0x0C;
			GPIO_PORTD_DATA_R |= 0x8E;		//the hundreds seven segment display will be set to 0
			GPIO_PORTA_DATA_R |= 0x0C;
			}
		
		else if(Units >= 0 && Tenth >=0 && Hundreds >=0)
			{
			if (Units == 0){                 			//PB7 will not be used (DP which is not important) as PD1 is used [we can use both pins (PD1 and PB7) by removing the R10 resistor]
				GPIO_PORTB_DATA_R |= 0x3F;}			//all pins will be set to 1 except pins G and DP in the seven segment display
			else if (Units == 1){
				GPIO_PORTB_DATA_R |= 0x06;}			//pins B and C will be set to 1 in the seven segment display
			else if (Units == 2){
				GPIO_PORTB_DATA_R |= 0x5B;}			//pins A,B,D,E and G will be set to 1 in the seven segment display
			else if (Units == 3){
				GPIO_PORTB_DATA_R |= 0x4F;}			//pins A,B,C,D and G will be set to 1 in the seven segment display
			else if (Units == 4){
				GPIO_PORTB_DATA_R |= 0x66;}			//pins B,C,F and G will be set to 1 in the seven segment display
			else if (Units == 5){
				GPIO_PORTB_DATA_R |= 0x6D;}			//pins A,C,D,F and G will be set to 1 in the seven segment display
			else if (Units == 6){
				GPIO_PORTB_DATA_R |= 0x7D;}			//all pins will be set to 1 except pins B and DP in the seven segment display
			else if (Units == 7){
				GPIO_PORTB_DATA_R |= 0x07;}			//pins A,B and C will be set to 1 in the seven segment display
			else if (Units == 8){
				GPIO_PORTB_DATA_R |= 0x7F;}			//all pins will be set to 1 except the pin DP in the seven segment display
			else if (Units == 9){
				GPIO_PORTB_DATA_R |= 0x6F;}			//all pins will be set to 1 except pins E and DP in the seven segment display
			
			
			if (Tenth == 0){
				GPIO_PORTA_DATA_R |= 0xF0;			//pins from 4-7 in PORTA 
				GPIO_PORTE_DATA_R |= 0x0C;}			//pins from 2-5 in PORTE
			else if (Tenth == 1){
				GPIO_PORTA_DATA_R |= 0x60;			
				GPIO_PORTE_DATA_R &= ~0x3C;}			//pins B and C will be set to 1 in the seven segment display
			else if (Tenth == 2){
				GPIO_PORTA_DATA_R |= 0xB0;
				GPIO_PORTE_DATA_R |= 0x14;}			//pins A,B,D,E and G will be set to 1 in the seven segment display
			else if (Tenth == 3){
				GPIO_PORTA_DATA_R |= 0xF0;
				GPIO_PORTE_DATA_R |= 0x10;}			//pins A,B,C,D and G will be set to 1 in the seven segment display
			else if (Tenth == 4){
				GPIO_PORTA_DATA_R |= 0x60;
				GPIO_PORTE_DATA_R |= 0x18;}			//pins B,C,F and G will be set to 1 in the seven segment display
			else if (Tenth == 5){
				GPIO_PORTA_DATA_R |= 0xD0;
				GPIO_PORTE_DATA_R |= 0x18;}			//pins A,C,D,F and G will be set to 1 in the seven segment display
			else if (Tenth == 6){
				GPIO_PORTA_DATA_R |= 0xD0;
				GPIO_PORTE_DATA_R |= 0x1C;}			//all pins will be set to 1 except pins B and DP in the seven segment display
			else if (Tenth == 7){
				GPIO_PORTA_DATA_R |= 0x70;			//pins A,B and C will be set to 1 in the seven segment display
				GPIO_PORTE_DATA_R &= ~0x3C;}
			else if (Tenth == 8){
				GPIO_PORTA_DATA_R |= 0xF0;
				GPIO_PORTE_DATA_R |= 0x1C;}			//all pins will be set to 1 except the pin DP in the seven segment display
			else if (Tenth == 9){
				GPIO_PORTA_DATA_R |= 0xF0;
				GPIO_PORTE_DATA_R |= 0x18;}			//all pins will be set to 1 except pins E and DP in the seven segment display
			
// We can use the entire GPIO_PORTD but we face some difficulties in connecting the two pins D4 AND D5 (also we can use them afterwards in the project) so we used A2 and A3 instead
			
			if (Hundreds == 0){	
				GPIO_PORTD_DATA_R |= 0x8E;			//PD0 is not used as PB6 is used ,,,,,,So PD7 is used instead (PD0->PD7) [we can use both pins (PD0 and PB6) by removing the R9 resistor]
				GPIO_PORTA_DATA_R |= 0x0C;}
			else if (Hundreds == 1){
				GPIO_PORTD_DATA_R |= 0x06;			//pins B and C will be set to 1 in the seven segment display	
				GPIO_PORTA_DATA_R &= ~0x0C;}
			else if (Hundreds == 2){
				GPIO_PORTD_DATA_R |= 0xCA;			//pins A,B,D,E and G will be set to 1 in the seven segment display
				GPIO_PORTA_DATA_R |= 0x04;}
			else if (Hundreds == 3){
				GPIO_PORTD_DATA_R |= 0xCE;			//pins A,B,C,D and G will be set to 1 in the seven segment display
				GPIO_PORTA_DATA_R &= ~0x0C;}
			else if (Hundreds == 4){
				GPIO_PORTD_DATA_R |= 0x46;			//pins B,C,F and G will be set to 1 in the seven segment display
				GPIO_PORTA_DATA_R |= 0x08;}
			else if (Hundreds == 5){			
				GPIO_PORTD_DATA_R |= 0xCC;			//pins A,C,D,F and G will be set to 1 in the seven segment display
				GPIO_PORTA_DATA_R |= 0x08;}
			else if (Hundreds == 6){
				GPIO_PORTD_DATA_R |= 0xCC;			//all pins will be set to 1 except pins B and DP in the seven segment display
				GPIO_PORTA_DATA_R |= 0x0C;}			
			else if (Hundreds == 7){
				GPIO_PORTD_DATA_R |= 0x86;			//pins A,B and C will be set to 1 in the seven segment display
				GPIO_PORTA_DATA_R &= ~0x0C;}		
			else if (Hundreds == 8){
				GPIO_PORTD_DATA_R |= 0xCE;			//all pins will be set to 1 except the pin DP in the seven segment display
				GPIO_PORTA_DATA_R |= 0x0C;}			
			else if (Hundreds == 9){
				GPIO_PORTD_DATA_R |= 0xCE;			//all pins will be set to 1 except pins E and DP in the seven segment display
				GPIO_PORTA_DATA_R |= 0x08;}			
			}
}
