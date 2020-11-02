/****
	*	@name		STM32F1_TIM
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		1-November-2020
	*
*****/


/************************************** Include ***************************************/

#include "main.h"
 

/**************************************** Main ****************************************/

int main (void) {
	// DEFINITION OF VARIABLES
		
	
	// MICROCONTROLLER INITIALIZATION
		InitRCC ();
//		InitMCO ();
		InitSWD ();
		InitGPIO ();
		InitTIM ();
	
	// FREERTOS TASKS
		xTaskCreate (vTaskDimmingLED, "Dimming LED on A0", 32, NULL, 1, NULL);
		
	// Start FreeRTOS Sheduler.
	// RTOS should never go into the body of an infinite while.
		vTaskStartScheduler ();
	
	// MAIN CYCLE
		while (true) {
			// An error handler.
			// Happens when an unexpected error occurs in the RTOS scheduler.
			// Blink LED PC13.
			GPIOC->ODR ^= GPIO_ODR_ODR13;
			vTaskDelay (50);
		}
}


/************************************** Functions *************************************/

void vTaskDimmingLED (void *arg) {
   /*
	*	@brief	None.
	*	@param	None.
	*	@retval	None.
	*/
	
	uint16_t i = 0;	
	
	while (true) {
		for (i = 0; i < TIM2_ARR; i++) {
			TIM2->CCR1 = i;						// CH1 duty cycle.
			vTaskDelay (5);
		}
	} 
}
