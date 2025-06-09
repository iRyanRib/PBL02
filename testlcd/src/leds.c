/*
 * LEDs.c
 *
 *  Created on: 30 de abr. de 2025
 *      Author: Lucas
 */
#include "leds.h"
#include "chip.h"

void inicializa_leds(void){

	LPC_IOCON->PIO0[12] = 0x081; //
	LPC_IOCON->PIO0[13] = 0x081; //
	LPC_IOCON->PIO0[14] = 0x081; //

	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 0, 12);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 0, 13);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 0, 14);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 1, 13);

}

void acende_leds(int led1,int led2,int led3,int led4){

	Chip_GPIO_SetPinState(LPC_GPIO, 0, 12, led4);
	Chip_GPIO_SetPinState(LPC_GPIO, 0, 13, led3);
	Chip_GPIO_SetPinState(LPC_GPIO, 0, 14, led2);
	Chip_GPIO_SetPinState(LPC_GPIO, 1, 13, led1);

}

