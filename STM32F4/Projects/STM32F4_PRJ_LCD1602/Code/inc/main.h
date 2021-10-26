#ifndef _MAIN_H_
#define _MAIN_H_

/*******************************************************************************
 *	@name		STM32F4_PRJ_LCD1602
 *	@file 		main.h
 *
 *	@author 	Uladzislau 'vladubase' Dubatouka
 *				<vladubase@gmail.com>
 *	@version	V1.0
 *	@date 		21-September-2021
 ******************************************************************************/


/********************************** Includes **********************************/

#include "stm32f4xx.h"

#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"									// sprinf
#include "wchar.h"									// wchar_t

// User headers
#include "InitRCC.h"
#include "InitSWD.h"
#include "InitGPIO.h"
#include "InitADC.h"


/*********************************** Defines **********************************/

__IO uint32_t SysTick_CNT = 0;						// SysTick count.


/********************************** Functions *********************************/

void InitSYS (void) {
	// Enable Hardware Floating Point.
	SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));
	
	// SysTick
	SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	SysTick->LOAD = f_SYSCLK / (1000 - 1);			// (100 MHz/1000) -> get ms.
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

void LCDSendHalfByte (unsigned char c) {
	c <<= 4;
	GPIOC->BSRRL |= GPIO_BSRR_BS_15;				// LCD E ON.
	delay_ms (1);
	GPIOA->BSRRH |= GPIO_BSRR_BS_7 | 				// 4-bit mode
		GPIO_BSRR_BS_6 | 
		GPIO_BSRR_BS_5 | 
		GPIO_BSRR_BS_4;
	GPIOA->BSRRL |= c;
	GPIOC->BSRRH |= GPIO_BSRR_BS_15;				// LCD E OFF.
	delay_ms (1);
}

/*
 *	@brief		Function to send a byte to display.
 *	@param1		c		Caracter/value to send.
 *	@param2		mode	Instruction	(0)
 *						Data		(1)
 *	@retval		None.
 */
void LCDSendByte (unsigned char c, unsigned char mode) {	
	if (mode == 0) {
		GPIOC->BSRRH |= GPIO_BSRR_BS_13;			// LCD RS OFF.
	} else {
		GPIOC->BSRRL |= GPIO_BSRR_BS_13;			// LCD RS ON.
	}
	LCDSendHalfByte (c >> 4);
	LCDSendHalfByte (c);
}

void LCDSendChar (unsigned char c) {
	LCDSendByte (c, 1);
}

void LCDSendString (char str[]) {
	wchar_t n;
	for (n = 0; str[n] != '\0'; n++) {
		LCDSendChar (str[n]);
	}
}

void InitLCD1602 (void) {
	delay_ms (15);
	LCDSendHalfByte (0x00);
	delay_ms (4);
	LCDSendHalfByte (0x03);
	delay_ms (100);
	LCDSendHalfByte (0x03);
	delay_ms (1);
	LCDSendHalfByte (0x03);
	delay_ms (1);
	LCDSendHalfByte (0x02);
	delay_ms (1);
	LCDSendByte (0x28, 0);							// 4-bit mode.
	delay_ms (1);
	LCDSendByte (0x0C, 0);							// Image on LCD on.
	delay_ms (1);
	LCDSendByte (0x06, 0);							// Coursor.
	delay_ms (1);
}

void LCDClearScreen (void) {
	LCDSendByte (0x01, 0);
}

void LCDSetPositionXY (unsigned char x, unsigned char y) {
	LCDSendByte ((char) ((0x40 * y + x) | 128), 0);
}


/********************************** Interrupts ********************************/

void SysTick_Handler (void) {
	if (SysTick_CNT > 0) {
		SysTick_CNT--;
	}
}


#endif /* _MAIN_H_ */
