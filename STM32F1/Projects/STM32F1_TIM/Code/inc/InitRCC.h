#ifndef _INIT_RCC_H_
#define _INIT_RCC_H_

/****
	*	@name		STM32F1_RCC
	*	@file 		InitRCC.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		31-October-2020
	*
*****/


/************************************** Includes **************************************/

#include "stm32f10x.h"


/************************************** Includes **************************************/

#define F_HCLK	((uint32_t)	72e6)				// Internal AHB clock frequency.
#define F_PCLK1	((uint32_t)	36e6)				// Internal APB1 clock frequency.
#define F_PCLK2	((uint32_t)	72e6)				// Internal APB2 clock frequency.


/********************************* Function  prototypes *******************************/

void InitRCC (void);


#endif /* _INIT_RCC_H_ */
