/****
	*	@name		STM32F1_I2C
	*	@file 		InitI2C.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		8-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_I2C
	*	@info		STM32F10xx8	Datasheet - production data	Datasheet			DocID13587	Rev 17
	*				STM32F10xx8	Reference Manual			Reference Manual	RM0008		Rev 20
	*				STM32F10xx8	I2C peripheral				Errata Sheet		ES096		Rev 14
	*
*****/


/************************************** Includes **************************************/

#include "InitI2C.h"


/************************************** Function **************************************/

void InitI2C (void) {
	InitI2C1 ();
}

void InitI2C1 (void) {
   /*
	*	@brief	This function setup Inter-integrated circuit (I2C) 1 interface.
	*			Configure I2C1 as Master-transmitter. Frequence - 2 MHz. Speed - Standart 100 kHz.
	*	@param	None.
	*	@retval	None.
	*/
	
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN |		// IO port B clock enable.
					RCC_APB2ENR_AFIOEN;			// Alternate Function I/O clock enable.
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;			// I2C 1 clock enable.
	
	/* ********************** PB7 I2C1 SDA ********************** */
	// Output mode, max speed 50 MHz.
	GPIOB->CRL	|= GPIO_CRL_MODE7;
	// Alternate function output Open-drain.
	GPIOB->CRL	|= GPIO_CRL_CNF7;	
	
	/* ********************** PB6 I2C1 SCL ********************** */
	// Output mode, max speed 50 MHz.
	GPIOC->CRL	|= GPIO_CRL_MODE6;
	// Alternate function output Open-drain.
	GPIOC->CRL	|= GPIO_CRL_CNF6;
	
	
	/* ****************************   **************************** */
	I2C1->CR1	&= ~I2C_CR1_PE;					// Peripheral Disable. While setup must be 0.
	
	I2C1->CR1	&= ~I2C_CR1_SMBUS;				// I2C mode.
	I2C1->CR1	|= I2C_CR1_SWRST;				// Reset I2C peripheral.
	I2C1->CR1	&= ~I2C_CR1_SWRST;				// 
	
	I2C1->CR2	= (uint8_t) f_I2C1 * 1e-6;		// Peripheral clock frequency - 36 MHz. Write 36.
	I2C1->CCR	&= ~(I2C_CCR_FS |				// Standart mode I2C.
					I2C_CCR_DUTY);				// Fast Mode Duty Cycle( t_low / t_high = 2).
	I2C1->CCR	|= (I2C1->CR2 & I2C_CR2_FREQ) / // Set the frequency of the SCL module:
					(I2C1_SPEED * 2);			// <=> 180 == 36 MHz / (100 kHz * 2).
	I2C1->TRISE	= (250e-9 * I2C1_SPEED) + 1;	// In Sm mode, the maximum allowed SCL rise time is 1000 ns,
												// take SDA and SCL: rise time 250 ns, fall time 75 ns:
												// <=> 10 == (250 ns / 28 ns) + 1.
	
	I2C1->CR1	|= I2C_CR1_ACK |				// Peripheral Enable.
					I2C_CR1_PE;					// Acknowledge Enable.
}

void I2C1_Start (void) {
	I2C1->CR1	|= I2C_CR1_START;				// Start Generation.
	while (!(I2C1->SR1 & I2C_SR1_SB));			// Start condition generated.
}

void I2C1_SendAddress (uint8_t device_address, uint8_t RW_mode) {
	I2C1->DR	= (device_address | RW_mode);
	while (!(I2C1->SR1 & I2C_SR1_ADDR));		// Address sent (master mode).
	(void) I2C1->SR2;							// Read the SR2 register to clear the SB bit.
}

void I2C1_SendByte (uint8_t data) {
	while(!(I2C1->SR1 & I2C_SR1_TXE));			// Data Register Empty (transmitters).
	I2C1->DR = data;
	while(!(I2C1->SR1 & I2C_SR1_TXE));			// Data Register Empty (transmitters).
}

void I2C1_Stop () {
	I2C1->CR1 |= I2C_CR1_STOP;
}

void I2C1_WriteDataOnAddress (uint8_t device_address, uint8_t data) {
	// START.
	I2C1->CR1	|= I2C_CR1_START;				// Start Generation.
	while (!(I2C1->SR1 & I2C_SR1_SB));			// Start condition generated.
	
	// Send the device address.
	I2C1->DR	= (device_address | 0); 		// 7-bit address of device. Write mode.
	do {         
		if(I2C1->SR1 & I2C_SR1_AF) {
			I2C1->CR1 = I2C_CR1_PE | I2C_CR1_STOP;
			break;
		}
	} while(!(I2C1->SR1 & I2C_SR1_ADDR));		// Address sent (master mode).
	(void) I2C1->SR2;							// Read the SR2 register to clear the SB bit.
	
	// Send data.
	while(!(I2C1->SR1 & I2C_SR1_TXE));			// Data Register Empty (transmitters).
	I2C1->DR = data;
	while(!(I2C1->SR1 & I2C_SR1_TXE));			// Data Register Empty (transmitters).
	
	// STOP.
	while (!((I2C1->SR1 & I2C_SR1_TXE) && 		// Data Register Empty (transmitters).
			(I2C1->SR1 & I2C_SR1_BTF)));		// Data byte transfer succeeded.
	I2C1->CR1 |= I2C_CR1_PE | I2C_CR1_STOP;
}

uint8_t I2C1_Read (uint8_t device_address, uint8_t register_address) {
	uint8_t data = 0;
	
	// Start.
	I2C2->CR1 |= I2C_CR1_START;
	while(!(I2C2->SR1 & I2C_SR1_SB));			// Start Bit (Master mode).
	
	// Send the device address.
	I2C2->DR = device_address;
	while(!(I2C2->SR1 & I2C_SR1_ADDR));			// Address sent (master mode).
	(void) I2C2->SR2;							// Read the SR2 register to clear the SB bit.
	
	// Send the register address.
	I2C2->DR = register_address;
	while(!(I2C2->SR1 & I2C_SR1_TXE));			// Data Register Empty (transmitters).
	I2C2->CR1 |= I2C_CR1_STOP;
	
	// reStart.
	I2C2->CR1 |= I2C_CR1_START;
	while(!(I2C2->SR1 & I2C_SR1_SB));			// Start Bit (Master mode).
	
	// Send the device address.
	I2C2->DR = device_address;
	while(!(I2C2->SR1 & I2C_SR1_ADDR));			// Address sent (master mode).
	(void) I2C2->SR2;							// Read the SR2 register to clear the SB bit.
	
	// Read data.
	I2C2->CR1 &= ~I2C_CR1_ACK;
	while(!(I2C2->SR1 & I2C_SR1_RXNE));			// Data Register not Empty (receivers).
	data = I2C2->DR;
	
	// Stop.
	I2C2->CR1 |= I2C_CR1_STOP;	
	
	return data;
}
