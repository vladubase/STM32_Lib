/*******************************************************************************
 *	@name		STM32F4_ADC
 *	@file 		main.c
 *
 *	@author 	Uladzislau 'vladubase' Dubatouka
 *				<vladubase@gmail.com>.
 *	@version	V1.0
 *	@date 		21-July-2021
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
	InitUART ();
	
	USART1_SendString ("\n=-----------------------------------=\n");
	USART1_SendString ("Hello!\n");
	USART1_SendString ("Send '1' to turn LED ON\n");
	USART1_SendString ("Send '0' to turn LED OFF\n");
	USART1_SendString ("=-----------------------------------=\n\n");
	
	// MAIN CYCLE
	while (true) {
		
	}
}


/********************************* Interrupts *********************************/

void USART1_IRQHandler (void) {
/*
*	@brief	This function set LED turns ON if USART1 receive '1'.
*			A response is sent like "LED ON" - current LED status.
*/
	if (USART1->SR & USART_SR_RXNE) {			// Read data register not empty.
		USART1->SR &= ~USART_SR_RXNE;			// Clear flag.
		
		if (USART1->DR == '1') {
			// LED PC14 on.
			USART1_SendString ("LED ON\r\n");
			GPIOC->BSRRH |= GPIO_BSRR_BS_13;
		} else if (USART1->DR == '0') {
			// LED PC13 off.
			USART1_SendString ("LED OFF\r\n");
			GPIOC->BSRRL |= GPIO_BSRR_BS_13;
		}
	}
}
