/*
 * External_Interrupt_INT0.h
 *
 *  Created on: Jun 27, 2019
 *      Author: ammarPC
 */

#ifndef EXTERNAL_INTERRUPT_INT0_H_
#define EXTERNAL_INTERRUPT_INT0_H_

#include <avr/interrupt.h>
#include "macros.h"
#include "BasicTypes.h"


TU08 INT0_flag;
TU08 INT1_flag;
TU08 INT2_flag;

typedef enum Mode{
	LevelTrigered_Low,
	LevelTrigered_Anychange,
	EdgeTrigered_FallingEdge,
	EdgeTrigered_RasingEdge,
}Mode;


typedef enum INT_Number{
	INT_0,
	INT_1,
	INT_2,
}INT_Number;





#endif /* EXTERNAL_INTERRUPT_INT0_H_ */
