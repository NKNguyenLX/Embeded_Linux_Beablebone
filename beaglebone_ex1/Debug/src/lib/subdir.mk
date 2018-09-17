################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lib/EasyDriver.cpp \
../src/lib/SimpleGPIO.cpp \
../src/lib/core.cpp \
../src/lib/pwm.cpp \
../src/lib/uart.cpp 

OBJS += \
./src/lib/EasyDriver.o \
./src/lib/SimpleGPIO.o \
./src/lib/core.o \
./src/lib/pwm.o \
./src/lib/uart.o 

CPP_DEPS += \
./src/lib/EasyDriver.d \
./src/lib/SimpleGPIO.d \
./src/lib/core.d \
./src/lib/pwm.d \
./src/lib/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/%.o: ../src/lib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabi-g++ -I/usr/arm-linux-gnueabi/include/c++/5 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


