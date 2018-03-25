################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

CC_SRCS += \
../src/main.cc 

CPP_SRCS += \
../src/sw_tanh_classifier.cpp 

CC_DEPS += \
./src/main.d 

OBJS += \
./src/main.o \
./src/sw_tanh_classifier.o 

CPP_DEPS += \
./src/sw_tanh_classifier.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O0 -g3 -I../../test_dataflow_bsp/ps7_cortexa9_0/include -I"C:\Xilinx\Vivado_HLS\2016.2\include" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=neon -ftree-vectorize -mvectorize-with-neon-quad -mfloat-abi=softfp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O0 -g3 -I../../test_dataflow_bsp/ps7_cortexa9_0/include -I"C:\Xilinx\Vivado_HLS\2016.2\include" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=neon -ftree-vectorize -mvectorize-with-neon-quad -mfloat-abi=softfp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


