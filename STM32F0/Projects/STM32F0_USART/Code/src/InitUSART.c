/****
	*	@name		STM32F0_USART
	*	@file 		InitUSART.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		29-October-2020
	*
*****/


/************************************** Includes **************************************/

#include "InitUSART.h"


/************************************** Function **************************************/

void InitUSART (void) {
   /*
	*	@brief	This function setup Serial Wire Debug.
	*	@param	None.
	*	@retval	None
	*/
	
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;			// GPIOA clock enable
	
	// PA14..13:
	// Alternative function mode - SWD
	GPIOA->MODER |= GPIO_MODER_MODER14_1 | GPIO_MODER_MODER13_1;
}
