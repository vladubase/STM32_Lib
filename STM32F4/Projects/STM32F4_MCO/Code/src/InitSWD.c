/****
	*	@name		STM32F4_SWD
	*	@file 		InitSWD.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.2
	*	@date 		10-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F4/Projects/STM32F4_SWD
	*
*****/


/************************************** Includes **************************************/

#include "InitSWD.h"


/************************************** Function **************************************/

void InitSWD (void) {
   /*
	*	@brief	This function setup Serial Wire Debug.
	*	@param	None.
	*	@retval	None.
	*/
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;		// GPIOA clock enable
	
	/* ******************** PA14 SWCLK in pull-down ****************
	   ********************  PA13 SWDIO in pull-up  **************** */
	// Alternate function mode.
	GPIOA->MODER |= GPIO_MODER_MODER14_1 | GPIO_MODER_MODER13_1;
	
	// Output push-pull (reset state).
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_14 | GPIO_OTYPER_OT_14);
	
	// High speed.
	// @note	Refer to the product datasheet.
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14 | GPIO_OSPEEDER_OSPEEDR13;
	
	// PA14 pull-down, PA13 pull-up.
	// @note	Reference Manual: General-purpose I/O (GPIO).	
	//			The debug pins are in AF pull-up/pull-down after reset.
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR14_1 | GPIO_PUPDR_PUPDR13_0;
	
	// GPIO_AFRH should be 0000: AF0 (SYS_AF).
	// @note	Datasheet: 			Alternate function mapping.
	// @note	Reference Manual: 	STM32F411xC/E register boundary addresses.
	// [1] element - means Address offset of GPIOA: 0x24 - GPIO alternate function high register (GPIOx_AFRH).
	GPIOA->AFR[1] &= ~(1 << 0);					// 0x40020000 + 0x24 == 0	-->		address GPIOA + AFRH offset.
}
