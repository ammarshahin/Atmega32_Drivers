/*
 * main.c
 *
 *  Created on: Jun 27, 2019
 *      Author: ammar shahin
 */

#include "main.h"

int main()
{
// Set PA0 pin to be Output
	DDRA  |= (1<<PA0);
	PORTA |= (1<<PA0);

	INT_Init(INT_0,EdgeTrigered_FallingEdge);
	INT_Init(INT_1,EdgeTrigered_RasingEdge);

	while(true)
    {
		if(INT0_flag == 1)
		{
			SET_BIT(PORTA,0);
			INT0_flag = 0;
		}

		if(INT1_flag == 1)
		{
			CLR_BIT(PORTA,0);
			INT1_flag = 0;
		}
	}
	return 0;
}
