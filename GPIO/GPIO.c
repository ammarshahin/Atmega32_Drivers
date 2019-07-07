/*
 * GPIO.c
 *
 *  Created on: Jul 7, 2019
 * *      Author: ammar shahin 
 * 
 */
 
#include "GPIO.h"



 volatile unsigned char*  GPIO_ports[] = {myPORTA,myPORTB,myPORTC,myPORTD};
 volatile unsigned char*  GPIO_dirs[] = {myDDRA,myDDRB,myDDRC,myDDRD};
 volatile unsigned char*  GPIO_pins[] = {myPINA,myPINB,myPINC,myPIND};

TU08 get_port_index (TU08 port_name)
{
	TU08 i ;
	switch (port_name)
	{
	case 'A':
	case 'a':
		i = 0 ;
		break;
	case 'B' :
	case 'b':
		i = 1 ;
		break;
	case 'C':
	case 'c':
		i = 2 ;
		break;
	case 'D':
	case 'd':
		i = 3 ;
		break;

	}
return i ;

}



void GPIO_voidInit(void)
{
	/*Comment!: DDR initialization  */
	*GPIO_dirs[0] = Init_direction_default;
	*GPIO_dirs[1] = Init_direction_default;
	*GPIO_dirs[2] = Init_direction_default;
	*GPIO_dirs[3] = Init_direction_default;
}

//===================PIN==========================
//Data
/*Comment!: Read Pin Value */
TU08 GPIO_TU08_ReadPinVal(TU08 PinIdx,TU08* PtrToVal, TU08 Port_Name)
{
	TU08 API_Status ;

	if(PinIdx > no_of_pins_on_port - 1)
	{
		API_Status = error_happen;
	}
	else
	{

		*PtrToVal =  ((*GPIO_pins [ get_port_index(Port_Name) ] >>PinIdx)&1) ;
		API_Status = No_error;
	}

	return API_Status ;

}

/*Comment!: Write Pin Value */
TU08 GPIO_TU08_WritePinVal(TU08 PinIdx,TU08 PinVal , TU08 Port_Name)
{
	TU08 API_Status ;

	if(PinIdx > no_of_pins_on_port - 1)
	{
		API_Status = error_happen;
	}
	else
	{
		switch(PinVal)
		{
		case 1:
			*GPIO_ports[ get_port_index(Port_Name) ] |= 1<<PinIdx;
			API_Status = No_error;
			break;
		case 0:
			*GPIO_ports[ get_port_index(Port_Name) ] &= ~(1<<PinIdx) ;
			API_Status = No_error;
			break;
		default:
			API_Status = error_happen;
			break;

		}
	}

	return API_Status ;

}

//Direction
/*Comment!: Write Pin Direction */
TU08 GPIO_TU08_WritePinDir(TU08 PinIdx,TU08 PinDir , TU08 Port_Name)
{
	TU08 API_Status ;

	if(PinIdx > no_of_pins_on_port - 1)
	{
		API_Status = error_happen;
	}
	else
	{
		switch(PinDir)
		{
		case 1:
			*GPIO_dirs[ get_port_index(Port_Name) ] |= 1<<PinIdx;
			API_Status = No_error;
			break;
		case 0:
			*GPIO_dirs[ get_port_index(Port_Name) ] &= ~(1<<PinIdx) ;
			API_Status = No_error;
			break;
		default:
			API_Status = error_happen;
			break;

		}
	}

	return API_Status ;

}

/*Comment!: Read Pin Direction */
TU08 GPIO_TU08_ReadPinDir(TU08 PinIdx,TU08* PtrToDir , TU08 Port_Name )
{

	TU08 API_Status ;

	if(PinIdx > no_of_pins_on_port - 1)
	{
		API_Status = error_happen;
	}
	else
	{
		*PtrToDir =  ((*GPIO_dirs [ get_port_index(Port_Name) ] >> PinIdx) & 1) ;
		API_Status = No_error;
	}

	return API_Status ;
}
/////////////////////////////////////////////////
//===================PORT==========================
//Data
/*Comment!: Read Port Value */
TU08 GPIO_TU08_ReadPortVal(TU08* PtrToVal , TU08 Port_Name)
{

	*PtrToVal =  *GPIO_pins [ get_port_index(Port_Name) ] ;

	return No_error ;

}

/*Comment!: Write Port Value */
TU08 GPIO_TU08_WritePortVal(TU08 PortVal , TU08 Port_Name)
{
	*GPIO_ports[ get_port_index(Port_Name) ] = PortVal ;
	return No_error ;


}

//Direction
/*Comment!: Write Port Direction */
TU08 GPIO_TU08_WritePortDir(TU08 PortDir, TU08 Port_Name)
{
	  *GPIO_dirs [ get_port_index(Port_Name) ] = PortDir;

	return No_error ;

}


/*Comment!: Read Port Direction */
TU08 GPIO_TU08_ReadPortDir(TU08* PtrToDir, TU08 Port_Name)
{
	*PtrToDir =  *GPIO_dirs[ get_port_index(Port_Name) ] ;

	return No_error ;


}
//====================================================================