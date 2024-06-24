################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS/ProtoThread-Core/transplant_ports/pt_ports.c 

OBJS += \
./OS/ProtoThread-Core/transplant_ports/pt_ports.o 

C_DEPS += \
./OS/ProtoThread-Core/transplant_ports/pt_ports.d 


# Each subdirectory must supply rules for building sources it contributes
OS/ProtoThread-Core/transplant_ports/%.o: ../OS/ProtoThread-Core/transplant_ports/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DBLE_MAC=1 -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\OS\ProtoThread-Core" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\Startup" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Src\APP\include" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\StdPeriphDriver\inc" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\BLE\HAL\include" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\Ld" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\BLE\LIB" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

