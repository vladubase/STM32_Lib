/****
	*	@name		STM32F1_UART
	*	@file 		InitUART.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		1-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_UART
	*
*****/


/************************************** Includes **************************************/

#include "InitUART.h"


/************************************* Functions **************************************/

void InitUART (void) {
	InitUSART1 ();
}


/************************************** USART 1 ***************************************/

void InitUSART1 (void) {
   /*
	*	@brief	This function setup USART.
	*	@param	None.
	*	@retval	None.
	*/
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |		// GPIOA clock enable.
					RCC_APB2ENR_USART1EN |		// USART1 clock enable.
					RCC_APB2ENR_AFIOEN;			// AFIO clock enable.
	
	/* ************************** PA10 RX ************************ */
	// Input mode (reset state).
	GPIOA->CRH &= ~GPIO_CRH_MODE10;
	
	// Floating input (reset state).
	GPIOA->CRH |= GPIO_CRH_CNF10_0;

	/* ************************** PA9  TX ************************ */
	// Output mode, max speed 50 MHz.
	GPIOA->CRH |= GPIO_CRH_MODE9;
	
	// Input with pull-up / pull-down
	GPIOA->CRH |= GPIO_CRH_CNF9_1;
	
	/* ************************* Baud rate *********************** */
	// 
	USART1->BRR = (APB2_PERIPH_CLOCK + USART1_BAUDRATE / 2) / USART1_BAUDRATE;
	
	/* *********************************************************** */
	// 
	USART1->CR1 |= USART_CR1_RE |				// Receiver Enable.
				   USART_CR1_TE |				// Transmitter Enable.
				   USART_CR1_UE;				// USART Enable.
	
	/* ********************** USART1 Interrupt ******************* */
	// A USART interrupt is generated whenever ORE=1 or 
	// RXNE=1 in the USART_SR register.
	USART1->CR1 |= USART_CR1_RXNEIE;			// RXNE interrupt enable.
	NVIC_EnableIRQ (USART1_IRQn);
}

void USART1SendByte (char chr) {
	// Wait Transmission complete flag.
	while (!(USART1->SR & USART_SR_TC));
	
	USART1->DR = chr;
}

void USART1SendString (char* str) {
	uint8_t i = 0;
	
	while (str[i]) {
		USART1SendByte (str[i++]);
	}
}
