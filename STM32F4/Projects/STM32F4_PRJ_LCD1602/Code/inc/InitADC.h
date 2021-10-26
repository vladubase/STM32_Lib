#ifndef _INIT_ADC_H_
#define _INIT_ADC_H_

/*******************************************************************************
 *	@name		STM32F4_PRJ_LCD1602
 *	@file 		InitADC.h
 *
 *	@author 	Uladzislau 'vladubase' Dubatouka
 *				<vladubase@gmail.com>
 *	@version	V1.0
 *	@date 		23-September-2021
 ******************************************************************************/


/********************************** Includes **********************************/

#include "stm32f4xx.h"


/*********************************** Defines **********************************/

#define ADC_STEP_VOLTS	((float)	3.3 / 4096)


/***************************** Function  prototypes ***************************/

void InitADC (void);
void InitADCTempSensor (void);
uint16_t ADC1StartConvertion (void);


#endif /* _INIT_ADC_H_ */
