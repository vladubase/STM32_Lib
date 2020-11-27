/****
	*	@name		STM32F1_FreeRTOS_Tasks
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		1-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/FreeRTOS/STM32F1_FreeRTOS_Tasks
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
	
	// INITIALIZE TASKS
		xTaskCreate (vTaskBlinkPC13, "Blink PC13 when button on PC14 pushed", 32, NULL, 1, NULL);
		
	// START FreeRTOS SHEDULER.
		vTaskStartScheduler ();
	
	// MAIN CYCLE
		while (true) {
			// An error handler.
			// Happens when an unexpected error occurs in the RTOS scheduler,
			// because RTOS should never go into the body of an infinite while.
			// Blink LED PC13 frequently.
			GPIOC->ODR ^= GPIO_ODR_ODR13;
			vTaskDelay (50);
		}
}


/************************************** Functions *************************************/

void vTaskBlinkPC13 (void *arg) {
   /*
	*	@brief	Blink PC13 when button pushed.
	*	@param	None.
	*	@retval	None
	*/
	
	while (true) {
		if (!(GPIOC->IDR & GPIO_IDR_IDR14)) {
			GPIOC->BSRR = GPIO_BSRR_BR13;
			vTaskDelay (100);
			GPIOC->BSRR = GPIO_BSRR_BS13;
			vTaskDelay (100);
		} else {
			GPIOC->BSRR = GPIO_BSRR_BS13;
		}
		vTaskDelay (1);
	}
}
