################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS/ProtoThread-Core/lib/list.c \
../OS/ProtoThread-Core/lib/memb.c \
../OS/ProtoThread-Core/lib/ringbuf.c 

OBJS += \
./OS/ProtoThread-Core/lib/list.o \
./OS/ProtoThread-Core/lib/memb.o \
./OS/ProtoThread-Core/lib/ringbuf.o 

C_DEPS += \
./OS/ProtoThread-Core/lib/list.d \
./OS/ProtoThread-Core/lib/memb.d \
./OS/ProtoThread-Core/lib/ringbuf.d 


# Each subdirectory must supply rules for building sources it contributes
OS/ProtoThread-Core/lib/%.o: ../OS/ProtoThread-Core/lib/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DBLE_MAC=1 -I"F:\�ĵ�\��������\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\OS\ProtoThread-Core" -I"F:\�ĵ�\��������\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\Startup" -I"F:\�ĵ�\��������\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Src\APP\include" -I"F:\�ĵ�\��������\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\StdPeriphDriver\inc" -I"F:\�ĵ�\��������\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\BLE\HAL\include" -I"F:\�ĵ�\��������\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\Ld" -I"F:\�ĵ�\��������\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\BLE\LIB" -I"F:\�ĵ�\��������\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

