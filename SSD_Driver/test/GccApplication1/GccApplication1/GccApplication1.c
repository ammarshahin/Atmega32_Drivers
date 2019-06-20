#include "main.h"

int main(void)
{   
	SSD_Init();
	TU08 i;
	while(1)
	{
		for(i = 0 ; i < 16 ; i++)
		{
			SSD_Display_8Bit(i);
			_delay_ms(500);		
		}
	}		
}
