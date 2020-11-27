/****
	*	@name		STM32F1_UART
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		1-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_UART
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
	
	// FREERTOS TASKS
		xTaskCreate (vTaskUSART2SendMessage, "Send message via USART 2", 32, NULL, 1, NULL);
		
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

void vTaskUSART2SendMessage (void *arg) {
   /*
	*	@brief	Send message on USART1 using button.
	*	@param	None.
	*	@retval	None
	*/
	
	
	while (true) {
		USART2SendByte (0x32);				// Send number 2
		
		vTaskDelay (1000);
	} 
}
