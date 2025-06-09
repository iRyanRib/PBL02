/*
 * lcd.h
 *
 * Biblioteca para controle de LCD JHD162A no modo de 4 bits
 * Adaptada para o microcontrolador LPC11U14/201
 * 
 * Grupo 06 - PBL02 - UNIFEI
 *
 * Mapa de pinos conectados ao LCD:
 * LCD Pin | Função         | Pino MCU | Nome no Projeto | Nome no LPC11U14/201
 * --------|----------------|----------|------------------|-------------------------------
 *   1     | GND            | -        | -                | GND
 *   2     | VDD (+5V)      | -        | -                | +5V
 *   3     | VO (Contraste) | 1        | VO               | PIO_25/CT32B0_MAT1
 *   4     | RS             | 3        | RS               | RESET/PIO0_0
 *   5     | R/W            | 38       | R/W              | PIO1_22/RI/MOSI1
 *   6     | E (Enable)     | 40       | E                | PIO_16/AD5/CT32B1_MAT3/WAKEUP
 *  11     | D4             | 42       | D4               | PIO0_23/AD7
 *  12     | D5             | 43       | D5               | PIO1_15/DCD/CT16B0_MAT2/SCK
 *  13     | D6             | 45       | D6               | PIO_17/RTS/CT32B0_CAP0/SCLK
 *  14     | D7             | 48       | D7               | PIO1_16/RI/CT16B0_CAP0
 *  15     | LED+ (+5V)     | -        | -                | +5V via resistor (R6)
 *  16     | LED- (GND)     | -        | -                | GND
 */

#ifndef LCD_H_
#define LCD_H_

#include "chip.h"

/*
 * Definições para os comandos do LCD
 */
#define LCD_CLEAR           0x01    // Limpa o display e retorna o cursor para a posição inicial
#define LCD_HOME            0x02    // Retorna o cursor para a posição inicial
#define LCD_ENTRY_MODE      0x06    // Configuração do modo de entrada: incremento do cursor, sem deslocamento do display
#define LCD_DISPLAY_ON      0x0C    // Display ligado, cursor desligado, sem piscar
#define LCD_DISPLAY_CURSOR  0x0E    // Display ligado, cursor ligado, sem piscar
#define LCD_DISPLAY_BLINK   0x0F    // Display ligado, cursor ligado, piscando
#define LCD_SHIFT_CURSOR_L  0x10    // Desloca o cursor para a esquerda
#define LCD_SHIFT_CURSOR_R  0x14    // Desloca o cursor para a direita
#define LCD_SHIFT_DISPLAY_L 0x18    // Desloca o display para a esquerda
#define LCD_SHIFT_DISPLAY_R 0x1C    // Desloca o display para a direita
#define LCD_4BIT_MODE_1LINE 0x20    // Modo 4 bits, 1 linha, 5x8 pontos
#define LCD_4BIT_MODE       0x28    // Modo 4 bits, 2 linhas, 5x8 pontos
#define LCD_8BIT_MODE_1LINE 0x30    // Modo 8 bits, 1 linha, 5x8 pontos
#define LCD_8BIT_MODE       0x38    // Modo 8 bits, 2 linhas, 5x8 pontos
#define LCD_CGRAM_ADDR      0x40    // Define o endereço da CGRAM (para caracteres personalizados)
#define LCD_DDRAM_ADDR      0x80    // Define o endereço da DDRAM (para posicionamento do cursor)

/*
 * Protótipos de funções
 */

// Funções locais de utilidade
void delay_ms(unsigned int v_uiTempo);                            // Rotina de atraso em milissegundos
void bit_set(volatile uint32_t *p_uiValor, unsigned char v_ucBit); // Define um bit como 1 em um registrador
void bit_clr(volatile uint32_t *p_uiValor, unsigned char v_ucBit); // Define um bit como 0 em um registrador

// Funções principais para controle do LCD
void LCD_iniciar(void);                                           // Inicializa o LCD em modo 4 bits
void LCD_comando(char v_cComando);                                // Envia um comando para o LCD
void LCD_caractere(char v_cCaractere);                            // Envia um caractere para o LCD
void LCD_string(const char *mensagem);                            // Envia uma string para o LCD
void LCD_posicionar(uint8_t linha, uint8_t coluna);               // Posiciona o cursor em uma linha e coluna específicas
void LCD_limpar(void);                                            // Limpa o display do LCD
void LCD_caractere_personalizado(uint8_t local, const uint8_t *dados); // Cria um caractere personalizado


#endif /* LCD_H_ */
