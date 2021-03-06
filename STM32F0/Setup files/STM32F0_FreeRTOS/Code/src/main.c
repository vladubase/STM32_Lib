/****
	*	@name		STM32F0_FreeRTOS
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		31-October-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F0/Projects/STM32F0_FreeRTOS
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
	
	// FREERTOS TASKS
		xTaskCreate (vTask1, "Name of Task 1", 32, NULL, 1, NULL);
		xTaskCreate (vTask2, "Name of Task 2", 32, NULL, 1, NULL);
		
	// START FreeRTOS SHEDULER.
		vTaskStartScheduler ();
	
	// MAIN CYCLE
		while (true) {
			// An error handler, such as a blinking ErrorLED, because
			// RTOS should never go into the body of an infinite while.
			// Happens when an unexpected error occurs in the RTOS scheduler.
			
		}
}


/************************************** Functions *************************************/

void vTask1 (void *arg) {
   /*
	*	@brief	FreeRTOS task1.
	*	@param	None.
	*	@retval	None.
	*/
	
	while (true) {
		
		
		vTaskDelay (1);
	}
}

void vTask2 (void *arg) {
   /*
	*	@brief	FreeRTOS task2.
	*	@param	None.
	*	@retval	None.
	*/
	
	while (true) {
		
		
		vTaskDelay (1);
	}
}
