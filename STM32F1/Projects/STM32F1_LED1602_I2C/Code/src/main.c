/****
	*	@name		STM32F1_STM32F1_I2C
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		8-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_I2C
	*
*****/


/************************************** Include ***************************************/

#include "main.h"
 

/**************************************** Main ****************************************/

int main (void) {
	// DEFINITION OF VARIABLES
//		uint32_t i = 0;
	
	// MICROCONTROLLER INITIALIZATION
		InitRCC ();
		InitSWD ();
		InitGPIO ();
		InitI2C ();
	
	// MAIN CYCLE
		while (1) {
			I2C1_WriteDataOnAddress (0x4E, 'A');
			GPIOC->ODR ^= GPIO_ODR_ODR13;
		}
}
