################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SSD_with_one_port.lss \

FLASH_IMAGE += \
SSD_with_one_port.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SSD_with_one_port.elf secondary-outputs

# Tool invocations
SSD_with_one_port.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SSD_with_one_port.map -mmcu=atmega32 -o "SSD_with_one_port.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SSD_with_one_port.lss: SSD_with_one_port.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SSD_with_one_port.elf  >"SSD_with_one_port.lss"
	@echo 'Finished building: $@'
	@echo ' '

SSD_with_one_port.hex: SSD_with_one_port.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SSD_with_one_port.elf  "SSD_with_one_port.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SSD_with_one_port.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SSD_with_one_port.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SSD_with_one_port.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
