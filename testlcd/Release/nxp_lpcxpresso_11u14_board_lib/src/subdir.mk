################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../nxp_lpcxpresso_11u14_board_lib/src/board.c \
../nxp_lpcxpresso_11u14_board_lib/src/board_sysinit.c 

C_DEPS += \
./nxp_lpcxpresso_11u14_board_lib/src/board.d \
./nxp_lpcxpresso_11u14_board_lib/src/board_sysinit.d 

OBJS += \
./nxp_lpcxpresso_11u14_board_lib/src/board.o \
./nxp_lpcxpresso_11u14_board_lib/src/board_sysinit.o 


# Each subdirectory must supply rules for building sources it contributes
nxp_lpcxpresso_11u14_board_lib/src/%.o: ../nxp_lpcxpresso_11u14_board_lib/src/%.c nxp_lpcxpresso_11u14_board_lib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DNDEBUG -D__CODE_RED -DCORE_M0 -D__LPC11XX__ -D__REDLIB__ -I"D:\Documentos\Área de Trabalho\pbl\pbl02-main\pbl02-main\nxp_lpcxpresso_11u14_board_lib\inc" -I"D:\Documentos\Área de Trabalho\pbl\pbl02-main\pbl02-main\inc" -I"D:\Documentos\Área de Trabalho\pbl\pbl02-main\pbl02-main\lpc_chip_11uxx_lib\inc" -Os -fno-common -g -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-nxp_lpcxpresso_11u14_board_lib-2f-src

clean-nxp_lpcxpresso_11u14_board_lib-2f-src:
	-$(RM) ./nxp_lpcxpresso_11u14_board_lib/src/board.d ./nxp_lpcxpresso_11u14_board_lib/src/board.o ./nxp_lpcxpresso_11u14_board_lib/src/board_sysinit.d ./nxp_lpcxpresso_11u14_board_lib/src/board_sysinit.o

.PHONY: clean-nxp_lpcxpresso_11u14_board_lib-2f-src

