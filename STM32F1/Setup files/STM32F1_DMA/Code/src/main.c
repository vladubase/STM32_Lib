/****
	*	@name		STM32F1_DMA
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V0.1
	*	@date 		8-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_DMA
	*
*****/


/************************************** Include ***************************************/

#include "main.h"
 

/**************************************** Main ****************************************/

int main (void) {
	// DEFINITION OF VARIABLES
		
	
	// MICROCONTROLLER INITIALIZATION
		InitRCC ();
		InitSWD ();
		InitGPIO ();
		InitUART ();
		InitDMA ();
	
	// FREERTOS TASKS
		xTaskCreate (vTaskDMAtoUART, "DMA", 32, NULL, 1, NULL);
		
	// Start FreeRTOS Sheduler.
		vTaskStartScheduler ();
	
	// MAIN CYCLE
		while (true) {
			// An error handler.
			// Happens when an unexpected error occurs in the RTOS scheduler,
			// because RTOS should never go into the body of an infinite while.
			// Blink LED PC13.
			GPIOC->ODR ^= GPIO_ODR_ODR13;
			vTaskDelay (50);
		}
}


/************************************** Functions *************************************/

void vTaskDMAtoUART (void *arg) {
	while (true) {
		DMA_USART1Write ();
		
		GPIOC->ODR ^= GPIO_ODR_ODR13;
		vTaskDelay (1000);
	}
}


/************************************** Interrupts ************************************/

void USART1_IRQHandler (void) {
	// Read data register not empty.
	if (USART1->SR & USART_SR_RXNE) {
		
	}
}
