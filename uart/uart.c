/*
 * 	uart.c
 *
 * 	Created: 4/24/2019 5:10:39 PM
 *  Author: ammar shahin
 */ 



#include "uart.h"

void UART_Init()
{
	/* baud rate 9600, F_CPU = 8Mhz */
	UBRRL = 51;

	/* Enable receiver and transmitter */
	UCSRB |= (1<<RXEN) | (1<<TXEN); 
	
	/* Enable UART , Asynchronous operation , no parity , one stop bit , 8-bit char */ 
	UCSRC |= (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
}

void Uart_Write(TU08 data){
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );  // check trans
	UDR = data;
}

void Uart_Write_string(TU08 *data){
	for(TU08 i = 0; data[i] != '\0'; i++)
		Uart_Write(data[i]);
}

TU08 UART_Recieve(){
	while ( !(UCSRA & (1<<RXC)) );
	return UDR;
}

TU08 Uart_available(){
    if( (UCSRA & (1<<RXC)) ){
		return 1;
	}
	return 0;
}