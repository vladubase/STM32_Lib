/****
	*	@name		STM32F0_SWD
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		2-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F0/Projects/STM32F0_SWD
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
	
	// MAIN CYCLE
		while (1) {
			
		}
}
