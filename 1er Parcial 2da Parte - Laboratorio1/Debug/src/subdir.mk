################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/1er\ Parcial\ -\ Laboratorio.c 

C_DEPS += \
./src/1er\ Parcial\ -\ Laboratorio.d 

OBJS += \
./src/1er\ Parcial\ -\ Laboratorio.o 


# Each subdirectory must supply rules for building sources it contributes
src/1er\ Parcial\ -\ Laboratorio.o: ../src/1er\ Parcial\ -\ Laboratorio.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/1er Parcial - Laboratorio.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/1er\ Parcial\ -\ Laboratorio.d ./src/1er\ Parcial\ -\ Laboratorio.o

.PHONY: clean-src

