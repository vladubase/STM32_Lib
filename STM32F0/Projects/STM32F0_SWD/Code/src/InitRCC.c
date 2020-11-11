/****
	*	@name		STM32F0_RCC_PLL_48MHz
	*	@file 		InitRCC.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.1
	*	@date 		11-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F0/Projects/STM32F0_RCC_PLL_48MHz
	*
*****/


/************************************** Includes **************************************/

#include "InitRCC.h"


/************************************** Function **************************************/

void InitRCC (void) {
   /*
	*	@brief	This function setup RCC. HSE will be used as PLL clock source.
	*			Use external crystal on 8 MHz. HCLK output is 48 MHz.
	*	@param	None.
	*	@retval	None.
	*/
	
	RCC->CR |= RCC_CR_HSEON; 					// External High Speed clock enable.
	while (!(RCC->CR & RCC_CR_HSERDY));			// External High Speed clock ready flag.
	
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;			// SYSCLK not divided. AHB = SYSCLK.
	RCC->CFGR |= RCC_CFGR_PPRE_DIV1;			// APB = SYSCLK.
	
	RCC->CFGR |= RCC_CFGR_PLLSRC_PREDIV1; 		// PREDIV1 clock selected as PLL entry clock source.
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_PREDIV1; 	// PREDIV1 clock not divided for PLL entry.
	RCC->CFGR |= RCC_CFGR_PLLMULL6; 			// PLL input clock*6: 8 MHz * 6 = 48 MHz.
	
	// System clock MUX - PLLCLK
	RCC->CFGR &= ~RCC_CFGR_SW;					// Clear SW bits.
	RCC->CFGR |= RCC_CFGR_SW_PLL;				// Select source SYSCLK = PLL.
	while((RCC->CFGR & RCC_CFGR_SWS) !=			// Wait till PLL is used.
		RCC_CFGR_SWS_1);
	
	RCC->CR |= RCC_CR_PLLON;					// PLL enable.
	while(!(RCC->CR & RCC_CR_PLLRDY));      	// PLL clock ready flag.
	
	// Configure Flash prefetch, Instruction cache, Data cache and wait state.
	FLASH->ACR = FLASH_ACR_PRFTBE |				// Prefetch buffer enable.
		FLASH_ACR_LATENCY;						// One wait state as 24 MHz < SYSCLK = 48 MHz.
}
