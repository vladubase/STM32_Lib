/****
	*	@name		STM32F1_RCC_PLL_72MHz
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		30-October-2020
	*
*****/


/************************************** Include ***************************************/

#include "main.h"
 

/**************************************** Main ****************************************/

int main (void) {
	// DEFINITION OF VARIABLES
		
	
	// MICROCONTROLLER INITIALIZATION
		InitRCC ();
//		InitMCO ();
		InitSWD ();
	
	// MAIN CYCLE
		while (1) {
			
		}
}
