/*******************************************************************************
 *	@name		STM32F4_MCO
 *	@file 		main.c
 *
 *	@author 	Uladzislau 'vladubase' Dubatouka
 *				<vladubase@gmail.com>.
 *	@version	V1.0
 *	@date 		20-July-2021
 ******************************************************************************/

#include "main.h"


/************************************ Main ************************************/


int main (void) {
	// DEFINITION OF VARIABLES
	
	
	// MICROCONTROLLER INITIALIZATION
	InitSystem ();
	InitRCC ();
	InitSWD ();
	InitMCO ();
	
	// MAIN CYCLE
	while (true) {
		
	}
}
