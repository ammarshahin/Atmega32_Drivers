/*
 * SPI.h
 *
 * Created: 6/7/2019 7:19:08 PM
 *  Author: ammar shahin
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include "BasicTypes.h"
#include "BitMasking_Macros.h"

void SPI_Master_Init();
void SPI_Slave_Init();
TU08 SPI_Tx_Rx(TU08 data);

#endif /* SPI_H_ */