/*
 * I2C.h
 *
 * Created: 4/24/2019 6:45:32 PM
 *  Author: ammar shahin
 */
 
#ifndef I2C_MASTER_H
#define I2C_MASTER_H

#include <util/twi.h> 
#include "BasicTypes.h"
#include "BitMasking_Macros.h"

#define F_SCL 100000UL // SCL frequency
#define F_CPU 1000000UL

#define Prescaler 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)


#define TW_MR_ARB_LOST   0x38
#define TW_START         0x08  // start bit has been transmitted
#define TW_REP_START     0x10
#define TW_MT_SLA_ACK    0x18  // +ve ACK for address transmitted
#define TW_MT_DATA_ACK   0x28
#define TW_MR_DATA_NACK  0x58
#define TW_MR_SLA_NACK   0x48
#define TW_MT_SLA_NACK   0x20
#define TW_MT_DATA_NACK  0x30
#define TW_MR_DATA_ACK   0x50
#define TW_MR_SLA_ACK    0x40


void I2C_master_init(void);
void I2C_start(TU08 address);
void I2C_write(TU08 data);
TU08 I2C_read(void);
void I2C_stop(void);
TU08 I2C_Slave_avialable();
void I2C_Slave_Init(TU08 My_Add);
#endif // I2C_MASTER_H