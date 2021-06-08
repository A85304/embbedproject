#include"GPS_RECIEVE.h"

uint8_t *GPS_GET_LINE(void){
	uint8_t buffer[82];    				//longest nema massege is 82
	uint8_t read_ch;			
	int i=1;
	//begins saving data when reads $
	do{
		read_ch=READ_UART();
	}while(read_ch !='$');
	buffer[0]=read_ch;
	
	// taking a nema massege from gps
	while(i<82){
		read_ch=READ_UART();
		if(read_ch !=0)								// doesn't take newlines
		{
			buffer[i]=read_ch;
			i++;
		}
		else{
			break;
		}
	}
	return buffer;
}

uint8_t *GPS_DATA_RECIVE(void){
	uint8_t *buffer;									//longest nema massege is 82
	do{
	buffer=GPS_GET_LINE();
		
	}while((strncmp(buffer,"$GPGLL",6)!=0));     // addresse needed is $GPGLL
	return buffer;
}


