/****
	*	@name		STM32F4_MCO
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		10-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F4/Projects/STM32F4_MCO
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
		InitMCO ();
	
	// MAIN CYCLE
		while (1) {
			
		}
}