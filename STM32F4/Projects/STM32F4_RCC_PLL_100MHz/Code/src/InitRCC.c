/****
	*	@name		STM32F4_RCC_PLL_100MHz
	*	@file 		InitRCC.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.3
	*	@date 		11-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F4/Projects/STM32F4_RCC_PLL_100MHz
	*
*****/


/************************************** Includes **************************************/

#include "InitRCC.h"


/************************************** Function **************************************/

void InitRCC (void) {
   /*
	*	@brief	This function setup RCC. HSE will be used as PLL clock source.
	*			Use external crystal on 25 MHz. HCLK output is 100 MHz.
	*	@param	None.
	*	@retval	None.
	*/
	
	RCC->CR |= RCC_CR_HSEON; 					// External High Speed clock enable.
	while (!(RCC->CR & RCC_CR_HSERDY));			// External High Speed clock ready flag.
	
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;			// SYSCLK not divided. AHB = SYSCLK.
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;			// APB1 = SYSCLK / 2.
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;			// APB2 = SYSCLK.
	
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE; 	// PREDIV1 clock selected as PLL entry clock source.
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLM & PLL_M);	// PLL M divider = 12.
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLN & PLL_N);	// PLL N multiplier = 96.
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLP & PLL_P);	// PLL P divider = 2.
	
	// System clock MUX - PLLCLK.
	RCC->CFGR &= ~RCC_CFGR_SW;					// Clear SW bits.
	RCC->CFGR |= RCC_CFGR_SW_PLL;				// Select source SYSCLK = PLL.
	while((RCC->CFGR & RCC_CFGR_SWS) !=  		// Wait till PLL is used.
		RCC_CFGR_SWS_PLL);
	
	// Enable the main PLL.
	RCC->CR |= RCC_CR_PLLON;					// PLL enable.
	while(!(RCC->CR & RCC_CR_PLLRDY));			// PLL clock ready flag.
	
	// Configure Flash prefetch, Instruction cache, Data cache and wait state.
	FLASH->ACR = FLASH_ACR_DCEN |				// Data cache is enabled.
		FLASH_ACR_ICEN |						// Instruction cache is enabled.
		FLASH_ACR_PRFTEN | 						// Prefetch buffer enable.
		FLASH_ACR_LATENCY_3WS;					// The ratio of the CPU clock period to the Flash memory access time
												//	Three wait states.
												//	@note See Table "Number of wait states
												//	according to CPU clock (HCLK) frequency".
}
