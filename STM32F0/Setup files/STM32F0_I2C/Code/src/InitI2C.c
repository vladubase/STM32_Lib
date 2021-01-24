/****
	*	@name		STM32F0_I2C
	*	@file 		InitI2C.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		24-January-2021
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F0/Projects/STM32F0_I2C
	*	@info		STM32F030x	Datasheet - production data	Datasheet			'F030xx'	Rev 3
	*				STM32F030x	Reference Manual			Reference Manual	RM0360		Rev 4
	*				STM32F030x	I2C peripheral				Errata Sheet		ES0219		Rev 5
	*				I2C-bus specification and user manual	User Manual			UM10204		Rev 6
	*				I2C_Timing_Configuration_V1.0.1			Excel Table			(AN4235)	Rev 1.0.1
	*
*****/


/************************************** Includes **************************************/

#include "InitI2C.h"


/************************************** Function **************************************/

void InitI2C (void) {
   /*
	*	@brief	This function setup Inter-integrated circuit (I2C) 1 interface.
	*			Configure I2C as Master-transmitter. Frequence - 48 MHz. Standart Speed 100 kHz.
	*			Analog Filter Delay, Rise time 100ns.
	*/
	
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;			// GPIOA clock enable.
	
	
	/* *********************** PA9 I2C SCL *********************** */
	
	// Alternate function mode.
	GPIOA->MODER |= GPIO_MODER_MODER9_1;
	
	// Output open-drain.
	GPIOA->OTYPER |= GPIO_OTYPER_OT_9;
	
	// High speed.
	// @note	Refer to the device datasheet.
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;
	
	// No pull-up, pull-down.
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR9;
	
	
	/* *********************** PA10 I2C SDA ********************** */
	
	// Alternate function mode.
	GPIOA->MODER |= GPIO_MODER_MODER10_1;
	
	// Output open-drain.
	GPIOA->OTYPER |= GPIO_OTYPER_OT_10;
	
	// High speed.
	// @note	Refer to the device datasheet.
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10;
	
	// No pull-up, pull-down.
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR10;

	/* ****************************   **************************** */
	
	I2C1->TIMINGR = (uint32_t) 0x10805E89;
	I2C1->CR1 = (uint32_t) I2C_CR1_PE;			// Peripheral enable.
	I2C1->CR2 = I2C_CR2_AUTOEND | 				// Automatic end mode.
		(1 << 16) | 							// 1 byte to transmit.
		(I2C_CR2_SADD << 1);					// Slave address = 0x5A, write transfer.
}

//void I2C_Start (void) {
//	I2C1->CR2	|= I2C_CR2_START;				// Start Generation.
//	while (!(I2C1->SR1 & I2C_SR1_SB));			// Start condition generated.
//}

//void I2C_SendAddress (uint8_t device_address, uint8_t RW_mode) {
//	I2C1->DR = (device_address | RW_mode);
//	while (!(I2C1->SR1 & I2C_SR1_ADDR));		// Address sent (master mode).
//	(void) I2C1->SR2;							// Read the SR2 register to clear the SB bit.
//}

//void I2C_SendByte (uint8_t data) {
//	while(!(I2C1->SR1 & I2C_SR1_TXE));			// Data Register Empty (transmitters).
//	I2C1->DR = data;
//	while(!(I2C1->SR1 & I2C_SR1_TXE));			// Data Register Empty (transmitters).
//}

//void I2C_Stop () {
//	I2C1->CR2 |= I2C_CR2_STOP;
//}

//void I2C_WriteDataOnAddress (uint8_t device_address, uint8_t data) {
//	// START.
//	I2C1->CR1	|= I2C_CR1_START;				// Start Generation.
//	while (!(I2C1->SR1 & I2C_SR1_SB));			// Start condition generated.
//	
//	// Send the device address.
//	I2C1->DR	= (device_address | 0); 		// 7-bit address of device. Write mode.
//	do {         
//		if(I2C1->SR1 & I2C_SR1_AF) {
//			I2C1->CR1 = I2C_CR1_PE | I2C_CR1_STOP;
//			break;
//		}
//	} while(!(I2C1->SR1 & I2C_SR1_ADDR));		// Address sent (master mode).
//	(void) I2C1->SR2;							// Read the SR2 register to clear the SB bit.
//	
//	// Send data.
//	while(!(I2C1->SR1 & I2C_SR1_TXE));			// Data Register Empty (transmitters).
//	I2C1->DR = data;
//	while(!(I2C1->SR1 & I2C_SR1_TXE));			// Data Register Empty (transmitters).
//	
//	// STOP.
//	while (!((I2C1->SR1 & I2C_SR1_TXE) && 		// Data Register Empty (transmitters).
//			(I2C1->SR1 & I2C_SR1_BTF)));		// Data byte transfer succeeded.
//	I2C1->CR1 |= I2C_CR1_PE | I2C_CR1_STOP;
//}

//uint8_t I2C_Read (uint8_t device_address, uint8_t register_address) {
//	uint8_t data = 0;
//	
//	// Start.
//	I2C2->CR1 |= I2C_CR1_START;
//	while(!(I2C2->SR1 & I2C_SR1_SB));			// Start Bit (Master mode).
//	
//	// Send the device address.
//	I2C2->DR = device_address;
//	while(!(I2C2->SR1 & I2C_SR1_ADDR));			// Address sent (master mode).
//	(void) I2C2->SR2;							// Read the SR2 register to clear the SB bit.
//	
//	// Send the register address.
//	I2C2->DR = register_address;
//	while(!(I2C2->SR1 & I2C_SR1_TXE));			// Data Register Empty (transmitters).
//	I2C2->CR1 |= I2C_CR1_STOP;
//	
//	// reStart.
//	I2C2->CR1 |= I2C_CR1_START;
//	while(!(I2C2->SR1 & I2C_SR1_SB));			// Start Bit (Master mode).
//	
//	// Send the device address.
//	I2C2->DR = device_address;
//	while(!(I2C2->SR1 & I2C_SR1_ADDR));			// Address sent (master mode).
//	(void) I2C2->SR2;							// Read the SR2 register to clear the SB bit.
//	
//	// Read data.
//	I2C2->CR1 &= ~I2C_CR1_ACK;
//	while(!(I2C2->SR1 & I2C_SR1_RXNE));			// Data Register not Empty (receivers).
//	data = I2C2->DR;
//	
//	// Stop.
//	I2C2->CR1 |= I2C_CR1_STOP;	
//	
//	return data;
//}
