/****
	*	@name		STM32F1_TIM
	*	@file 		InitTIM.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		1-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_TIM
	*
*****/


/************************************** Includes **************************************/

#include "InitTIM.h"


/************************************** Function **************************************/

void InitTIM (void) {
   /*
	*	@brief	This function setup TIM2 channel 1.
	*	@param	None.
	*	@retval	None.
	*/
	
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |		// IO port A clock enable.
					RCC_APB2ENR_AFIOEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;			// Timer 2 clock enable.
	
	/* **************************** PA0 ************************** */
	// Output mode, max speed 50 MHz.
	GPIOA->CRL |= GPIO_CRL_MODE0;
	
	// Alternate function output Push-pull.
	GPIOA->CRL &= ~GPIO_CRL_CNF0;
	GPIOA->CRL |= GPIO_CRL_CNF0_1;
	
	/* ********************** Prescaler value ******************** */
	TIM2->PSC = TIM2_PSC;						// Prescaller.
	TIM2->ARR = TIM2_ARR;						// Period.
	
	/* ********************* Non-inverting Mode ****************** */
	TIM2->CCMR1 |= TIM_CCMR1_OC1M_2 | 			// Output Compare 1 Mode.
				   TIM_CCMR1_OC1M_1;
	
	/* ****************** Capture/Compare 1 output *************** */
	TIM2->CCER |= TIM_CCER_CC1E;				// On - OC1 signal is output on the corresponding output pin.
	TIM2->CCER &= ~TIM_CCER_CC1P;				// OC1 active high.
	
	/* ******************** Direction of counting **************** */
	TIM2->CR1 &= TIM_CR1_DIR;					// Counter used as upcounter.
	
	/* *********************** Counter Enable ******************** */
	TIM2->CR1 |= TIM_CR1_CEN;					// Counter enabled.
}
