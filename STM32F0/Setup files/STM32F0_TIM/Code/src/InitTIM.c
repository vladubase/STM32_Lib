/**
*	@name		STM32F0_TIM
*	@file 		InitTIM.c
*
*	@author 	Uladzislau 'vladubase' Dubatouka
*				<vladubase@gmail.com>
*	@version	V1.0
*	@date 		14-November-2020
*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F0/Projects/STM32F0_TIM
*
*/


/************************************** Includes **************************************/

#include "InitTIM.h"


/************************************** Function **************************************/

void InitTIM (void) {
	InitTIM1 ();
}

void InitTIM1 (void) {
/**
*	@brief	This function setup TIM1.
*	@param	None.
*	@retval	None.
*/
	
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;			// I/O port A clock enable.
	
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;			// TIM1 clock enable.
		
	/* ******************** PA7 TIM1 Channel 1******************** */
	// Alternate function mode.
	GPIOA->MODER |= GPIO_MODER_MODER7_1;
	
	// Output push-pull (reset state).
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_7;
	
	// High speed - 48 MHz.
	// @note	Refer to the device datasheet.
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEEDR7;
	
	// No pull-up, pull-down.
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR7;
	
	
	/* ********************** Prescaler value ******************** */
	TIM1->PSC = TIM1_PSC;						// Prescaler Value.
	TIM1->PSC = TIM1_ARR;						// Actual auto-reload Value (period).
	
	
	/* ********************* Non-inverting Mode ****************** */
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | 			// Output Compare 1 Mode. PWM mode 1.
				   TIM_CCMR1_OC1M_1;
	
	
	/* ****************** Capture/Compare 1 output *************** */
	TIM1->CCER |= TIM_CCER_CC1E;				// On - OC1 signal is output.
	TIM1->CCER &= ~TIM_CCER_CC1P;				// OC1 active high.
	
	
	/* ******************** Direction of counting **************** */
	TIM1->CR1 &= TIM_CR1_DIR;					// Counter used as upcounter.
	
	
	TIM1->CR1 |= TIM_CR1_CEN;					// Counter enabled.
}
