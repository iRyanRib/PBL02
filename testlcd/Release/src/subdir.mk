################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc11xx.c \
../src/crp.c \
../src/leds.c \
../src/testlcd.c 

C_DEPS += \
./src/cr_startup_lpc11xx.d \
./src/crp.d \
./src/leds.d \
./src/testlcd.d 

OBJS += \
./src/cr_startup_lpc11xx.o \
./src/crp.o \
./src/leds.o \
./src/testlcd.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DNDEBUG -D__CODE_RED -DCORE_M0 -D__LPC11XX__ -D__REDLIB__ -I"D:\Documentos\Área de Trabalho\pbl\pbl02-main\pbl02-main\nxp_lpcxpresso_11u14_board_lib\inc" -I"D:\Documentos\Área de Trabalho\pbl\pbl02-main\pbl02-main\inc" -I"D:\Documentos\Área de Trabalho\pbl\pbl02-main\pbl02-main\lpc_chip_11uxx_lib\inc" -Os -fno-common -g -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/cr_startup_lpc11xx.d ./src/cr_startup_lpc11xx.o ./src/crp.d ./src/crp.o ./src/leds.d ./src/leds.o ./src/testlcd.d ./src/testlcd.o

.PHONY: clean-src

