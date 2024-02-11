################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/Drive/DriveControl.cpp 

OBJS += \
./Core/Src/Drive/DriveControl.o 

CPP_DEPS += \
./Core/Src/Drive/DriveControl.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Drive/%.o Core/Src/Drive/%.su Core/Src/Drive/%.cyclo: ../Core/Src/Drive/%.cpp Core/Src/Drive/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L412xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Drive

clean-Core-2f-Src-2f-Drive:
	-$(RM) ./Core/Src/Drive/DriveControl.cyclo ./Core/Src/Drive/DriveControl.d ./Core/Src/Drive/DriveControl.o ./Core/Src/Drive/DriveControl.su

.PHONY: clean-Core-2f-Src-2f-Drive

