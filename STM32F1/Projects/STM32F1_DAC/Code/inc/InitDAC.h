#ifndef _INIT_DAC_H_
#define _INIT_DAC_H_

/****
	*	@name		STM32F1_DAC
	*	@file 		InitDAC.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		3-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_DAC
	*
*****/


/************************************** Includes **************************************/

#include "stm32f10x.h"


/********************************* Function  prototypes *******************************/

void InitDAC (void);
void DACWrite (uint16_t DAC_value);


#endif /* _INIT_DAC_H_ */
