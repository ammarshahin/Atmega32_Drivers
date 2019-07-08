/*
 * SPI.c
 *
 * Created: 6/7/2019 7:19:31 PM
 *  Author: ammar shahin
 */ 

#include "SPI.h"

void SPI_Master_Init()
{
	/* Set the pins PB4(SS), PB5(MOSI), and PB7(SCK) to be output */
	DDRB |= (1<<PB4) | (1<<PB5) | (1<<PB7);
	
	/* enable SPI, SPI Interrupt, be a "master", and clock polarity*/
	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<CPOL);
}

void SPI_Slave_Init()
{
	/* Set the pins PB6(MISO) to be output */
	DDRB |= (1<<PB6);
	
	/* enable SPI, SPI Interrupt, and set it to be a "Slave" */
	SPCR |= (1<<SPE) | (1<<CPOL);
}

TU08 SPI_Tx_Rx(TU08 data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}