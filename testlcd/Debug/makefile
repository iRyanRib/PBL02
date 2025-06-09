################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include nxp_lpcxpresso_11u14_board_lib/src/subdir.mk
-include lpc_chip_11uxx_lib/src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := testlcd
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: testlcd.axf

# Tool invocations
testlcd.axf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\USER\Documents\MCUXpressoIDE_24.12.148\workspace\testlcd\lpc_chip_11uxx_lib\libs" -L"C:\Users\USER\Documents\MCUXpressoIDE_24.12.148\workspace\testlcd\nxp_lpcxpresso_11u14_board_lib" -Xlinker -Map="testlcd.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0 -mthumb -T testlcd_Debug.ld -o "testlcd.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) testlcd.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "testlcd.axf" ; arm-none-eabi-objcopy -v -O binary "testlcd.axf" "testlcd.bin" ; # checksum -p LPC1114_302 -d "testlcd.bin"
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
