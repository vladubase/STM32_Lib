#ifndef _INIT_TIM_H_
#define _INIT_TIM_H_

/****
	*	@name		STM32F1_TIM
	*	@file 		InitTIM.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*	@version	V1.1
	*	@date 		2-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_TIM
	*
*****/


/************************************** Includes **************************************/

#include "stm32f10x.h"
#include "stdint.h"


/*************************************** Defines **************************************/

#define	TIM2_PSC	((uint16_t) 72 - 1)			// Prescaller.
#define	TIM2_ARR	((uint16_t) 1000)			// Period.


/********************************* Function  prototypes *******************************/

void InitTIM (void);


#endif /* _INIT_TIM_H_ */
