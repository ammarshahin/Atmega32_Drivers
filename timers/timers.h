/*
 * timers.h
 *
 * Created: 4/24/2019 12:54:42 AM
 *  Author: ammar shahin
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "std_macros.h"
void timer0_init();
void timer0_init_ocr();
uint64_t timer0_ms();
uint64_t timer0_ms_ocr();


#endif /* TIMERS_H_ */