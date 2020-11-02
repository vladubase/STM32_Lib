/****
	*	@name		STM32F1_RCC_PLL_72MHz
	*	@file 		InitMCO.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		2-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_STM32F1_RCC_PLL_72MHz
	*
*****/


/************************************** Includes **************************************/

#include "InitMCO.h"


/************************************** Function **************************************/

void InitMCO (void) {
   /*
	*	@brief	This function setup microcontroller clock output.
	*	@param	None.
	*	@retval	None.
	*/
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;			// GPIOA clock enable
	
	/* **************************** PA8 ************************** */
	// Output mode, max speed 50 MHz.
	GPIOA->CRH |= GPIO_CRH_MODE8;
	
	// Alternate function output Push-pull.
	GPIOA->CRH |= GPIO_CRH_CNF8_1;
	
	// PLL clock divided by 2 selected as MCO source
	// PLL / 2 = 36 Mhz.
	RCC->CFGR |= RCC_CFGR_MCO_PLL;
}
