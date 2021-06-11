#include"UART_INI.h"
//omar moataz

void UART_INI(void){
	SYSCTL_RCGCGPIO_R |=0x01;												//activate clk in gpio_A
	SYSCTL_RCGCUART_R |=0x01;												//activate clk in uart_0
	while((SYSCTL_PRGPIO_R &(1u))==0);							//wating for activation
	GPIO_PORTE_LOCK_R=GPIO_LOCK_KEY;								//unlocking gpio comit register
	GPIO_PORTE_CR_R|=0x03;													//unlocking bits 0,1 in gpioA
	GPIO_PORTE_AMSEL_R &=~0x03;											//disable analog
	         
	GPIO_PORTE_PCTL_R &=~0xFF;											//clearing first two pins function
	GPIO_PORTE_PCTL_R |=0x11;												//choosing alternate fun in mux
	GPIO_PORTE_AFSEL_R|=0x03;												//choosing uart
	GPIO_PORTE_DEN_R |=0x03;												//enable digital fun
	
	UART7_CTL_R  &=~UART_CTL_UARTEN;								//disable uart for config
	    
																								//BR =9600
	UART7_IBRD_R |=0x68;														//setting integer BR to 104
	UART7_FBRD_R |=0x0B;														//setting fractional BR to 11
	    
	UART7_LCRH_R =(UART_LCRH_WLEN_8|UART_LCRH_FEN);  //enable fifo and making data len 8 bits
	    
																							//to update BR LCRH must recieve config
	    
																		
	UART7_CTL_R =(UART_CTL_TXE|UART_CTL_RXE|UART_CTL_UARTEN);  //enable transmit and rescieve and enable uart end of config
	
	
}
