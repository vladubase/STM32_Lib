#ifndef _INIT_FLASH_H_
#define _INIT_FLASH_H_

/****
	*	@name		STM32F1_FLASH
	*	@file 		InitFLASH.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		4-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_FLASH
	*	@info		STM32F10xxx Flash memory microcontrollers - Programming manual PM0075
	*
*****/


/************************************** Includes **************************************/

#include "stm32f10x.h"


/************************************** Includes **************************************/

#define FLASH_KEY1	((uint32_t)	0x45670123)
#define FLASH_KEY2	((uint32_t) 0xCDEF89AB)


/********************************* Function  prototypes *******************************/

void InitFLASH (void);

void FLASHUnlock (void);
void FLASHLock (void);
void FLASHRemoveFirmware (void);

uint32_t FLASHReadData (uint32_t address);
void FLASHWriteData (uint32_t address, uint32_t data);


#endif /* _INIT_FLASH_H_ */
