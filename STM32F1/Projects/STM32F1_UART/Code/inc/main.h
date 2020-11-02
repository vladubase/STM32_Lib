#ifndef _MAIN_H_
#define _MAIN_H_

/****
	*	@name		STM32F1_USART
	*	@file 		main.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		31-October-2020
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
#include "InitUART.h"

// FreeRTOS Init
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


/************************************** Defines **************************************/




/********************************* Function Prototypes ********************************/

// FreeRTOS Tasks
void vTaskUSART2SendMessage (void *arg);

#endif /* _MAIN_H_ */
