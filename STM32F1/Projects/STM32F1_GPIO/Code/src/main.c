/****
	*	@name		STM32F1_GPIO
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		31-October-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_GPIO
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
		while (1) {
			// If button pushed - Blink LED PC13.
			if ((GPIOC->IDR & GPIO_IDR_IDR14) == 0) {
				// Blink LED PC13.
				GPIOC->ODR ^= GPIO_ODR_ODR13;
				for (i = 0; i < 8e5; i++)
					__ASM ("nop");
			} else {
				// Continuous light of PC13.
				GPIOC->ODR &= ~GPIO_ODR_ODR13;
			}
		}
}
