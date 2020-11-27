/**
*	@name		STM32F0_PROJECT
*	@file 		main.c
*
*	@author 	Uladzislau 'vladubase' Dubatouka
*				<vladubase@gmail.com>.
*	@version	V1.0
*	@date 		14-November-2020
*	@link		https://github.com/vladubase/STM32_Lib
*
*/


/************************************** Include ***************************************/

#include "main.h"


/**************************************** Main ****************************************/

int main (void) {
	// DEFINITION OF VARIABLES
		uint32_t i = 0;
		uint32_t delay = 0;
	
	// MICROCONTROLLER INITIALIZATION
		InitRCC ();
		InitSWD ();
		InitGPIO ();
		InitTIM ();
	
	// MAIN CYCLE
		while (true) {
			// Dimming LED on A4.
			for (i = 0; i < TIM1_ARR; i++) {
				TIM2->CCR1 = i;						// CH1 duty cycle.
			}
			
			// Delay 5 ms.
			for (delay = 0; delay < 240e3; delay++) {
				__asm ("nop");
			}
		}
}
