################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../struct_pointrer.c 

OBJS += \
./struct_pointrer.o 

C_DEPS += \
./struct_pointrer.d 


# Each subdirectory must supply rules for building sources it contributes
struct_pointrer.o: ../struct_pointrer.c
	arm-none-eabi-gcc "$<" -std=gnu11 -g3 -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"struct_pointrer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

