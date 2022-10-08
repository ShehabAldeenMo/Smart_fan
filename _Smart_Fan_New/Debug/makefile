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
_Smart_Fan_New.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: _Smart_Fan_New.elf secondary-outputs

# Tool invocations
_Smart_Fan_New.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,_Smart_Fan_New.map -mmcu=atmega32 -o "_Smart_Fan_New.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

_Smart_Fan_New.lss: _Smart_Fan_New.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S _Smart_Fan_New.elf  >"_Smart_Fan_New.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: _Smart_Fan_New.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 _Smart_Fan_New.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) _Smart_Fan_New.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
