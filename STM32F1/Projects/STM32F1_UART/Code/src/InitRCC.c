/****
	*	@name		STM32F1_USART
	*	@file 		InitRCC.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		31-October-2020
	*
*****/


/************************************** Includes **************************************/

#include "InitRCC.h"


/************************************** Function **************************************/

void InitRCC (void) {
   /*
	*	@brief	This function setup RCC. Use external crystal on 8 MHz.
	*	@param	None.
	*	@retval	None
	*/
	
	RCC->CR |= RCC_CR_HSEON; 							// External High Speed clock enable.
	while (!(RCC->CR & RCC_CR_HSERDY));					// External High Speed clock ready flag.
	
	// Flash clock
	FLASH->ACR = FLASH_ACR_PRFTBE | 					// Prefetch buffer enable.
		FLASH_ACR_LATENCY;								// One wait state.
	
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;					// AHB = SYSCLK.
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;					// APB1 = SYSCLK / 2.
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;					// APB2 = SYSCLK.
	
	RCC->CFGR |= RCC_CFGR_PLLSRC_HSE; 					// HSE clock selected as PLL entry clock source.
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_HSE; 				// HSE clock not divided for PLL entry.
	RCC->CFGR |= RCC_CFGR_PLLMULL9; 					// PLL input clock*9: 8 MHz * 9 = 72 MHz.
	
	RCC->CR |= RCC_CR_PLLON;                      		// LL enable.
	while(!(RCC->CR & RCC_CR_PLLRDY));      			// PLL clock ready flag.
	
	// System clock MUX - PLLCLK
	RCC->CFGR &= ~RCC_CFGR_SW;                   		// Clear SW bits.
	RCC->CFGR |= RCC_CFGR_SW_PLL;                 		// Select source SYSCLK = PLL.
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1); // Wait till PLL is used.
}
