/****
	*	@name		STM32F0_FreeRTOS
	*	@file 		InitGPIO.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		30-October-2020
	*
*****/


/************************************** Includes **************************************/

#include "InitGPIO.h"


/************************************** Function **************************************/

void InitGPIO (void) {
   /*
	*	@brief	This function setup GPIO. Port A as output, Port B as input
	*	@param	None.
	*	@retval	None
	*/
	
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;			// GPIOA clock enable
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;			// GPIOB clock enable
	
	
	/******************  Bit definition for PA10..9, 7..0  ******************/
	
	// General purpose output mode
	/*	GPIOA->MODER = 0x145555;	*/
	GPIOA->MODER |= GPIO_MODER_MODER10_0 | GPIO_MODER_MODER9_0 | GPIO_MODER_MODER7_0 | 
		GPIO_MODER_MODER6_0 | GPIO_MODER_MODER5_0 | GPIO_MODER_MODER4_0 | GPIO_MODER_MODER3_0 | 
		GPIO_MODER_MODER2_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER0_0;
	
	// Output push-pull (reset state)
	/*	GPIOA->OTYPER = 0x000000;	*/
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_10 | GPIO_OTYPER_OT_9 | GPIO_OTYPER_OT_7 | GPIO_OTYPER_OT_6 |
		GPIO_OTYPER_OT_5 | GPIO_OTYPER_OT_4 | GPIO_OTYPER_OT_3 | GPIO_OTYPER_OT_2 | GPIO_OTYPER_OT_1);
	
	// High speed
	/*	GPIOA->OSPEEDR = 0x3CFFFF;	*/
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10 | GPIO_OSPEEDER_OSPEEDR9 | GPIO_OSPEEDER_OSPEEDR7 | 
		GPIO_OSPEEDER_OSPEEDR6 | GPIO_OSPEEDER_OSPEEDR5 | GPIO_OSPEEDER_OSPEEDR4 |
		GPIO_OSPEEDER_OSPEEDR2 | GPIO_OSPEEDER_OSPEEDR1 | GPIO_OSPEEDER_OSPEEDR0;
	
	// Pull-up
	/*	GPIOA->PUPDR = 0x175555;	*/
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR10_0 | GPIO_PUPDR_PUPDR9_0 | GPIO_PUPDR_PUPDR7_0 |
		GPIO_PUPDR_PUPDR6_0 | GPIO_PUPDR_PUPDR5_0 | GPIO_PUPDR_PUPDR4_0 | GPIO_PUPDR_PUPDR3_0 |
		GPIO_PUPDR_PUPDR2_0 | GPIO_PUPDR_PUPDR1_0 | GPIO_PUPDR_PUPDR0_0;
	
	
	/***********************  Bit definition for PB1  ***********************/
	
	// General purpose input mode
	/*	GPIOB->MODER = 0x000000;	*/
	GPIOB->MODER &= ~GPIO_MODER_MODER1;
	
	// Output push-pull (reset state)
	/*	GPIOA->OTYPER = 0x000000;	*/
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_1;
	
	// High speed
	/*	GPIOA->OSPEEDR = 0x000003;	*/
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR1;
	
	// Pull-down
	/*	GPIOA->PUPDR = 0x000002;	*/
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR1_1;
}
