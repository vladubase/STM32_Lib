/**
*	@name		STM32F0_TIM
*	@file 		InitTIM.c
*
*	@author 	Uladzislau 'vladubase' Dubatouka
*				<vladubase@gmail.com>
*	@version	V1.0.1
*	@date 		25-January-2021
*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F0/Projects/STM32F0_TIM
*
*/


/************************************** Includes **************************************/

#include "InitTIM.h"


/************************************** Function **************************************/

void InitTIM (void) {
	InitTIM14 ();
}

void InitTIM14 (void) {
/**
*	@brief	This function setup TIM1.
*/
	
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;			// I/O port A clock enable.	
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;			// TIM1 clock enable.
		
	/* ******************* PA7 TIM14 Channel 1******************** */
	// Alternate function mode.
	GPIOA->MODER |= GPIO_MODER_MODER7_1;
	
	// Alternative function selection.
	GPIOA->AFR[0] |= (0x04 << (7 * 4));		// TIM14_CH1 - 0100: AF4.
		
	
	/* ********************** Prescaler value ******************** */
	TIM14->PSC = TIM14_PSC;						// Prescaler Value.
	TIM14->PSC = TIM14_ARR;						// Actual auto-reload Value (period).
	
	
	/* ********************* Non-inverting Mode ****************** */
	TIM14->CCMR1 |= TIM_CCMR1_OC1M_2 | 			// Output Compare 1 Mode. PWM mode 1.
				   TIM_CCMR1_OC1M_1;
	
	
	/* ****************** Capture/Compare 1 output *************** */
	TIM14->CCER |= TIM_CCER_CC1E;				// On - OC1 signal is output.
	TIM14->CCER &= ~TIM_CCER_CC1P;				// OC1 active high.
	
	
	/* ******************** Direction of counting **************** */
	TIM14->CR1 &= TIM_CR1_DIR;					// Counter used as upcounter.
	
	
	TIM14->CR1 |= TIM_CR1_CEN;					// Counter enabled.
}
