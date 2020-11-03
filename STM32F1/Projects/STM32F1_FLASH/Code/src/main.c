/****
	*	@name		STM32F1_FLASH
	*	@file 		main.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		4-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_FLASH
	*
*****/


/************************************** Include ***************************************/

#include "main.h"
 

/**************************************** Main ****************************************/

int main (void) {
	// DEFINITION OF VARIABLES
		
	
	// MICROCONTROLLER INITIALIZATION
		InitRCC ();
		InitSWD ();
//		InitFLASH ();
	
	// Address: Page 127 0x0801FC00 - 0x0801FFFF 1 Kbyte
	// Data: _Hello,  world!_
		FLASHWriteData (0x0801FC00,			0x6C65485F);
		FLASHWriteData (0x0801FC00 + 0x4,	0x202C6F6C);
		FLASHWriteData (0x0801FC00 + 0x8,	0x726F7720);
		FLASHWriteData (0x0801FC00 + 0xC,	0x5F21646C);
	
	// MAIN CYCLE
		while (1) {
			
		}
}
