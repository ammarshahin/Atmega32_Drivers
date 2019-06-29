/*
 * External_Interrupt_INT0.c
 *
 *  Created on: Jun 27, 2019
 *      Author: ammarPC
 */

#include "External_Interrupt_INT0.h"


void INT_Init(INT_Number no,Mode mode)
{
	switch(no)
	{
	 case INT_0:
	 {
		 switch(mode)
		 {
		  case LevelTrigered_Low:
		  {
				MCUCR |= (0<<ISC00);
				MCUCR |= (0<<ISC01);
				break;
		  }
		  case LevelTrigered_Anychange:
		  {
			  	MCUCR |= (1<<ISC00);
				MCUCR |= (0<<ISC01);
		  		break;
		  }
		  case EdgeTrigered_FallingEdge:
		  {
				MCUCR |= (0<<ISC00);
				MCUCR |= (1<<ISC01);
				break;
		  }
		  case EdgeTrigered_RasingEdge:
		  {
				MCUCR |= (1<<ISC00);
				MCUCR |= (1<<ISC01);
				break;
		  }
		 }
		 GICR  |= (1<<INT0);
		 sei();
// Set INT0 pin to be Input
	 	 DDRD  |= (0<<PD2);
	 	 PORTD |= (1<<PD2); // set the Input with pull up
		 break;
	 }

	 case INT_1:
	 {
		 switch(mode)
		 		 {
		 		  case LevelTrigered_Low:
		 		  {
		 				MCUCR |= (0<<ISC10);
		 				MCUCR |= (0<<ISC11);
		 				break;
		 		  }
		 		  case LevelTrigered_Anychange:
		 		  {
		 			  	MCUCR |= (1<<ISC10);
		 				MCUCR |= (0<<ISC11);
		 		  		break;
		 		  }
		 		  case EdgeTrigered_FallingEdge:
		 		  {
		 				MCUCR |= (0<<ISC10);
		 				MCUCR |= (1<<ISC11);
		 				break;
		 		  }
		 		  case EdgeTrigered_RasingEdge:
		 		  {
		 				MCUCR |= (0<<ISC10);
		 				MCUCR |= (1<<ISC11);
		 				break;
		 		  }
		 		 }
		 GICR  |= (1<<INT1);
		 sei();
	// Set INT1 pin to be Input
		 DDRD  |= (0<<PD3);
	 	 PORTD |= (1<<PD3); // set the Input with pull up
		 break;
	 }

	 case INT_2:
	 {
		 // Not Yet
		 break;
	 }
	}
}


ISR(INT0_vect)
{
	INT0_flag = 1;
}

ISR(INT1_vect)
{
	INT1_flag = 1;
}

ISR(INT2_vect)
{
	INT2_flag = 1;
}
