/*******************************************************************************
 *	@name		STM32F4_PRJ_LCD1602
 *	@file 		main.c
 *
 *	@author 	Uladzislau 'vladubase' Dubatouka
 *				<vladubase@gmail.com>.
 *	@version	V1.0
 *	@date 		25-October-2021
 ******************************************************************************/

#include "main.h"


/************************************ Main ************************************/

int main (void) {
	// DEFINITION OF VARIABLES
	uint16_t MCU_temp_ADC_value = 0;
	float MCU_temp_voltage = 0.0;
	float MCU_temp_real = 0.0;
	char MCU_temp_str[4];
	
	// MICROCONTROLLER INITIALIZATION
	InitRCC ();
	InitSYS ();
	InitSWD ();	
	InitGPIO ();
	InitADC ();
	// PERIPHERAL INITIALIZATION
	InitLCD1602 ();
	
	LCDClearScreen ();
	LCDSetPositionXY (0, 0);
	
	// LCD MENU
	LCDSetPositionXY (0, 0);
	LCDSendString ("MCU Temp:");
	LCDSetPositionXY (14, 0);		LCDSendChar (0xDF);				// Print symbol '°'.
	LCDSetPositionXY (15, 0);		LCDSendChar ('C');
	
	// MAIN CYCLE
	while (true) {
		MCU_temp_ADC_value = ADC1StartConvertion ();				// 12-bit number.
		MCU_temp_voltage = MCU_temp_ADC_value * ADC_STEP_VOLTS;		// Voltage on ADC.
		MCU_temp_real = ((MCU_temp_voltage - 0.76) / 0.0025) + 25;	// Temperature.
		
		sprintf (MCU_temp_str, "%.1f", MCU_temp_real);				// Format xx.x.
		LCDSetPositionXY (10, 0);	LCDSendString(MCU_temp_str);	// Write number of degrees.
		
		delay_ms (1000);
	}
}
