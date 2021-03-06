#ifndef _INIT_UART_H_
#define _INIT_UART_H_

/****
	*	@name		STM32F1_UART
	*	@file 		InitUART.h
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>
	*	@version	V1.0
	*	@date 		1-November-2020
	*	@link		https://github.com/vladubase/STM32_Lib/tree/main/STM32F1/Projects/STM32F1_UART
	*
*****/


/************************************** Includes **************************************/

#include "stm32f10x.h"


/************************************** Defines **************************************/

#define	APB1_PERIPH_CLOCK		((uint32_t)	36e6)
#define	APB2_PERIPH_CLOCK		((uint32_t)	72e6)
#define	USART1_BAUDRATE			((uint16_t)	9600)
#define	USART2_BAUDRATE			((uint16_t)	9600)


/********************************* Function  prototypes *******************************/

void InitUART (void);

// USART 1
	void InitUSART1 (void);
	void USART1SendByte (char chr);
	void USART1SendString (char* str);
	void USART1_IRQHandler (void);

// USART 2
	void InitUSART2 (void);
	void USART2SendByte (char chr);
	void USART2SendString (char* str);
	void USART2_IRQHandler (void);


#endif /* _INIT_UART_H_ */
