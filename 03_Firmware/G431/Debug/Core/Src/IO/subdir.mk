################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/IO/IOHandle.cpp 

OBJS += \
./Core/Src/IO/IOHandle.o 

CPP_DEPS += \
./Core/Src/IO/IOHandle.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/IO/%.o Core/Src/IO/%.su Core/Src/IO/%.cyclo: ../Core/Src/IO/%.cpp Core/Src/IO/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-IO

clean-Core-2f-Src-2f-IO:
	-$(RM) ./Core/Src/IO/IOHandle.cyclo ./Core/Src/IO/IOHandle.d ./Core/Src/IO/IOHandle.o ./Core/Src/IO/IOHandle.su

.PHONY: clean-Core-2f-Src-2f-IO

