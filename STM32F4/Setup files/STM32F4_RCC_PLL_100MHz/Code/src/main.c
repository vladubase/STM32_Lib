/*******************************************************************************
 *	@name		STM32F4_RCC_PLL_100MHz
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
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER13_0;		// 0b01:	General purpose output mode.
	GPIOC->OTYPER &= ~GPIO_OTYPER_OT_13;		// 0b00:	Output push-pull (reset state).
	GPIOC->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR13;	// 0b00:	Low speed.
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR13;		// 0b00:	No pull-up, pull-down.
	
	// MAIN CYCLE
	while (true) {
		GPIOC->BSRRL |= GPIO_BSRR_BS_13;
		delay_ms (5e6);
		GPIOC->BSRRH |= GPIO_BSRR_BS_13;
		delay_ms (5e6);
	}
}
