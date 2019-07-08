/*
 * uart.h
 *
 * Created: 7/7/2019
 *  Author: ammar shahin
 */ 

#ifndef UART_H_
#define UART_H_

#include "BasicTypes.h"
#include <avr/io.h>

void UART_Init();
TU08 UART_Recieve();
void Uart_Write(TU08);
TU08 Uart_available();
void Uart_Write_string(TU08 *data);


#endif /* UART_H_ */