################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PrettyPrint/PrettyPrint.cpp 

OBJS += \
./PrettyPrint/PrettyPrint.o 

CPP_DEPS += \
./PrettyPrint/PrettyPrint.d 


# Each subdirectory must supply rules for building sources it contributes
PrettyPrint/%.o: ../PrettyPrint/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


