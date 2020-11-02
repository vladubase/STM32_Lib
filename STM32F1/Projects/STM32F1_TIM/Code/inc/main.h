#ifndef _MAIN_H_
#define _MAIN_H_

/****
	*	@name		STM32F1_TIM
	*	@file 		main.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.1
	*	@date 		2-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_TIM
	*
*****/


/************************************** Includes **************************************/

#include "stm32f10x.h"
#include "stdint.h"
#include "stdbool.h"

// User Headers
#include "InitRCC.h"
#include "InitSWD.h"
#include "InitGPIO.h"
#include "InitTIM.h"

// FreeRTOS Init
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


/************************************** Defines **************************************/




/********************************* Function Prototypes ********************************/

// FreeRTOS Tasks
void vTaskDimmingLED (void *arg);

#endif /* _MAIN_H_ */
