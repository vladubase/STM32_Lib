#ifndef _MAIN_H_
#define _MAIN_H_

/*******************************************************************************
 *	@name		STM32F4_RCC_PLL_100MHz
 *	@file 		main.h
 *
 *	@author 	Uladzislau 'vladubase' Dubatouka
 *				<vladubase@gmail.com>
 *	@version	V1.0
 *	@date 		19-July-2021
 *	@link		https://github.com/vladubase/STM32_Lib
 ******************************************************************************/


/********************************** Includes **********************************/

#include "stm32f4xx.h"

#include "stdint.h"
#include "stdbool.h"

// User headers
#include "InitRCC.h"


/*********************************** Defines **********************************/



/********************************** Functions *********************************/

void InitSystem (void) {
	SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));	// Enable Hardware Floating Point.
}


void delay_ms (uint32_t ms) {
	uint32_t i = 0;
	for (i = 0; i < ((f_HCLK / 1000) * ms); i++) {
		__ASM ("NOP");
	}
}

#endif /* _MAIN_H_ */
