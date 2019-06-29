/*
 * main.h
 *
 * Created: 3/30/2019 1:55:58 AM
 *  Author: ammar shahin
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include "macros.h"
#include "BasicTypes.h"
#include "External_Interrupt_INT0.h"

#include <avr/io.h>
#include <util/delay.h>

#define false 0
#define	true 1


extern TU08 INT0_flag;
extern TU08 INT1_flag;
extern TU08 INT2_flag;


#endif /* MAIN_H_ */
