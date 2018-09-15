################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/EasyDriver.cpp \
../src/SimpleGPIO.cpp \
../src/TestApplication.cpp \
../src/beagle_test.cpp \
../src/pwm.cpp \
../src/uart.cpp 

OBJS += \
./src/EasyDriver.o \
./src/SimpleGPIO.o \
./src/TestApplication.o \
./src/beagle_test.o \
./src/pwm.o \
./src/uart.o 

CPP_DEPS += \
./src/EasyDriver.d \
./src/SimpleGPIO.d \
./src/TestApplication.d \
./src/beagle_test.d \
./src/pwm.d \
./src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabi-g++ -I/usr/arm-linux-gnueabi/include/c++/5 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


