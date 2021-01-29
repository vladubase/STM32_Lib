/**
*	@name		STM32F0_PROJECT
*	@file 		main.c
*
*	@author 	Uladzislau 'vladubase' Dubatouka
*				<vladubase@gmail.com>.
*	@version	V1.0
*	@date 		29-January-2021
*	@link		https://github.com/vladubase/STM32_Lib
*
*/


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
		InitTIM ();
	
	// MAIN CYCLE
		while (true) {
			// Pulse every 1 ms.
			TIM14->CCR1 = 500;						// CH1 duty cycle.
		}
}
