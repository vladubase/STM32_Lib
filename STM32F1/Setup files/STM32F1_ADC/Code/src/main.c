/****
	*	@name		STM32F1_ADC
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		2-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_ADC
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
		InitUSART1 ();
		InitADC1CH1 ();
	
	// MAIN ALGORITHM
		xTaskCreate (vTaskADCConversion, "vTaskADCConversion", 128, NULL, 1, NULL);
		xTaskCreate (vTaskUSART1SendData, "vTaskUSART1SendData", 128, NULL, 1, NULL);
	
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

void vTaskADCConversion (void *arg) {
   /*
	*	@brief	Read ADC value from register.
	*	@param	None.
	*	@retval	None.
	*/
	
	uint16_t ADC_result;
	
	while (true) {		
		ADC_result = ADC1StartConvertion ();
		
		xQueueSend(SendDataADC, &ADC_result, 0);
		
		GPIOC->ODR ^= GPIO_ODR_ODR13;
		
		vTaskDelay (1000);
	} 
}

void vTaskUSART1SendData (void *arg) {	
   /*
	*	@brief	Send value of ADC ang voltage via USART1.
	*	@param	None.
	*	@retval	None.
	*/
	
	uint16_t ADC_result;
	char ADC_result_str[5] = {0};
	
	char ADC_voltage_str[5] = {0};
	
	while (true) {
		xQueueReceive(SendDataADC, &ADC_result, 0);
		
		// Convert value of ADC to char*.
		sprintf (ADC_result_str, "%u", ADC_result);
		sprintf (ADC_voltage_str, "%.3f", ADC_result * ADC_STEP_VOLTS);
		
		// Send ADC value.
		USART1SendString ("ADC value: ");
		USART1SendString (ADC_result_str);
		USART1SendString ("\r\n");
		
		// Send Voltage.
		USART1SendString ("Voltage: ");
		USART1SendString (ADC_voltage_str);
		USART1SendString (" V\r\n");
		
		USART1SendString ("\r\n");
			
				
		vTaskDelay (1000);
	}
}


/************************************* Interrupts *************************************/

void USART1_IRQHandler (void) {
	// Read data register not empty.
	if (USART1->SR & USART_SR_RXNE) {
		USART1->SR &= ~USART_SR_RXNE;			// Clear flag.
		
		if (USART1->DR == '0') {
			// LED PC13 off.
			USART1SendString ("LED OFF\r\n");
			GPIOC->BSRR = GPIO_BSRR_BS13;
		}
		if (USART1->DR == '1') {
			// LED PC13 on.
			USART1SendString ("LED ON\r\n");
			GPIOC->BSRR = GPIO_BSRR_BR13;
		}
	}
}


void USART2_IRQHandler (void) {
	// Read data register not empty.
	if (USART2->SR & USART_SR_RXNE) {
		USART2->SR &= ~USART_SR_RXNE;			// Clear flag.
		
		if (USART2->DR == '0') {
			// LED PC13 off
			USART2SendString ("LED OFF\r\n");
			GPIOC->BSRR = GPIO_BSRR_BS13;
		}
		if (USART2->DR == '1') {
			// LED PC13 on
			USART2SendString ("LED ON\r\n");
			GPIOC->BSRR = GPIO_BSRR_BR13;
		}
	}
}
