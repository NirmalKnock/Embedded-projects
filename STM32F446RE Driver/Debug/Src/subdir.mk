################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/01I2C_Master_Rx_testing.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/01I2C_Master_Rx_testing.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/01I2C_Master_Rx_testing.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/01I2C_Master_Rx_testing.o: ../Src/01I2C_Master_Rx_testing.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DDEBUG -c -I../Inc -I"D:/Embedded C/MCU master 1/STM32F446RE Driver/drivers/inc" -I"D:/Embedded C/MCU master 1/STM32F446RE Driver/drivers/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/01I2C_Master_Rx_testing.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DDEBUG -c -I../Inc -I"D:/Embedded C/MCU master 1/STM32F446RE Driver/drivers/inc" -I"D:/Embedded C/MCU master 1/STM32F446RE Driver/drivers/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DDEBUG -c -I../Inc -I"D:/Embedded C/MCU master 1/STM32F446RE Driver/drivers/inc" -I"D:/Embedded C/MCU master 1/STM32F446RE Driver/drivers/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

