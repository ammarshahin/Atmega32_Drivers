/*
 * keypad.h
 *
 * Created: 4/4/2019 1:33:55 PM
 *  Author: ammarPC
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>
#include "BasicTypes.h"
#include "BitMasking_Macros.h"


#define NO_PRESSED_KEY			0
#define KEYPAD_DIR				DDRA
#define KEYPAD_PORT				PORTA
#define KEYPAD_ROWS				PINA


void keypad_init();
int KeyPad_getpressedkey(void);


#endif /* KEYPAD_H_ */