/****
	*	@name		STM32F1_RCC_PLL_72MHz
	*	@file 		InitSWD.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.1
	*	@date 		2-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_RCC_PLL_72MHz
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
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;			// GPIOA clock enable
	
	/* ************************* PA14..13 ************************ */
	// Output mode, max speed 50 MHz.
	GPIOA->CRH |= GPIO_CRH_MODE14 | GPIO_CRH_MODE13;
	
	// Alternate function output Push-pull.
	GPIOA->CRH |= GPIO_CRH_CNF14_1 | GPIO_CRH_CNF13_1;
	
	// Debug port mapping.
	// JTAG-DP Disabled and SW-DP Enabled.
	AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE;
}
