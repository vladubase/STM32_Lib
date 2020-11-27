/****
	*	@name		STM32F1_DAC
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		3-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_DAC
	*
	*	@attention	Note that the DAC is only available on STM32F10X_HD or STM32F10X_CL.
	*				To find out your version see Datasheet.
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
		InitDAC ();								// See @attention.
	
	// MAIN ALGORITHM
		xTaskCreate (vTaskDACOut, "DAC", 32, NULL, 1, NULL);
	
	// QUEUE MANAGMENT
		SendDataADC = xQueueCreate (5, sizeof (uint16_t));
		
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

void vTaskDACOut (void *arg) {
   /*
	*	@brief	Generate Sinus.
	*	@param	None.
	*	@retval	None.
	*/
	
	uint16_t i;
	const uint16_t sin[32] = {
		0, 38, 155, 344, 599, 909, 1263, 1647, 
		2047, 2447, 2831, 3185, 3498, 3750, 3939, 4056,
		4095, 4056, 3939, 3750, 3498, 3185, 2831, 2447,
		2047, 1647, 1263, 909, 599, 344, 155, 38
	};
	
	while (true) {
		DACWrite (sin[i++]);
		
		if (i == sizeof (sin)) {
			i = 0;
		}
		
		vTaskDelay (10);
	}
}
