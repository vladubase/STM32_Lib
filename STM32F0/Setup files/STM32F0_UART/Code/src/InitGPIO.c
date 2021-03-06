/**
*	@file 		InitGPIO.c
*
*	@author 	Uladzislau 'vladubase' Dubatouka
*				<vladubase@gmail.com>
*	@version	V1.1
*	@date 		11-November-2020
*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F0/Projects/STM32F0_GPIO
*
*/


/************************************** Includes **************************************/

#include "InitGPIO.h"


/************************************** Function **************************************/

void InitGPIO (void) {
/**
*	@brief	This function setup GPIO.
*			Port A4 as output on LED.
*	@param	None.
*	@retval	None.
*/
	
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;			// GPIOA clock enable.
	
	
	/* **************************** PA4 ************************** */
	
	// General purpose output mode.
	GPIOA->MODER |= GPIO_MODER_MODER4_0;
	
	// Output push-pull (reset state).
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_4;
	
	// High speed.
	// @note	Refer to the device datasheet.
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;
	
	// Pull-up.
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR4_0;
}
