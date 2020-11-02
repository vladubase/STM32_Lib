/****
	*	@name		STM32F1_FreeRTOS_Queues
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
		InitUART ();
	
	// MAIN ALGORITHM
		xTaskCreate (vTaskUSART2SendMessage, "vTaskUSART2SendMessage", 32, NULL, 1, NULL);
		xTaskCreate (vTaskUSART2ReceiveMessage, "vTaskUSART2ReceiveMessage", 32, NULL, 1, NULL);
	
	// QUEUE MANAGMENT
		SendData = xQueueCreate (5, sizeof (uint8_t));
		
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

void vTaskUSART2ReceiveMessage (void *arg) {
   /*
	*	@brief	vTaskUSART2ReceiveMessage.
	*	@param	None.
	*	@retval	None
	*/
	
	uint8_t data = 0;
	
	while (true) {
		if (uxQueueMessagesWaiting(SendData)) {
			xQueueReceive(SendData, &data, 0);
			USART2SendByte (data);
		}
		
		vTaskDelay (200);
	} 
}

void vTaskUSART2SendMessage (void *arg) {
   /*
	*	@brief	vTaskUSART2SendMessage.
	*	@param	None.
	*	@retval	None
	*/
	
	uint16_t i = 30;							// 30th symbol in ASCII Table.
	
	while (true) {
		i++;									// Every iteration send next ASCII symbol.
		xQueueSend(SendData, &i, 0);
		
		vTaskDelay (1000);						// Send i every 1000ms.
	}
}
