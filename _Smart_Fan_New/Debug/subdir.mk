################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prg.c \
../DC_MOTOR.c \
../DIO_prg.c \
../EX_INT_prg.c \
../INTERRUPT_prg.c \
../LCD_prg.c \
../main.c 

OBJS += \
./ADC_prg.o \
./DC_MOTOR.o \
./DIO_prg.o \
./EX_INT_prg.o \
./INTERRUPT_prg.o \
./LCD_prg.o \
./main.o 

C_DEPS += \
./ADC_prg.d \
./DC_MOTOR.d \
./DIO_prg.d \
./EX_INT_prg.d \
./INTERRUPT_prg.d \
./LCD_prg.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


