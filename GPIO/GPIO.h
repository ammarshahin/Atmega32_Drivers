/*
 * GPIO.h
 *
 *  Created on: Jul 7, 2019
 * *      Author: ammar shahin 
 * 
 */


#ifndef GPIO_H_
#define GPIO_H_


#include "../BasicTypes.h"
	

#define myPORTA  ((volatile unsigned char* const)0X3B)
#define myDDRA   ((volatile unsigned char* const)0X3A)
#define myPINA   ((volatile unsigned char* const)0X39)
#define myPORTB  ((volatile unsigned char* const)0X38)
#define myDDRB   ((volatile unsigned char* const)0X37)
#define myPINB   ((volatile unsigned char* const)0X36)
#define myPORTC  ((volatile unsigned char* const)0X35)
#define myDDRC   ((volatile unsigned char* const)0X34)
#define myPINC   ((volatile unsigned char* const)0X33)
#define myPORTD  ((volatile unsigned char* const)0X32)
#define myDDRD   ((volatile unsigned char* const)0X31)
#define myPIND   ((volatile unsigned char* const)0X30)


#define TU08_Direction_input 0x00
#define TU08_Direction_output 0xFF

//choose the default initialization for GPIO
#define Init_direction_default  TU08_Direction_input
#define no_of_pins_on_port  8

//=========================Initialization====================================
/*Comment!: Initialization function */
 void GPIO_voidInit(void);
//====================================================================

//===================PIN==========================
//Data
/*Comment!: Read Pin Value */
 extern TU08 GPIO_TU08_ReadPinVal(TU08 PinIdx,TU08* PtrToVal, TU08 Port_Name);

/*Comment!: Write Pin Value */
 extern TU08 GPIO_TU08_WritePinVal(TU08 PinIdx,TU08 PinVal , TU08 Port_Name);

//Direction
/*Comment!: Write Pin Direction */
 extern TU08 GPIO_TU08_WritePinDir(TU08 PinIdx,TU08 PinDir, TU08 Port_Name);

/*Comment!: Read Pin Direction */
 extern TU08 GPIO_TU08_ReadPinDir(TU08 PinIdx,TU08* PtrToDir, TU08 Port_Name);

//===================PORT==========================
//Data
/*Comment!: Read Port Value */
 extern TU08 GPIO_TU08_ReadPortVal(TU08* PtrToVal , TU08 Port_Name);

/*Comment!: Write Port Value */
 extern TU08 GPIO_TU08_WritePortVal(TU08 PortVal , TU08 Port_Name);

//Direction
/*Comment!: Write Port Direction */
 extern TU08 GPIO_TU08_WritePortDir(TU08 PortDir, TU08 Port_Name);

/*Comment!: Read Port Direction */
 extern TU08 GPIO_TU08_ReadPortDir(TU08* PtrToDir, TU08 Port_Name);
//====================================================================

#endif
