#ifndef _MAIN_H_
#define _MAIN_H_

/****
	*	@name		STM32F1_ADC
	*	@file 		main.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		2-November-2020
	*
*****/


/************************************** Includes **************************************/

#include "stm32f10x.h"
#include "stdint.h"
#include "stdbool.h"
#include <stdio.h>

// User Headers
#include "InitRCC.h"
#include "InitMCO.h"
#include "InitSWD.h"
#include "InitGPIO.h"
#include "InitUART.h"
#include "InitADC.h"

// FreeRTOS Init
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


/************************************** Defines **************************************/

#define ADC_STEP_VOLTS	((float)	3 / 4095)
 
 
/************************************ Structures *************************************/

xQueueHandle SendDataADC;


/******************************** Function Prototypes ********************************/

// FreeRTOS Tasks
void vTaskADCConversion (void *arg);
void vTaskUSART1SendData (void *arg);

#endif /* _MAIN_H_ */
