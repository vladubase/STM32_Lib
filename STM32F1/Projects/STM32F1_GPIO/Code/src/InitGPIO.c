/****
	*	@name		STM32F1_GPIO
	*	@file 		InitGPIO.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.1
	*	@date 		2-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_GPIO
	*
*****/


/************************************** Includes **************************************/

#include "InitGPIO.h"


/************************************** Function **************************************/

void InitGPIO (void) {
   /*
	*	@brief	This function setup I/O ports.
	*	@param	None.
	*	@retval	None.
	*/
	
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;			// IO port C clock enable
	
	/* *************************** PC14 ************************** */
	// Input mode (reset state).
	GPIOC->CRH &= ~GPIO_CRH_MODE14;
	
	// Input with pull-up / pull-down.
	GPIOC->CRH |= GPIO_CRH_CNF14_1;
	
	
	/* *************************** PC13 ************************** */
	// Output mode, max speed 2 MHz.
	GPIOC->CRH |= GPIO_CRH_MODE13_1;
	
	// General purpose output push-pull.
	GPIOC->CRH &= ~GPIO_CRH_CNF13;
}
