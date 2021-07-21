/*******************************************************************************
 *	@name		STM32F4_ADC
 *	@file 		main.c
 *
 *	@author 	Uladzislau 'vladubase' Dubatouka
 *				<vladubase@gmail.com>.
 *	@version	V1.0
 *	@date 		21-July-2021
 ******************************************************************************/

#include "main.h"


/************************************ Main ************************************/


int main (void) {
	// DEFINITION OF VARIABLES
	uint16_t ADC_result = 0;
	char ADC_result_str[5] = {0};	
	char ADC_voltage_str[5] = {0};	
	
	// MICROCONTROLLER INITIALIZATION
	InitSystem ();
	InitRCC ();
	InitSWD ();
	InitGPIO ();
	InitUSART1 ();
	InitADC1CH1 ();
	
	// MAIN CYCLE
	while (true) {
		// If button pushed (KEY, PA0) - Start ADC Conversion.
		if (!(GPIOA->IDR & GPIO_IDR_IDR_0)) {
			USART1_SendString ("\n=-----------------------------------=\n");
			USART1_SendString ("        ADC IN1 PA1\n");
			USART1_SendString ("Starting conversion\n");
			GPIOC->BSRRH |= GPIO_BSRR_BS_13;				// LED PC13 on.
			
			ADC_result = ADC1_StartConversion ();			// Get data from ADC.
			// Convert value of ADC to char*.
			sprintf (ADC_result_str, "%u", ADC_result);
			sprintf (ADC_voltage_str, "%.3f", ADC_result * ADC1_LSB);
			
			// Send ADC value.
			USART1_SendString ("    ADC value:   ");
			USART1_SendString (ADC_result_str);
			USART1_SendString ("\n");
			
			// Send Voltage.
			USART1_SendString ("    Voltage:        ");
			USART1_SendString (ADC_voltage_str);
			USART1_SendString (" V\n\n");
			
			delay_ms (25e6);
		} else		
			GPIOC->BSRRL |= GPIO_BSRR_BS_13;				// LED PC13 off.
	}
}
