################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
HSE_calculation.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
HSE_calculation.list \

OBJCOPY_BIN += \
HSE_calculation.bin \


# All Target
all: HSE_calculation.elf secondary-outputs

# Tool invocations
HSE_calculation.elf: $(OBJS) $(USER_OBJS) D:\Embedded\ C\MCU\ master\ 1\HSE_calculation\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "HSE_calculation.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\Embedded C\MCU master 1\HSE_calculation\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="HSE_calculation.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

HSE_calculation.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "HSE_calculation.list"
	@echo 'Finished building: $@'
	@echo ' '

HSE_calculation.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "HSE_calculation.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
