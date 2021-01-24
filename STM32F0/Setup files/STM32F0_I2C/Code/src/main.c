/****
	*	@name		STM32F0_GPIO
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.1
	*	@date 		10-January-2021
	*	@link		https://github.com/vladubase/STM32_Lib
	*
*****/


/************************************** Include ***************************************/

#include "main.h"


/**************************************** Main ****************************************/

int main (void) {
	// DEFINITION OF VARIABLES
		
		
	// MICROCONTROLLER INITIALIZATION
		InitRCC ();
		InitSWD ();
		InitGPIO ();
		InitI2C ();
	
	// MAIN CYCLE
		while (true) {
			if ((I2C2->ISR & I2C_ISR_TXE) == I2C_ISR_TXE) {
				I2C2->TXDR = 'h'; /* Byte to send */
				I2C2->CR2 |= I2C_CR2_START; /* Go */
			}
		}
}
