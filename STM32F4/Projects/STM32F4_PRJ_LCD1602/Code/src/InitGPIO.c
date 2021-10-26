/*******************************************************************************
 *	@name		STM32F4_GPIO
 *	@file 		InitGPIO.c
 *
 *	@author 	Uladzislau 'vladubase' Dubatouka
 *				<vladubase@gmail.com>
 *	@version	V1.0
 *	@date 		20-September-2021
 ******************************************************************************/

#include "InitGPIO.h"


/********************************* Functions **********************************/

/*
 *	@brief	This function setup General Purpose Input/Output.
 *		LED1602
 *			RS		PC13	Output
 *			R/W		PC14	Output
 *			E		PC15	Output
 *
 *			DB0		PA0		Output
 *			DB1		PA1		Output
 *			DB2		PA2		Output
 *			DB3		PA3		Output
 *			DB4		PA4		Output
 *			DB5		PA5		Output
 *			DB6		PA6		Output
 *			DB7		PA7		Output
 */
void InitGPIO (void) {	
	// Setup Port A
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER7_0 |			// 0b01:	General purpose output mode.
		GPIO_MODER_MODER6_0 |
		GPIO_MODER_MODER5_0 |
		GPIO_MODER_MODER4_0 |
		GPIO_MODER_MODER3_0 |
		GPIO_MODER_MODER2_0 |
		GPIO_MODER_MODER1_0 |
		GPIO_MODER_MODER0_0;
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_7 |			// 0b00:	Output push-pull (reset state).
		GPIO_OTYPER_OT_6 |
		GPIO_OTYPER_OT_5 |
		GPIO_OTYPER_OT_4 |
		GPIO_OTYPER_OT_3 |
		GPIO_OTYPER_OT_2 |
		GPIO_OTYPER_OT_1 |
		GPIO_OTYPER_OT_0);
	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR7 |	// 0b00:	Low speed.
		GPIO_OSPEEDER_OSPEEDR6 |
		GPIO_OSPEEDER_OSPEEDR5 |
		GPIO_OSPEEDER_OSPEEDR4 |
		GPIO_OSPEEDER_OSPEEDR3 |
		GPIO_OSPEEDER_OSPEEDR2 |
		GPIO_OSPEEDER_OSPEEDR1 |
		GPIO_OSPEEDER_OSPEEDR0);
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR7 |			// 0b00:	No pull-up, pull-down.
		GPIO_PUPDR_PUPDR6 | 
		GPIO_PUPDR_PUPDR5 | 
		GPIO_PUPDR_PUPDR4 | 
		GPIO_PUPDR_PUPDR3 | 
		GPIO_PUPDR_PUPDR2 | 
		GPIO_PUPDR_PUPDR1 | 
		GPIO_PUPDR_PUPDR0);
	
	
	// Setup Port C
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER15_0 |			// 0b01:	General purpose output mode.
		GPIO_MODER_MODER14_0 |
		GPIO_MODER_MODER13_0;
	GPIOC->OTYPER &= ~(GPIO_OTYPER_OT_15 |			// 0b00:	Output push-pull (reset state).
		GPIO_OTYPER_OT_14 |
		GPIO_OTYPER_OT_13);
	GPIOC->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR15 |	// 0b00:	Low speed.
		GPIO_OSPEEDER_OSPEEDR14 |
		GPIO_OSPEEDER_OSPEEDR13);
	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPDR15 |			// 0b00:	No pull-up, pull-down.
		GPIO_PUPDR_PUPDR14 | 
		GPIO_PUPDR_PUPDR13);
}
