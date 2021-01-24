#ifndef _INIT_I2C_H_
#define _INIT_I2C_H_

/****
	*	@name		STM32F0_I2C
	*	@file 		InitI2C.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		24-January-2021
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F0/Projects/STM32F0_I2C
	*
*****/


/************************************** Includes **************************************/

#include "stm32f0xx.h"
#include "stdint.h"
#include "stdbool.h"
#include "stm32f0xx.h"


/************************************** Defines ***************************************/

#define f_HCLK		((uint32_t)	48e6)			// Internal AHB clock frequency - 48 MHz.
#define f_I2C		((uint32_t)	48e6)			// I2C1 Peripheral Clock Frequency - 2 MHz.
#define I2C1_SPEED	((uint32_t)	100e3)			// Standart speed - 100 kHz.


/********************************* Function  prototypes *******************************/

void InitI2C (void);
void I2C_WriteDataOnAddress (uint8_t device_address, uint8_t data);

void I2C_Start (void);
void I2C_SendAddress (uint8_t device_address, uint8_t RW_mode);
void I2C_SendByte (uint8_t data);
void I2C_Stop (void);


#endif /* _INIT_I2C_H_ */
