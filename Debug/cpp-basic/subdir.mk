################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cpp-basic/hello.cpp \
../cpp-basic/matmul.cpp \
../cpp-basic/swap.cpp 

OBJS += \
./cpp-basic/hello.o \
./cpp-basic/matmul.o \
./cpp-basic/swap.o 

CPP_DEPS += \
./cpp-basic/hello.d \
./cpp-basic/matmul.d \
./cpp-basic/swap.d 


# Each subdirectory must supply rules for building sources it contributes
cpp-basic/%.o: ../cpp-basic/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: NVCC Compiler'
	/usr/local/cuda-9.0/bin/nvcc -G -g -O0 -gencode arch=compute_50,code=sm_50  -odir "cpp-basic" -M -o "$(@:%.o=%.d)" "$<"
	/usr/local/cuda-9.0/bin/nvcc -G -g -O0 --compile  -x c++ -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


