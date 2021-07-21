#ifndef _MAIN_H_
#define _MAIN_H_

/*******************************************************************************
 *	@name		STM32F4_ADC
 *	@file 		main.h
 *
 *	@author 	Uladzislau 'vladubase' Dubatouka
 *				<vladubase@gmail.com>
 *	@version	V1.0
 *	@date 		21-July-2021
 ******************************************************************************/


/********************************** Includes **********************************/

#include "stm32f4xx.h"

#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"

// User headers
#include "InitRCC.h"
#include "InitSWD.h"
#include "InitGPIO.h"
#include "InitUART.h"
#include "InitADC.h"


/*********************************** Defines **********************************/



/********************************** Functions *********************************/

void InitSystem (void) {
	SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));	// Enable Hardware Floating Point.
}

void delay_ms (uint32_t time) {
	while (time--);
}

#endif /* _MAIN_H_ */
