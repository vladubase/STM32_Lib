/**
*	@name		STM32F0_PROJECT
*	@file 		main.c
*
*	@author 	Uladzislau 'vladubase' Dubatouka
*				<vladubase@gmail.com>.
*	@version	V1.0
*	@date 		11-January-2021
*	@link		https://github.com/vladubase/STM32_Lib
*
*/


/************************************** Include ***************************************/

#include "main.h"


/**************************************** Main ****************************************/

int main (void) {
	// DEFINITION OF VARIABLES
		
		
	// MICROCONTROLLER INITIALIZATION
		InitRCC ();
		InitSWD ();
		InitGPIO ();
		InitUSART1 ();
	
	// MAIN CYCLE
		while (1) {
			USART1_SendByte (0x32);				// Send number 2.
		}
}


/************************************* Interrupts *************************************/

void USART1_IRQHandler (void) {
/*
*	@brief	This function set LED turns ON if USART1 receive '1'.
*			A response is sent like "LED ON" - current LED status.
*/
	// Read data register not empty.
	if (USART1->ISR & USART_ISR_RXNE) {
		USART1->ISR &= ~USART_ISR_RXNE;			// Clear flag.
		
		if (USART1->RDR == '0') {
			// LED PA4 off.
			USART1_SendString ("LED OFF\r\n");
			GPIOA->BSRR |= GPIO_BSRR_BS_4;
		}
		if (USART1->RDR == '1') {
			// LED PA4 on.
			USART1_SendString ("LED ON\r\n");
			GPIOA->BSRR |= GPIO_BSRR_BR_4;
		}
	}
}
