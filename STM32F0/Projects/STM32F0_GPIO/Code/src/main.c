/****
	*	@name		STM32F0_GPIO
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		11-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib
	*
*****/


/************************************** Include ***************************************/

#include "main.h"


/**************************************** Main ****************************************/

int main (void) {
	// DEFINITION OF VARIABLES
		uint32_t i = 0;
		
	// MICROCONTROLLER INITIALIZATION
		InitRCC ();
		InitSWD ();
		InitGPIO ();
	
	// MAIN CYCLE
		while (true) {
			// If button PB1 pushed - Blink LED PA4.
			if (!(GPIOB->IDR & GPIO_IDR_1)) {
				// Blink LED PC13.
				GPIOC->ODR ^= GPIO_ODR_4;
				for (i = 0; i < 8e5; i++)
					__asm ("nop");
			} else {
				// Continuous light of PA4.
				GPIOC->ODR &= ~GPIO_ODR_4;
			}
		}
}
