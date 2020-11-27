#ifndef _MAIN_H_
#define _MAIN_H_

/****
	*	@name		STM32F1_DAC
	*	@file 		main.h
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
#include "stdint.h"
#include "stdbool.h"
#include <stdio.h>

// User Headers
#include "InitRCC.h"
#include "InitSWD.h"
#include "InitDAC.h"

// FreeRTOS Init
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


/************************************** Defines **************************************/


 
 
/************************************ Structures *************************************/

xQueueHandle SendDataADC;


/******************************** Function Prototypes ********************************/

// FreeRTOS Tasks
void vTaskDACOut (void *arg);

#endif /* _MAIN_H_ */
