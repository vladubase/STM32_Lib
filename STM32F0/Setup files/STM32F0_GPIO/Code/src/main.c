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
	
	// MAIN CYCLE
		while (true) {
			// If button pushed (PB1) (pull-up to 3.3V) - Turn ON LED PA4.
			if (!(GPIOB->IDR & GPIO_IDR_1)) {
				GPIOA->BSRR |= GPIO_BSRR_BS_4;
			} else {
				GPIOA->BSRR |= GPIO_BSRR_BR_4;
			}
		}
}
