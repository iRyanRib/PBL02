################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lpc_chip_11uxx_lib/src/adc_1125.c \
../lpc_chip_11uxx_lib/src/adc_11xx.c \
../lpc_chip_11uxx_lib/src/chip_11xx.c \
../lpc_chip_11uxx_lib/src/clock_11xx.c \
../lpc_chip_11uxx_lib/src/gpio_11xx_1.c \
../lpc_chip_11uxx_lib/src/gpio_11xx_2.c \
../lpc_chip_11uxx_lib/src/gpiogroup_11xx.c \
../lpc_chip_11uxx_lib/src/i2c_11xx.c \
../lpc_chip_11uxx_lib/src/iocon_11xx.c \
../lpc_chip_11uxx_lib/src/pinint_11xx.c \
../lpc_chip_11uxx_lib/src/pmu_11xx.c \
../lpc_chip_11uxx_lib/src/ring_buffer.c \
../lpc_chip_11uxx_lib/src/ssp_11xx.c \
../lpc_chip_11uxx_lib/src/sysctl_11xx.c \
../lpc_chip_11uxx_lib/src/sysinit_11xx.c \
../lpc_chip_11uxx_lib/src/timer_11xx.c \
../lpc_chip_11uxx_lib/src/uart_11xx.c \
../lpc_chip_11uxx_lib/src/wwdt_11xx.c 

C_DEPS += \
./lpc_chip_11uxx_lib/src/adc_1125.d \
./lpc_chip_11uxx_lib/src/adc_11xx.d \
./lpc_chip_11uxx_lib/src/chip_11xx.d \
./lpc_chip_11uxx_lib/src/clock_11xx.d \
./lpc_chip_11uxx_lib/src/gpio_11xx_1.d \
./lpc_chip_11uxx_lib/src/gpio_11xx_2.d \
./lpc_chip_11uxx_lib/src/gpiogroup_11xx.d \
./lpc_chip_11uxx_lib/src/i2c_11xx.d \
./lpc_chip_11uxx_lib/src/iocon_11xx.d \
./lpc_chip_11uxx_lib/src/pinint_11xx.d \
./lpc_chip_11uxx_lib/src/pmu_11xx.d \
./lpc_chip_11uxx_lib/src/ring_buffer.d \
./lpc_chip_11uxx_lib/src/ssp_11xx.d \
./lpc_chip_11uxx_lib/src/sysctl_11xx.d \
./lpc_chip_11uxx_lib/src/sysinit_11xx.d \
./lpc_chip_11uxx_lib/src/timer_11xx.d \
./lpc_chip_11uxx_lib/src/uart_11xx.d \
./lpc_chip_11uxx_lib/src/wwdt_11xx.d 

OBJS += \
./lpc_chip_11uxx_lib/src/adc_1125.o \
./lpc_chip_11uxx_lib/src/adc_11xx.o \
./lpc_chip_11uxx_lib/src/chip_11xx.o \
./lpc_chip_11uxx_lib/src/clock_11xx.o \
./lpc_chip_11uxx_lib/src/gpio_11xx_1.o \
./lpc_chip_11uxx_lib/src/gpio_11xx_2.o \
./lpc_chip_11uxx_lib/src/gpiogroup_11xx.o \
./lpc_chip_11uxx_lib/src/i2c_11xx.o \
./lpc_chip_11uxx_lib/src/iocon_11xx.o \
./lpc_chip_11uxx_lib/src/pinint_11xx.o \
./lpc_chip_11uxx_lib/src/pmu_11xx.o \
./lpc_chip_11uxx_lib/src/ring_buffer.o \
./lpc_chip_11uxx_lib/src/ssp_11xx.o \
./lpc_chip_11uxx_lib/src/sysctl_11xx.o \
./lpc_chip_11uxx_lib/src/sysinit_11xx.o \
./lpc_chip_11uxx_lib/src/timer_11xx.o \
./lpc_chip_11uxx_lib/src/uart_11xx.o \
./lpc_chip_11uxx_lib/src/wwdt_11xx.o 


# Each subdirectory must supply rules for building sources it contributes
lpc_chip_11uxx_lib/src/%.o: ../lpc_chip_11uxx_lib/src/%.c lpc_chip_11uxx_lib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DNDEBUG -D__CODE_RED -DCORE_M0 -D__LPC11XX__ -D__REDLIB__ -I"D:\Documentos\Área de Trabalho\pbl\pbl02-main\pbl02-main\nxp_lpcxpresso_11u14_board_lib\inc" -I"D:\Documentos\Área de Trabalho\pbl\pbl02-main\pbl02-main\inc" -I"D:\Documentos\Área de Trabalho\pbl\pbl02-main\pbl02-main\lpc_chip_11uxx_lib\inc" -Os -fno-common -g -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lpc_chip_11uxx_lib-2f-src

clean-lpc_chip_11uxx_lib-2f-src:
	-$(RM) ./lpc_chip_11uxx_lib/src/adc_1125.d ./lpc_chip_11uxx_lib/src/adc_1125.o ./lpc_chip_11uxx_lib/src/adc_11xx.d ./lpc_chip_11uxx_lib/src/adc_11xx.o ./lpc_chip_11uxx_lib/src/chip_11xx.d ./lpc_chip_11uxx_lib/src/chip_11xx.o ./lpc_chip_11uxx_lib/src/clock_11xx.d ./lpc_chip_11uxx_lib/src/clock_11xx.o ./lpc_chip_11uxx_lib/src/gpio_11xx_1.d ./lpc_chip_11uxx_lib/src/gpio_11xx_1.o ./lpc_chip_11uxx_lib/src/gpio_11xx_2.d ./lpc_chip_11uxx_lib/src/gpio_11xx_2.o ./lpc_chip_11uxx_lib/src/gpiogroup_11xx.d ./lpc_chip_11uxx_lib/src/gpiogroup_11xx.o ./lpc_chip_11uxx_lib/src/i2c_11xx.d ./lpc_chip_11uxx_lib/src/i2c_11xx.o ./lpc_chip_11uxx_lib/src/iocon_11xx.d ./lpc_chip_11uxx_lib/src/iocon_11xx.o ./lpc_chip_11uxx_lib/src/pinint_11xx.d ./lpc_chip_11uxx_lib/src/pinint_11xx.o ./lpc_chip_11uxx_lib/src/pmu_11xx.d ./lpc_chip_11uxx_lib/src/pmu_11xx.o ./lpc_chip_11uxx_lib/src/ring_buffer.d ./lpc_chip_11uxx_lib/src/ring_buffer.o ./lpc_chip_11uxx_lib/src/ssp_11xx.d ./lpc_chip_11uxx_lib/src/ssp_11xx.o ./lpc_chip_11uxx_lib/src/sysctl_11xx.d ./lpc_chip_11uxx_lib/src/sysctl_11xx.o ./lpc_chip_11uxx_lib/src/sysinit_11xx.d ./lpc_chip_11uxx_lib/src/sysinit_11xx.o ./lpc_chip_11uxx_lib/src/timer_11xx.d ./lpc_chip_11uxx_lib/src/timer_11xx.o ./lpc_chip_11uxx_lib/src/uart_11xx.d ./lpc_chip_11uxx_lib/src/uart_11xx.o ./lpc_chip_11uxx_lib/src/wwdt_11xx.d ./lpc_chip_11uxx_lib/src/wwdt_11xx.o

.PHONY: clean-lpc_chip_11uxx_lib-2f-src

