################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/AppMain/ApplicationMain.cpp 

OBJS += \
./Core/Src/AppMain/ApplicationMain.o 

CPP_DEPS += \
./Core/Src/AppMain/ApplicationMain.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/AppMain/%.o Core/Src/AppMain/%.su Core/Src/AppMain/%.cyclo: ../Core/Src/AppMain/%.cpp Core/Src/AppMain/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L412xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-AppMain

clean-Core-2f-Src-2f-AppMain:
	-$(RM) ./Core/Src/AppMain/ApplicationMain.cyclo ./Core/Src/AppMain/ApplicationMain.d ./Core/Src/AppMain/ApplicationMain.o ./Core/Src/AppMain/ApplicationMain.su

.PHONY: clean-Core-2f-Src-2f-AppMain

