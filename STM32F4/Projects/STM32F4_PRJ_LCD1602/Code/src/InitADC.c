/*******************************************************************************
 *	@name		STM32F4_PRJ_LCD1602
 *	@file 		InitADC.c
 *
 *	@author 	Uladzislau 'vladubase' Dubatouka
 *				<vladubase@gmail.com>
 *	@version	V1.0
 *	@date 		23-September-2021
 ******************************************************************************/


/********************************** Includes **********************************/

#include "InitADC.h"


/********************************** Function **********************************/

/*
*	@brief	This function setup internal ADC temperature sensor.
*	@param	None.
*	@retval	None.
*/
void InitADC (void) {
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	ADC1->CR2 |= ADC_CR2_ADON;				// A/D Converter ON.
	
	ADC->CCR |= ADC_CCR_ADCPRE_0;			// 0b01:	PCLK2 divided by 4.
	
	ADC1->CR1 &= ~ADC_CR1_SCAN;				// Scan mode disabled.
	ADC1->CR1 &= ~ADC_CR1_RES;				// 0b00: 12-bit (15 ADCCLK cycles).
	
	// TEMPERATURE SENSOR
	ADC->CCR &= ~ADC_CCR_VBATE;				// Vbat channel disabled.
	ADC->CCR |= ADC_CCR_TSVREFE;			// Temperature sensor and VREFINT channel enabled.
	
	ADC1->CR2 &= ~ADC_CR2_CONT;				// Single conversion mode.
	ADC1->CR2 |= ADC_CR2_EOCS;				// EOC bit is set at the end of each regular conversion.
	ADC1->CR2 &= ~ADC_CR2_ALIGN;			// Right alignment.
	
	ADC1->SMPR1 = ADC_SMPR1_SMP16;			// 0b111:	Sampling time: 480 cycles.
											// Total sample time: ~19us.
	
	ADC1->SQR1 &= ~ADC_SQR1_L;				// Channel sequence length: 1 conversion.
	ADC1->SQR3 |= (ADC_SQR3_SQ1 & 16);		// 16 channel on 1st conversion.
}

uint16_t ADC1StartConvertion (void) {
	ADC1->CR2 |= ADC_CR2_SWSTART;			// Start Conversion of regular channels.

	while (!(ADC1->SR & ADC_SR_EOC));		// Wait end of conversion.
	
	return ADC1->DR;						// Return data from ADC (12-bit).
}

