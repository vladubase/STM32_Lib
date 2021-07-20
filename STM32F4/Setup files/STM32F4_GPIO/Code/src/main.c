/*******************************************************************************
 *	@name		STM32F4_GPIO
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
	InitGPIO ();
	
	// MAIN CYCLE
	while (true) {
		// If button pushed (KEY, PA0) - Turn ON LED PC13.
		if (!(GPIOA->IDR & GPIO_IDR_IDR_0)) {
			GPIOC->BSRRH |= GPIO_BSRR_BS_13;			
		} else		
			GPIOC->BSRRL |= GPIO_BSRR_BS_13;
	}
}
