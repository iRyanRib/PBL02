/*
 * Copyright 2022 NXP
 * NXP confidential.
 * This software is owned or controlled by NXP and may only be used strictly
 * in accordance with the applicable license terms.  By expressly accepting
 * such terms or by downloading, installing, activating and/or otherwise using
 * the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 */

#ifdef __USE_CMSIS
#include "LPC11xx.h"
#endif

#include "LPC11xx.h"
#include "system_LPC11xx.h"
#include "adc.h"
#include "bits.h"
#include "buttons.h"
#include "i2c.h"
#include "io.h"
#include "lcd.h"
#include "leds.h"
#include "rtc.h"
#include "serial.h"
#include "utils.h"

int main(void) {

	SystemInit();
	ledsInit();
	buttonsInit();
	serialInit();
	i2cInit();
	lcdInit();

	lcdClear();
	lcdSetCursor(0, 0);
	lcdString("Iniciado OK!");

	ledsShow();

	unsigned int b;
	int caracter;
	unsigned char lastSec = 255;
	// unsigned int lastAdc = 1024;

	// Testar escrita de horário completo
	mcpSetSeconds(0);
	mcpSetMinutes(55);
	mcpSetHours(16);
	mcpSetWeekday(4);  // Ex: quinta-feira
	mcpSetDay(4);
	mcpSetMonth(7);
	mcpSetYear(25);    // 2025

    while(1) {
    	buttonsDebounce();
        b = buttonsRead();

    	if (bitTst(b, BUTTON_UP1_ID)) ledsToggle(LED0);
    	if (bitTst(b, BUTTON_RIGHT1_ID)) ledsToggle(LED1);
    	if (bitTst(b, BUTTON_DOWN1_ID)) ledsToggle(LED2);
    	if (bitTst(b, BUTTON_LEFT1_ID)) ledsToggle(LED3);
    	if (bitTst(b, BUTTON_CONFIRM1_ID)) ledsOffAll();

    	unsigned char endereco = 0x22;
    	unsigned char valorEscrito = 'F';

    	caracter = serialReadChar();
    	if (caracter != -1) {
    		serialSendString("\nRecebido: ");
    		serialSendChar(caracter);

    		switch (caracter) {
    			case '0': ledsToggle(LED0); break;
    			case '1': ledsToggle(LED1); break;
    			case '2': ledsToggle(LED2); break;
    			case '3': ledsToggle(LED3); break;
    			case '4': ledsOnAll();      break;
    			case '5': ledsOffAll();     break;
    			case '6': ledsShow();       break;
    			case '7': mcpWriteSram(endereco, valorEscrito); break;
    			case '8': unsigned char valorLido = mcpReadSram(endereco);  break;
    			case '9': serialSendChar(valorLido); serialSendChar('\n');  break;
    		}
    	}

    	unsigned char s = mcpGetSeconds();
    	if(s != lastSec){
    		lastSec = s;

//    		serialSendDate();
//    		serialSendChar('\n');
//    		serialSendTime();
//    		serialSendChar('\n');
//    		serialSendDateTime();
//    		serialSendChar('\n');

    		// Atualizar LCD
    		lcdSetCursor(0, 0);
    		lcdString("Hora: ");
    		if (mcpGetHours() < 10) lcdChar('0');
    		lcdNumber(mcpGetHours());
    		lcdChar(':');
    		if (mcpGetMinutes() < 10) lcdChar('0');
    		lcdNumber(mcpGetMinutes());
    		lcdChar(':');
    		if (mcpGetSeconds() < 10) lcdChar('0');
    		lcdNumber(mcpGetSeconds());
    		lcdChar(' ');

    		lcdSetCursor(1, 0);
    		lcdString("Data: ");
    		if (mcpGetDay() < 10) lcdChar('0');
    		lcdNumber(mcpGetDay());
    		lcdChar('/');
    		if (mcpGetMonth() < 10) lcdChar('0');
    		lcdNumber(mcpGetMonth());
    		lcdChar('/');
    		lcdNumber(2000 + mcpGetYear());
    	}
    }
    return 0 ;
}
