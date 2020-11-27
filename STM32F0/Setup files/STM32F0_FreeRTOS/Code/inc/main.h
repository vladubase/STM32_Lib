#ifndef _MAIN_H_
#define _MAIN_H_

/****
	*	@name		STM32F0_FreeRTOS
	*	@file 		main.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		31-October-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F0/Projects/STM32F0_FreeRTOS
	*
*****/


/************************************** Includes **************************************/

#include "stm32f0xx.h"
#include "stdint.h"
#include "stdbool.h"

// User Headers
#include "InitRCC.h"
#include "InitSWD.h"
#include "InitGPIO.h"

// FreeRTOS Init
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


/************************************** Defines **************************************/




/********************************* Function Prototypes ********************************/

// FreeRTOS Tasks
void vTask1 (void *arg);
void vTask2 (void *arg);

#endif /* _MAIN_H_ */
