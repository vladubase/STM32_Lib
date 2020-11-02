/****
	*	@name		STM32F1_ADC
	*	@file 		InitADC.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.1
	*	@date 		2-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_ADC
	*
*****/


/************************************** Includes **************************************/

#include "InitADC.h"


/************************************** Function **************************************/

void InitADC (void) {
	InitADC1CH1 ();
	ADC1StartConvertion ();
}

void InitADC1CH1 (void) {
   /*
	*	@brief	This function setup ADC1 channel 1.
	*	@param	None.
	*	@retval	None.
	*/
	
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |		// ADC 1 interface clock enable.
					RCC_APB2ENR_AFIOEN;			// I/O port A clock enable.
	
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN |		// Alternate Function I/O clock enable.
					RCC_CFGR_ADCPRE_DIV6;		// PCLK2 / 6 = 12 MHz.
	
	/* **************************** PA0 ************************** */
	// Input mode (reset state).
	GPIOC->CRL &= ~GPIO_CRL_MODE0;
	
	// Analog mode.
	GPIOC->CRL &= ~GPIO_CRL_CNF0;
	
	/* ************************ Calibration ********************** */
	ADC1->CR2 |= ADC_CR2_CAL;
	while (!(ADC1->CR2 |= ADC_CR2_CAL));
	
	/* *********************************************************** */
	ADC1->CR2 |= ADC_CR2_ADON;					// A/D Converter ON.
	ADC1->CR2 &= ~ADC_CR2_CONT;					// 1 - Continuous Conversion, 0 - Single conversion.
	
	/* *********************************************************** */
	ADC1->CR2 |= ADC_CR2_EXTSEL;				// External event start conversion SWSTART.
	ADC1->CR2 |= ADC_CR2_EXTTRIG;				// External Trigger Conversion mode for regular channels.
	
	/* *********************************************************** */
	ADC1->SMPR1 |= ADC_SMPR1_SMP16;				// +239.5 cycles, ~21us.
	ADC1->SQR1 &= ~ADC_SQR1_L;					// Regular channel sequence length.
	ADC1->SQR3 &= ~ADC_SQR3_SQ1;				// 1st conversion in regular sequence. Invert value because 0th channel.
}

uint16_t ADC1StartConvertion (void) {
	ADC1->CR2 |= ADC_CR2_SWSTART;			// Start Conversion of regular channels.
	
	while (!(ADC1->SR & ADC_SR_EOC));		// Wait end of conversion.
	
	return ADC1->DR;						// Return data from ADC.
}
