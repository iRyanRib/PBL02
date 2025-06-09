/*
**
** Main.c for LPC1114FBD48/302
**
** Description:
** This program interfaces with a 16x2 JHD162A LCD in 4-bit mode.
**
** New Pin Mapping for LCD and LPC1114FBD48/302:
** LCD Pin | Função         | MCU Pin | Nome no LPC1114FBD48/302
** --------|----------------|---------|-------------------------------
** 4     | RS             | 34      | R/PIO1_1/AD2/CT32B1_MAT0
** 5     | R/W            | -       | GND (Hardwired)
** 6     | E (Enable)     | 33      | R/PIO1_0/AD1/CT32B1_CAP0
** 11     | D4             | 32      | R/PIO0_11/AD0/CT32B0_MAT3
** 12     | D5             | 31      | PIO2_11/SCK0/CT16B0_CAP1
** 13     | D6             | 30      | PIO1_10/AD5/CT32B1_MAT1/MISO1
** 14     | D7             | 28      | PIO0_9/MOSI0/CT16B0_MAT1
**
** Original Author: Prof. Rodrigo de Paula Rodrigues (Universidade Federal de Itajubá)
** Modification Date: 2025-06-01
** Modified for LPC1114FBD48/302 and 4-bit LCD mode with correct IOCON for R_PIO pins.
**
**********************************************************************/

#include <LPC11xx.h>            /* LPC11xx Peripheral Registers */
#include "system_LPC11xx.h"     /* System Initialization */

// Define LCD Control and Data Pins based on LPC1114FBD48/302 mapping
// Control Pins
#define LCD_PIN_RS              1       // PIO1_1 (Pin 34 on LQFP48 - R/PIO1_1)
#define LCD_PORT_RS             LPC_GPIO1
#define LCD_IOCON_RS_REG        LPC_IOCON->R_PIO1_1 // Corrected: R_PIO register

#define LCD_PIN_E               0       // PIO1_0 (Pin 33 on LQFP48 - R/PIO1_0)
#define LCD_PORT_E              LPC_GPIO1
#define LCD_IOCON_E_REG         LPC_IOCON->R_PIO1_0  // Corrected: R_PIO register

// Data Pins (D4-D7 for 4-bit mode)
#define LCD_PIN_D4              5      // PIO0_11 (Pin 32 on LQFP48 - R/PIO0_11)
#define LCD_PORT_D4             LPC_GPIO3
#define LCD_IOCON_D4_REG        LPC_IOCON->PIO3_5 // Corrected: R_PIO register

#define LCD_PIN_D5              11      // PIO2_11 (Pin 31 on LQFP48 - PIO2_11)
#define LCD_PORT_D5             LPC_GPIO2
#define LCD_IOCON_D5_REG        LPC_IOCON->PIO2_11   // Standard PIO register

#define LCD_PIN_D6              10      // PIO1_10 (Pin 30 on LQFP48 - PIO1_10)
#define LCD_PORT_D6             LPC_GPIO1
#define LCD_IOCON_D6_REG        LPC_IOCON->PIO1_10   // Standard PIO register

#define LCD_PIN_D7              9       // PIO0_9 (Pin 28 on LQFP48 - PIO0_9)
#define LCD_PORT_D7             LPC_GPIO0
#define LCD_IOCON_D7_REG        LPC_IOCON->PIO0_9    // Standard PIO register


// Prototypes
void bit_set( volatile uint32_t *p_uiValor, unsigned char v_ucBit );
void bit_clr( volatile uint32_t *p_uiValor, unsigned char v_ucBit );
void delay_us_calibrated( unsigned int us );
void delay_ms( unsigned int ms );
void LCD_pulse_E( void );
void LCD_write_4bit_mode( unsigned char nibble_to_send );
void LCD_comando( char v_cComando );
void LCD_caractere( char v_cCaractere );
void LCD_iniciar( void );


int main(void)
{
    // SystemInit (CMSIS) configures the CLOCK to 48 MHz from 12 MHz crystal + PLL.

    // Enable clock for GPIO and IOCON
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6); // Enable GPIO and IOCON clocks
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);
    // Configure IOCON for LCD pins
    // For R_PIOx_y pins (RS, E, D4), FUNC must be 001 for GPIO. ADMODE=0 (Digital).
    // For standard PIOx_y pins (D5, D6, D7), FUNC is 000 for GPIO. ADMODE=0 (Digital) if applicable.
    // Values set Hysteresis OFF, Pull-up/down disabled.

    // R_PIO pins: value 0x01 (FUNC=1, ADMODE=0, HYS=0, PULL=0)
    LCD_IOCON_RS_REG = 0xC1; // R_PIO1_1 (RS)
    LCD_IOCON_E_REG  = 0xC1; // R_PIO1_0 (E)
    LCD_IOCON_D4_REG = 0x00;
    LCD_IOCON_D5_REG = 0x00;
    LCD_IOCON_D6_REG = 0xC0;
	LCD_IOCON_D7_REG = 0xC0;

    LCD_PORT_E->DIR |= (1 << LCD_PIN_E);
    LCD_PORT_RS->DIR |= (1 << LCD_PIN_RS);
    LCD_PORT_D4->DIR |= (1 << LCD_PIN_D4);
    LCD_PORT_D5->DIR |= (1 << LCD_PIN_D5);
    LCD_PORT_D6->DIR |= (1 << LCD_PIN_D6);
    LCD_PORT_D7->DIR |= (1 << LCD_PIN_D7);


    // Initialize LCD
    LCD_iniciar();

    // Send text "ELT031" to LCD
    LCD_caractere('E');
    LCD_caractere('L');
    LCD_caractere('T');
    LCD_caractere('0');
    LCD_caractere('3');
    LCD_caractere('1');

    LCD_comando(0xC0); // Move cursor to the second line

    // Send text "TESTE DO LCD"
