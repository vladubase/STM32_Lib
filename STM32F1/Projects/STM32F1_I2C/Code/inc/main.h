#ifndef _MAIN_H_
#define _MAIN_H_

/****
	*	@name		STM32F1_I2C
	*	@file 		main.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		8-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_I2C
	*
*****/


/************************************** Includes **************************************/

#include "stm32f10x.h"
#include "stdint.h"
#include "stdbool.h"

// User headers
#include "InitRCC.h"
#include "InitSWD.h"
#include "InitGPIO.h"
#include "InitI2C.h"


/************************************** Defines **************************************/

#define I2C_LED1602	0x27


#endif /* _MAIN_H_ */
