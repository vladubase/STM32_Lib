#ifndef _MAIN_H_
#define _MAIN_H_

/****
	*	@name		STM32F1_FreeRTOS_Tasks
	*	@file 		main.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		1-November-2020
	*
*****/


/************************************** Includes **************************************/

#include "stm32f10x.h"
#include "stdint.h"
#include "stdbool.h"

// User Headers
#include "InitRCC.h"
#include "InitMCO.h"
#include "InitSWD.h"
#include "InitGPIO.h"

// FreeRTOS Init
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


/************************************** Defines **************************************/



/******************************** Function Prototypes ********************************/

// FreeRTOS Tasks
void vTaskBlinkPC13 (void *arg);

#endif /* _MAIN_H_ */
