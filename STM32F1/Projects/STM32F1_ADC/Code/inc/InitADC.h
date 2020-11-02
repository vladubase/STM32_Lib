#ifndef _INIT_ADC_H_
#define _INIT_ADC_H_

/****
	*	@name		STM32F1_ADC
	*	@file 		InitADC.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.1
	*	@date 		2-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_ADC
	*
*****/


/************************************** Includes **************************************/

#include "stm32f10x.h"


/********************************* Function  prototypes *******************************/

void InitADC (void);
void InitADC1CH1 (void);
uint16_t ADC1StartConvertion (void);


#endif /* _INIT_ADC_H_ */
