################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS/ProtoThread-Core/sys/ctimer.c \
../OS/ProtoThread-Core/sys/etimer.c \
../OS/ProtoThread-Core/sys/process.c \
../OS/ProtoThread-Core/sys/timer.c 

OBJS += \
./OS/ProtoThread-Core/sys/ctimer.o \
./OS/ProtoThread-Core/sys/etimer.o \
./OS/ProtoThread-Core/sys/process.o \
./OS/ProtoThread-Core/sys/timer.o 

C_DEPS += \
./OS/ProtoThread-Core/sys/ctimer.d \
./OS/ProtoThread-Core/sys/etimer.d \
./OS/ProtoThread-Core/sys/process.d \
./OS/ProtoThread-Core/sys/timer.d 


# Each subdirectory must supply rules for building sources it contributes
OS/ProtoThread-Core/sys/%.o: ../OS/ProtoThread-Core/sys/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DBLE_MAC=1 -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\OS\ProtoThread-Core" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\Startup" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Src\APP\include" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\StdPeriphDriver\inc" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\BLE\HAL\include" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\Ld" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\BLE\LIB" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