//    LCD_caractere('T');
//    LCD_caractere('E');
//    LCD_caractere('S');
//    LCD_caractere('T');
//    LCD_caractere('E');
//    LCD_caractere(' ');
//    LCD_caractere('D');
//    LCD_caractere('O');
//    LCD_caractere(' ');
//    LCD_caractere('L');
//    LCD_caractere('C');
//    LCD_caractere('D');

    // Main loop
    while (1)
    {
        // Application code
    }
    // return 0; // Unreachable
}

// bit_set: Sets a specific bit in a 32-bit register
void bit_set( volatile uint32_t *p_uiValor, unsigned char v_ucBit )
{
	(*p_uiValor) |= (1 << v_ucBit);
}

// bit_clr: Clears a specific bit in a 32-bit register
void bit_clr( volatile uint32_t *p_uiValor, unsigned char v_ucBit )
{
	(*p_uiValor) &= ~(1 << v_ucBit);
}

// delay_us_calibrated: Approximate microsecond delay
void delay_us_calibrated( unsigned int us )
{
    volatile unsigned int i, j;
    for (i = 0; i < us; i++) {
        for (j = 0; j < 6; j++) { // Adjust '6' based on calibration for ~1us at 48MHz
            __NOP(); __NOP(); __NOP(); __NOP();
        }
    }
}

// delay_ms: Approximate millisecond delay
void delay_ms( unsigned int v_uiTempo )
{
	unsigned int vuiI1;

	do
	{
			// Gerar um atraso aproximado a 1 milissegundo
			for( vuiI1 = 0; vuiI1 < 3000; vuiI1++ );

			v_uiTempo--;

	} while( v_uiTempo > 0 );

}

// LCD_pulse_E: Pulses the Enable pin of the LCD
void LCD_pulse_E( void )
{
    //delay_us_calibrated(1);
    bit_set( &LCD_PORT_E->DATA, LCD_PIN_E );
    delay_us_calibrated(10); // E pulse width >450ns
    bit_clr( &LCD_PORT_E->DATA, LCD_PIN_E );
   // delay_us_calibrated(1);
}

// LCD_write_4bit_mode: Sends a 4-bit nibble to D4-D7 and pulses E
void LCD_write_4bit_mode( unsigned char nibble_to_send )
{
    if (nibble_to_send & 0x01) bit_set(&LCD_PORT_D4->DATA, LCD_PIN_D4);
    else bit_clr(&LCD_PORT_D4->DATA, LCD_PIN_D4);

    if (nibble_to_send & 0x02) bit_set(&LCD_PORT_D5->DATA, LCD_PIN_D5);
    else bit_clr(&LCD_PORT_D5->DATA, LCD_PIN_D5);

    if (nibble_to_send & 0x04) bit_set(&LCD_PORT_D6->DATA, LCD_PIN_D6);
    else bit_clr(&LCD_PORT_D6->DATA, LCD_PIN_D6);

    if (nibble_to_send & 0x08) bit_set(&LCD_PORT_D7->DATA, LCD_PIN_D7);
    else bit_clr(&LCD_PORT_D7->DATA, LCD_PIN_D7);

    LCD_pulse_E();
}

// LCD_comando: Sends a command byte to the LCD in 4-bit mode
void LCD_comando( char v_cComando )
{
    bit_clr( &LCD_PORT_RS->DATA, LCD_PIN_RS );

    LCD_write_4bit_mode( (v_cComando >> 4) & 0x0F );
    delay_ms(2);
    LCD_write_4bit_mode( v_cComando & 0x0F );

    if (v_cComando == 0x01 || v_cComando == 0x02 || v_cComando == 0x03) {
    	delay_ms(5);
    }
}

// LCD_caractere: Sends a data byte (character) to the LCD in 4-bit mode
void LCD_caractere( char v_cCaractere )
{
    bit_set( &LCD_PORT_RS->DATA, LCD_PIN_RS );

    LCD_write_4bit_mode( (v_cCaractere >> 4)& 0x0F );
    delay_us_calibrated(100);
    LCD_write_4bit_mode( v_cCaractere & 0x0F );

    delay_us_calibrated(100);
}

// LCD_iniciar: Initializes the LCD for 4-bit operation
void LCD_iniciar( void )
{
    bit_clr( &LCD_PORT_RS->DATA, LCD_PIN_RS );
    bit_clr( &LCD_PORT_E->DATA, LCD_PIN_E );

    delay_us_calibrated(500);

    LCD_comando(0x03);
    delay_ms(5);
    LCD_comando(0x03);
    delay_ms(5);
    LCD_comando(0x03);
    delay_ms(5);

    LCD_comando(0x28); // Function Set: 4-bit, 2 lines, 5x8 dots
    delay_ms(10);
    LCD_comando(0x0F); // Display ON, Cursor ON, Blink ON
    delay_ms(10);
    LCD_comando(0x01); // Clear Display
    delay_ms(10);
    LCD_comando(0x06); // Entry Mode Set
    delay_ms(10);
}
