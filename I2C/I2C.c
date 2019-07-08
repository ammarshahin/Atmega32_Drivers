/*
 * I2C.h
 *
 * Created: 4/24/2019 6:45:32 PM
 *  Author: ammar shahin
 */
 
#include "I2C.h"


void I2C_master_init(void)
{
	TWBR = (TU08)TWBR_val; // Set the bit rate
	
	/* enable the TWI ack, Interrupt enable, and TWI enable */
	TWCR |= (1<<TWEA) | (1<<TWEN);
}


void I2C_Slave_Init(TU08 My_Add){
	TWAR = My_Add<<1;
	TWCR = (1<<TWEA) | (1<<TWEN);
}


void I2C_start(TU08 address)
{
	// reset TWI control register
	TWCR = 0;
	// transmit START condition
	TWCR |=  (1<<TWSTA) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	
	// load slave address into data register
	TWDR = address<<1;
	// start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
}

void I2C_write(TU08 data)
{
	// load data into data register
	TWDR = data;
	// start transmission of data
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
}

TU08 I2C_read(void)
{

	// start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA); 
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	// return received data from TWDR
	return TWDR;
}

void I2C_stop(void)
{
	// transmit STOP condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

TU08 I2C_Slave_avialable(){	
	TWCR |= (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	return ((TWSR & 0xF8) == TW_SR_SLA_ACK); 
}