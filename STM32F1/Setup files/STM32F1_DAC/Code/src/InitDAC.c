/****
	*	@name		STM32F1_DAC
	*	@file 		InitDAC.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		3-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_DAC
	*
*****/


/************************************** Includes **************************************/

#include "InitDAC.h"


/************************************** Function **************************************/


#if defined (STM32F10X_HD) || defined  (STM32F10X_CL)
	void InitDAC (void) {
	   /*
		*	@brief	This function setup DAC out 1.
		*	@param	None.
		*	@retval	None.
		*/
		
		
		RCC->APB1ENR |= RCC_APB1ENR_DACEN;		// DAC interface clock enable.
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |;	// I/O port A clock enable.
						RCC_APB2ENR_AFIOEN;		// Alternate Function I/O clock enable.
		
		/* **************************** PA4 ************************** */
		// Input mode (reset state).
		GPIOC->CRL &= ~GPIO_CRL_MODE4;
	
		// Analog mode.
		GPIOC->CRL &= ~GPIO_CRL_CNF4;

		DAC->CR |= DAC_CR_EN1;					// DAC channel1 enable.
	}
	
	void DACWrite (uint16_t DAC_value) {
		if (DAC_value < 4096) {
			DAC->DHR12R1 = DAC_value;
		}
	}
#endif
