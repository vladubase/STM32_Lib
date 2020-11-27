/****
	*	@name		STM32F0_RCC_PLL_48MHz
	*	@file 		InitRCC.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		2-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F0/Projects/STM32F0_RCC_PLL_48MHz
	*
*****/


/************************************** Includes **************************************/

#include "InitRCC.h"


/************************************** Function **************************************/

void InitRCC (void) {
   /*
	*	@brief	This function setup RCC. Use external crystal on 24 MHz.
	*	@param	None.
	*	@retval	None
	*/
	
	RCC->CR |= RCC_CR_HSEON; 							// External High Speed clock enable.
	while (!(RCC->CR & RCC_CR_HSERDY));					// External High Speed clock ready flag.
	
	// Flash clock
	FLASH->ACR = FLASH_ACR_PRFTBE | 					// Prefetch buffer enable.
		FLASH_ACR_LATENCY;								// One wait state.
	
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;					// AHB = SYSCLK.
	RCC->CFGR |= RCC_CFGR_PPRE_DIV1;					// APB = SYSCLK.
	
	RCC->CFGR |= RCC_CFGR_PLLSRC_PREDIV1; 				// PREDIV1 clock selected as PLL entry clock source.
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_PREDIV1; 			// PREDIV1 clock not divided for PLL entry.
	RCC->CFGR |= RCC_CFGR_PLLMULL2; 					// PLL input clock*2: 24 MHz * 2 = 48 MHz.
	
	RCC->CR |= RCC_CR_PLLON;                      		// LL enable.
	while(!(RCC->CR & RCC_CR_PLLRDY));      			// PLL clock ready flag.
	
	// System clock MUX - PLLCLK
	RCC->CFGR &= ~RCC_CFGR_SW;                   		// Clear SW bits.
	RCC->CFGR |= RCC_CFGR_SW_PLL;                 		// Select source SYSCLK = PLL.
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1); // Wait till PLL is used.
}
