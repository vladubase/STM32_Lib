/****
	*	@name		STM32F4_RCC_PLL_100MHz
	*	@file 		InitRCC.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		2-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F4/Projects/STM32F4_RCC_PLL_100MHz
	*
*****/


/************************************** Includes **************************************/

#include "InitRCC.h"


/************************************** Function **************************************/

void InitRCC (void) {
   /*
	*	@brief	This function setup RCC. Use external crystal on 25 MHz.
	*	@param	None.
	*	@retval	None
	*/
	
	RCC->CR |= RCC_CR_HSEON; 									// External High Speed clock enable.
	while (!(RCC->CR & RCC_CR_HSERDY));							// External High Speed clock ready flag.
	
	// Flash clock
	FLASH->ACR = FLASH_ACR_PRFTEN | 							// Prefetch buffer enable.
		FLASH_ACR_LATENCY_0WS;									// Zero wait state.
	
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;							// SYSCLK not divided. AHB = SYSCLK.
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;							// HCLK not divided. APB = SYSCLK.
	
	RCC->CFGR |= RCC_PLLCFGR_PLLSRC_HSE; 						// PREDIV1 clock selected as PLL entry clock source.
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_PREDIV1; 					// PREDIV1 clock not divided for PLL entry.	
	RCC->CFGR |= RCC_CFGR_PLLM_8; 								// PLL input clock*2: 24 MHz * 2 = 48 MHz.
	
	RCC->CR |= RCC_CR_PLLON;                      				// PLL enable.
	while(!(RCC->CR & RCC_CR_PLLRDY));      					// PLL clock ready flag.
	
	// System clock MUX - PLLCLK
	RCC->CFGR &= ~RCC_CFGR_SW;                   				// Clear SW bits.
	RCC->CFGR |= RCC_CFGR_SW_PLL;                 				// Select source SYSCLK = PLL.
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1); 		// Wait till PLL is used.
}
