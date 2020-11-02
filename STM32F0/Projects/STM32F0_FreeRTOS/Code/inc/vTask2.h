#ifndef _VTASK_2_H_
#define _VTASK_2_H_

/****
	*	@name		STM32F0_FreeRTOS
	*	@file 		vTask2.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		30-October-2020
	*
*****/


/************************************** Includes **************************************/

#include "stm32f0xx.h"
#include "stdint.h"
#include "stdbool.h"

// FreeRTOS Init
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


/********************************* Function  prototypes *******************************/

void vTask2 (void *arg);


#endif /* _VTASK_2_H_ */
