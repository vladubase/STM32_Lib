#ifndef _MAIN_H_
#define _MAIN_H_

/*******************************************************************************
 *	@name		STM32F4_MCO
 *	@file 		main.h
 *
 *	@author 	Uladzislau 'vladubase' Dubatouka
 *				<vladubase@gmail.com>
 *	@version	V1.0
 *	@date 		20-July-2021
 ******************************************************************************/


/********************************** Includes **********************************/

#include "stm32f4xx.h"

#include "stdint.h"
#include "stdbool.h"

// User headers
#include "InitRCC.h"
#include "InitSWD.h"
#include "InitMCO.h"


/*********************************** Defines **********************************/

__IO uint32_t SysTick_CNT = 0;						// SysTick count.

/********************************** Functions *********************************/

void InitSystem (void) {
	// Enable Hardware Floating Point.
	SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));
	
	// SysTick.
	SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	SysTick->LOAD = f_SYSCLK / (1000 - 1);			// 100 MHz / 1000 -> get ms.
	SysTick->VAL &= ~SysTick_VAL_CURRENT_Msk;
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk |	// Processor clock (AHB).
		SysTick_CTRL_TICKINT_Msk |					// Asserts the SysTick exception request.
		SysTick_CTRL_ENABLE_Msk;					// Counter enabled.
}

void delay_ms (uint32_t time) {
	SysTick->VAL &= ~SysTick_VAL_CURRENT_Msk;
	SysTick->VAL = f_SYSCLK / (1000 - 1);
	SysTick_CNT = time;
	while (SysTick_CNT);
}


/********************************** Interrupts ********************************/

void SysTick_Handler (void) {
	if (SysTick_CNT > 0) {
		SysTick_CNT--;
	}
}

#endif /* _MAIN_H_ */
