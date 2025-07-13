#ifndef RTC_H
#define RTC_H

#define MCP7940_ADDR 0x6F // I2C address for MCP7940

// adicionar memória read e write


// MCP7940 Registers
#define MCP_REG_SECONDS 0x00
#define MCP_REG_MINUTES 0x01
#define MCP_REG_HOURS   0x02
#define MCP_REG_WEEKDAY 0x03
#define MCP_REG_DAY     0x04
#define MCP_REG_MONTH   0x05
#define MCP_REG_YEAR    0x06

// Conversão BCD <-> Decimal
unsigned char bcdToDec(unsigned char bcd);
unsigned char decToBcd(unsigned char dec);

// Leitura e escrita da SRAM (endereços de 0x20 até 0x5F)
unsigned char mcpReadSram(unsigned char addr);
void mcpWriteSram(unsigned char addr, unsigned char data);

void mcp7940Init(void);
unsigned char mcpReadReg(unsigned char reg);
void mcpWriteReg(unsigned char reg, unsigned char data);

// Leitura dos campos do RTC
#define mcpGetSeconds() (bcdToDec(i2cReadReg(MCP7940_ADDR, MCP_REG_SECONDS)   & 0x7F))
#define mcpGetMinutes()   (bcdToDec(i2cReadReg(MCP7940_ADDR, MCP_REG_MINUTES) & 0x7F))
#define mcpGetHours()     (bcdToDec(i2cReadReg(MCP7940_ADDR, MCP_REG_HOURS)   & 0x3F))
#define mcpGetWeekday()   (bcdToDec(i2cReadReg(MCP7940_ADDR, MCP_REG_WEEKDAY) & 0x07))
#define mcpGetDay()       (bcdToDec(i2cReadReg(MCP7940_ADDR, MCP_REG_DAY)     & 0x3F))
#define mcpGetMonth()     (bcdToDec(i2cReadReg(MCP7940_ADDR, MCP_REG_MONTH)   & 0x1F))
#define mcpGetYear()      (bcdToDec(i2cReadReg(MCP7940_ADDR, MCP_REG_YEAR)))

// Escrita dos campos (usa decToBcd)
#define mcpSetSeconds(v)  (i2cWriteReg(MCP7940_ADDR, MCP_REG_SECONDS, decToBcd(v) | 0x80)) // bit ST = 1
#define mcpSetMinutes(v)  (i2cWriteReg(MCP7940_ADDR, MCP_REG_MINUTES, decToBcd(v)))
#define mcpSetHours(v)    (i2cWriteReg(MCP7940_ADDR, MCP_REG_HOURS,   decToBcd(v)))
#define mcpSetWeekday(v)  (i2cWriteReg(MCP7940_ADDR, MCP_REG_WEEKDAY, decToBcd(v)))
#define mcpSetDay(v)      (i2cWriteReg(MCP7940_ADDR, MCP_REG_DAY,     decToBcd(v)))
#define mcpSetMonth(v)    (i2cWriteReg(MCP7940_ADDR, MCP_REG_MONTH,   decToBcd(v)))
#define mcpSetYear(v)     (i2cWriteReg(MCP7940_ADDR, MCP_REG_YEAR,    decToBcd(v)))

#endif // MCP7940_H
