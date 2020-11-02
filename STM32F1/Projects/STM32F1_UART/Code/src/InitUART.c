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
	InitUSART2 ();
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

void USART1_IRQHandler (void) {
	// Read data register not empty.
	if (USART1->SR & USART_SR_RXNE) {
		USART1->SR &= ~USART_SR_RXNE;			// Clear flag.
		
		if (USART1->DR == '0') {
			// LED PC13 off
			USART1SendString ("LED OFF\r\n");
			GPIOC->BSRR = GPIO_BSRR_BS13;
		}
		if (USART1->DR == '1') {
			// LED PC13 on
			USART1SendString ("LED ON\r\n");
			GPIOC->BSRR = GPIO_BSRR_BR13;
		}
	}
}

/************************************** USART 2 ***************************************/

void InitUSART2 (void) {
   /*
	*	@brief	This function setup USART.
	*	@param	None.
	*	@retval	None.
	*/
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |		// GPIOA clock enable.
					RCC_APB2ENR_AFIOEN;			// AFIO clock enable.
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;		// USART2 clock enable.
	
	/* ************************** PA3 RX ************************* */
	// Input mode (reset state).
	GPIOA->CRL &= ~GPIO_CRL_MODE3;
	
	// Floating input (reset state).
	GPIOA->CRL |= GPIO_CRL_CNF3_0;

	/* ************************** PA2  TX ************************ */
	// Output mode, max speed 50 MHz.
	GPIOA->CRL |= GPIO_CRL_MODE2;
	
	// Input with pull-up / pull-down
	GPIOA->CRL |= GPIO_CRL_CNF2_1;
	
	/* ************************* Baud rate *********************** */
	// 
	USART2->BRR = (APB1_PERIPH_CLOCK + USART2_BAUDRATE / 2) / USART2_BAUDRATE;
	
	/* *********************************************************** */
	// 
	USART2->CR1 |= USART_CR1_RE |				// Receiver Enable.
				   USART_CR1_TE |				// Transmitter Enable.
				   USART_CR1_UE;				// USART Enable.
	
	/* ********************** USART2 Interrupt ******************* */
	// A USART interrupt is generated whenever ORE=1 or 
	// RXNE=1 in the USART_SR register.
	USART2->CR1 |= USART_CR1_RXNEIE;			// RXNE interrupt enable.
	NVIC_EnableIRQ (USART2_IRQn);
}

void USART2SendByte (char chr) {
	// Wait Transmission complete flag.
	while (!(USART2->SR & USART_SR_TC));
	
	USART2->DR = chr;
}

void USART2SendString (char* str) {
	uint8_t i = 0;
	
	while (str[i]) {
		USART2SendByte (str[i++]);
	}
}

void USART2_IRQHandler (void) {
	// Read data register not empty.
	if (USART2->SR & USART_SR_RXNE) {
		USART2->SR &= ~USART_SR_RXNE;			// Clear flag.
		
		if (USART2->DR == '0') {
			// LED PC13 off
			USART2SendString ("LED OFF\r\n");
			GPIOC->BSRR = GPIO_BSRR_BS13;
		}
		if (USART2->DR == '1') {
			// LED PC13 on
			USART2SendString ("LED ON\r\n");
			GPIOC->BSRR = GPIO_BSRR_BR13;
		}
	}
}
