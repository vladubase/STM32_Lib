/****
	*	@name		STM32F1_DMA
	*	@file 		InitDMA.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V0.1
	*	@date 		8-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_DMA
	*
*****/


/************************************** Includes **************************************/

#include "InitDMA.h"


/*********************************** Global varibles **********************************/

uint8_t buffer[] = "I'm DMA\r\n";


/************************************** Function **************************************/

void InitDMA (void) {
	InitDMA_USART1 ();
}

// DMA USART1
void InitDMA_USART1 (void) {
   /*
	*	@brief	This function setup DMA: USART1 as transmitter. Channel 4.
	*	@param	None.
	*	@retval	None.
	*/	
	
	RCC->AHBENR |= RCC_AHBENR_DMA1EN;				// DMA1 clock enable.
	
	DMA1_Channel4->CPAR	= (uint32_t) &USART1->DR;	// Write to...
	DMA1_Channel4->CMAR	= (uint32_t) buffer;		// Write from...
//	DMA1_Channel4->CMAR	= (uint32_t) &buffer[0]; 	// Can be used if the buffer is large.
													// This will improve performance.
													// Used insted of line on the top.
	DMA1_Channel4->CNDTR = 32;						// Size of buffer to send.
	
	DMA1_Channel4->CCR	&= ~DMA_CCR4_CIRC;			// Circular mode disabled.
	DMA1_Channel4->CCR	&= ~DMA_CCR4_PINC;			// Peripheral increment mode disabled.
	
	DMA1_Channel4->CCR	&= ~DMA_CCR4_PSIZE;			// Size of transmitted data - 8-bits.
	DMA1_Channel4->CCR	&= ~DMA_CCR4_MSIZE;			// Size of buffer - 8-bits.
	
	DMA1_Channel4->CCR 	|= DMA_CCR4_DIR;			// Data transfer direction: memory to periphery.
	DMA1_Channel4->CCR 	|= DMA_CCR4_MINC;			// Read from memory - true.
	
	USART1->CR3			|= USART_CR3_DMAT;			// DMA mode is enabled for transmission.
}

void DMA_USART1Write (void) {
	DMA1_Channel4->CCR 	&= ~DMA_CCR4_EN;			// Channel disabled.
	DMA1_Channel4->CNDTR = sizeof (buffer) - 1;
	DMA1->IFCR			|= DMA_IFCR_CTCIF4;			// Transfer Complete clear.
	DMA1_Channel4->CCR 	|= DMA_CCR4_EN;				// Channel enabled.
}
