################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Main.c \
../src/uart.c 

OBJS += \
./src/Main.o \
./src/uart.o 

C_DEPS += \
./src/Main.d \
./src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused  -g -DDEBUG=1 -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\RVMSIS" -I"F:\文档\串口助手\评估版本\EVT\EXAM\UART1\src\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

