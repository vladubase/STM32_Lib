/****
	*	@name		STM32F1_FLASH
	*	@file 		InitSWD.c
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

#include "InitFLASH.h"


/************************************** Function **************************************/

void InitFLASH (void) {
   /*
	*	@brief	This function setup internal FLASH.
	*	@param	None.
	*	@retval	None.
	*/
	
//	FLASHRemoveFirmware ();
}

void FLASHUnlock (void) {
	// These bits represent the keys to unlock the FPEC.
	FLASH->KEYR = FLASH_KEY1;
	FLASH->KEYR = FLASH_KEY2;
}

void FLASHLock (void) {
	// FPEC and FLASH_CR are locked.
	FLASH->CR |= FLASH_CR_LOCK;
}

void FLASHRemoveFirmware (void) {
	FLASH->CR |= FLASH_CR_MER;					// Erase of all user pages chosen.	
	FLASH->CR |= FLASH_CR_STRT;					// This bit triggers an ERASE operation when set.
}

uint32_t FLASHReadData (uint32_t address) {
	return (*(__IO uint32_t*) address);
}

void FLASHWriteData (uint32_t address, uint32_t data) {
	FLASHUnlock ();								// Unlock FLASH
	
	FLASH->CR |= FLASH_CR_PG;					// Flash programming chosen.
	while ((FLASH->SR & FLASH_SR_BSY) != 0);	// Flash operation is in progress.
	
	/* *************** Writing the least two bytes *************** */
	*(__IO uint16_t*) address = (uint16_t) data;
	while ((FLASH->SR & FLASH_SR_BSY) != 0);	// Flash operation is in progress.
	
	address += 2;
	data >>= 16;
	
	/* ***************** Writing next two bytes ****************** */
	*(__IO uint16_t*) address = (uint16_t) data;
	while ((FLASH->SR & FLASH_SR_BSY) != 0);	// Flash operation is in progress.
	
	FLASH->CR &= ~(FLASH_CR_PG);
	
	FLASHLock ();								// Lock FLASH
}
