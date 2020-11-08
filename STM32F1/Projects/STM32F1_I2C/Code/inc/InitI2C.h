#ifndef _INIT_I2C_H_
#define _INIT_I2C_H_

/****
	*	@name		STM32F1_InitI2C
	*	@file 		InitI2C.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		8-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_I2C
	*
*****/


/************************************** Includes **************************************/

#include "stm32f10x.h"
#include "stdint.h"
#include "stdbool.h"


/************************************** Defines ***************************************/

#define f_HCLK		((uint32_t)	72e6)			// Internal AHB clock frequency - 72 MHz.
//#define f_PCLK1		((uint32_t)	f_HCLK / 2)		// Internal APB1 clock frequency - 36 MHz.
#define f_I2C1		((uint32_t)	36e6)			// I2C1 Peripheral Clock Frequency - 2 MHz.
#define I2C1_SPEED	((uint32_t)	100e3)			// Standart speed - 100 kHz.


/********************************* Function  prototypes *******************************/

void InitI2C (void);
void InitI2C1 (void);
void I2C1_WriteDataOnAddress (uint8_t device_address, uint8_t data);

void I2C1_Start (void);
void I2C1_SendAddress (uint8_t device_address, uint8_t RW_mode);
void I2C1_SendByte (uint8_t data);
void I2C1_Stop (void);


#endif /* _INIT_I2C_H_ */
