/**
*	@name		STM32F0_UART
*	@file 		InitUART.c
*
*	@author 	Uladzislau 'vladubase' Dubatouka
*				<vladubase@gmail.com>
*	@version	V1.1
*	@date 		12-November-2020
*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F0/Projects/STM32F0_UART
*
*/


/************************************** Includes **************************************/

#include "InitUART.h"


/************************************* Functions **************************************/

void InitUART (void) {
	InitUSART1 ();
}


/************************************** USART 1 ***************************************/

void InitUSART1 (void) {
/**
*	@brief	This function setup USART 1.
*	@param	None.
*	@retval	None.
*/
	
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;			// GPIOA clock enable.
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;		// USART1 clock enable.
	
	/* ************************** PA10 RX ************************ */
	// Alternate function mode.
	GPIOA->MODER |= GPIO_MODER_MODER10_1;
	
	// High speed.
	// @note	Refer to the device datasheet.
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10;
	
	// Output push-pull (reset state).
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_9;
	
	// No pull-up, pull-down.
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR10;

	/* ************************** PA9  TX ************************ */
	// Alternate function mode.
	GPIOA->MODER |= GPIO_MODER_MODER9_1;
	
	// High speed.
	// @note	Refer to the device datasheet.
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10;
	
	// Output push-pull (reset state).
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_9;
	
	// No pull-up, pull-down.
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR10;
	
	/* ************************* Baud rate *********************** */
	// 
	USART1->BRR = (f_AHB + USART1_BAUDRATE / 2) / USART1_BAUDRATE;
	
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

void USART1_SendByte (char chr) {
	// Wait Transmission complete flag.
	while (!(USART1->ISR & USART_ISR_TC));
	
	USART1->RDR = chr;
}

void USART1_SendString (char* str) {
	uint8_t i = 0;
	
	while (str[i]) {
		USART1_SendByte (str[i++]);
	}
}
