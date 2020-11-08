#ifndef _INIT_DMA_H_
#define _INIT_DMA_H_

/****
	*	@name		STM32F1_DMA
	*	@file 		InitDMA.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V0.1
	*	@date 		8-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_DMA
	*
*****/


/************************************** Includes **************************************/

#include "stm32f10x.h"


/********************************* Function  prototypes *******************************/

void InitDMA (void);
void InitDMA_USART1 (void);
void DMA_USART1Write (void);


#endif /* _INIT_DMA_H_ */
