################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/Src/Stm32f44xx_gpio.c 

OBJS += \
./Driver/Src/Stm32f44xx_gpio.o 

C_DEPS += \
./Driver/Src/Stm32f44xx_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/Src/%.o: ../Driver/Src/%.c Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Ad_Docs/Embedded Systems/git/driver_stm32f44/stm32_driver_development/driver_stm32f446xx/Driver/Inc" -I"C:/Ad_Docs/Embedded Systems/git/driver_stm32f44/stm32_driver_development/driver_stm32f446xx/Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver-2f-Src

clean-Driver-2f-Src:
	-$(RM) ./Driver/Src/Stm32f44xx_gpio.d ./Driver/Src/Stm32f44xx_gpio.o

.PHONY: clean-Driver-2f-Src

