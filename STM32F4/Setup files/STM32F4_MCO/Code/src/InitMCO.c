/*******************************************************************************
 *	@name		STM32F4_MCO
 *	@file 		InitMCO.c
 *
 *	@author 	Uladzislau 'vladubase' Dubatouka
 *				<vladubase@gmail.com>
 *	@version	V1.0
 *	@date 		20-July-2021
 ******************************************************************************/

#include "InitMCO.h"


/********************************** Function **********************************/

/*
 *	@brief	This function setup microcontroller clock output.
 */
void InitMCO (void) {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;		// GPIOA clock enable.
	
	GPIOA->MODER |= GPIO_MODER_MODER8_1;		// Alternate function mode.	
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_8;			// Output push-pull (reset state).		
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8;	// High speed.
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR8;			// No pull-up, pull-down.
	
	// f_SYSCLK clock selected as MCO1 source.
	// MCO1 clock = 100 MHz.
	RCC->CFGR &= ~RCC_CFGR_MCO1PRE;				// MCO1 prescaler: no division.
	RCC->CFGR |= RCC_CFGR_MCO1;					// PLL clock selected.
	
	// GPIO_AFRH should be 0000: AF0 (SYS_AF).
	// @note	Datasheet: 			Alternate function mapping.
	// @note	Reference Manual: 	STM32F411xC/E register boundary addresses.
	// [1] element - means GPIO alternate function high register (GPIOx_AFRH).
	GPIOA->AFR[1] &= ~(1 << 0);					// Clear 0th bit.
}
