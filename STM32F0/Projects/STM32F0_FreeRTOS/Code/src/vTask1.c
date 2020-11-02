/****
	*	@name		STM32F0_FreeRTOS
	*	@file 		vTask1.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		30-October-2020
	*
*****/


/************************************** Includes **************************************/

#include "vTask1.h"


/************************************** Function **************************************/

void vTask1 (void *arg) {
   /*
	*	@brief	FreeRTOS task.
	*	@param	None.
	*	@retval	None.
	*/
	
	while (true) {
		
		
		vTaskDelay (1);
	}
}
