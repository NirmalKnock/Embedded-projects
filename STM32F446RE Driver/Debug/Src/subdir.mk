################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/012i2C_Master_Rx_testingIT.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/012i2C_Master_Rx_testingIT.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/012i2C_Master_Rx_testingIT.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/012i2C_Master_Rx_testingIT.o: ../Src/012i2C_Master_Rx_testingIT.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DDEBUG -c -I../Inc -I"D:/Embedded C/MCU master 1/STM32F446RE Driver/drivers/inc" -I"D:/Embedded C/MCU master 1/STM32F446RE Driver/drivers/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/012i2C_Master_Rx_testingIT.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DDEBUG -c -I../Inc -I"D:/Embedded C/MCU master 1/STM32F446RE Driver/drivers/inc" -I"D:/Embedded C/MCU master 1/STM32F446RE Driver/drivers/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DDEBUG -c -I../Inc -I"D:/Embedded C/MCU master 1/STM32F446RE Driver/drivers/inc" -I"D:/Embedded C/MCU master 1/STM32F446RE Driver/drivers/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

