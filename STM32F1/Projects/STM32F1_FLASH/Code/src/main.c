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
	
	// Address: Page 127 0x0801FC00 - 0x0801FFFF 1 Kbyte
	// Data: Hello,  world!   
		FLASHWriteData (0x0801FC00,			0x6C6C6548);
		FLASHWriteData (0x0801FC00 + 0x4,	0x57202C6F);
		FLASHWriteData (0x0801FC00 + 0x8,	0x646C726F);
		FLASHWriteData (0x0801FC00 + 0xC,	0x20202021);
	
	// MAIN CYCLE
		while (1) {
			
		}
}
