#ifndef _MAIN_H_
#define _MAIN_H_

/****
	*	@name		STM32F1_FreeRTOS_Queues
	*	@file 		main.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		1-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/FreeRTOS/STM32F1_FreeRTOS_Queues
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
#include "InitUART.h"

// FreeRTOS Init
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


/************************************** Defines **************************************/


 
 
/************************************ Structures *************************************/

xQueueHandle SendData;


/******************************** Function Prototypes ********************************/

// FreeRTOS Tasks
void vTaskUSART2SendMessage (void *arg);
void vTaskUSART2ReceiveMessage (void *arg);

#endif /* _MAIN_H_ */
