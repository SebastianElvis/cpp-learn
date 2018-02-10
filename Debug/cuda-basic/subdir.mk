################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CU_SRCS += \
../cuda-basic/matmul.cu \
../cuda-basic/vec_add.cu 

OBJS += \
./cuda-basic/matmul.o \
./cuda-basic/vec_add.o 

CU_DEPS += \
./cuda-basic/matmul.d \
./cuda-basic/vec_add.d 


# Each subdirectory must supply rules for building sources it contributes
cuda-basic/%.o: ../cuda-basic/%.cu
	@echo 'Building file: $<'
	@echo 'Invoking: NVCC Compiler'
	/usr/local/cuda-9.0/bin/nvcc -G -g -O0 -gencode arch=compute_50,code=sm_50  -odir "cuda-basic" -M -o "$(@:%.o=%.d)" "$<"
	/usr/local/cuda-9.0/bin/nvcc -G -g -O0 --compile --relocatable-device-code=false -gencode arch=compute_50,code=compute_50 -gencode arch=compute_50,code=sm_50  -x cu -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


