################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/StdPeriphDriver/CH57x_adc.c \
../Drivers/StdPeriphDriver/CH57x_clk.c \
../Drivers/StdPeriphDriver/CH57x_flash.c \
../Drivers/StdPeriphDriver/CH57x_gpio.c \
../Drivers/StdPeriphDriver/CH57x_pwm.c \
../Drivers/StdPeriphDriver/CH57x_pwr.c \
../Drivers/StdPeriphDriver/CH57x_spi0.c \
../Drivers/StdPeriphDriver/CH57x_sys.c \
../Drivers/StdPeriphDriver/CH57x_timer0.c \
../Drivers/StdPeriphDriver/CH57x_timer1.c \
../Drivers/StdPeriphDriver/CH57x_timer2.c \
../Drivers/StdPeriphDriver/CH57x_timer3.c \
../Drivers/StdPeriphDriver/CH57x_uart0.c \
../Drivers/StdPeriphDriver/CH57x_uart1.c \
../Drivers/StdPeriphDriver/CH57x_uart2.c \
../Drivers/StdPeriphDriver/CH57x_uart3.c \
../Drivers/StdPeriphDriver/CH57x_usbdev.c \
../Drivers/StdPeriphDriver/CH57x_usbhostBase.c \
../Drivers/StdPeriphDriver/CH57x_usbhostClass.c 

OBJS += \
./Drivers/StdPeriphDriver/CH57x_adc.o \
./Drivers/StdPeriphDriver/CH57x_clk.o \
./Drivers/StdPeriphDriver/CH57x_flash.o \
./Drivers/StdPeriphDriver/CH57x_gpio.o \
./Drivers/StdPeriphDriver/CH57x_pwm.o \
./Drivers/StdPeriphDriver/CH57x_pwr.o \
./Drivers/StdPeriphDriver/CH57x_spi0.o \
./Drivers/StdPeriphDriver/CH57x_sys.o \
./Drivers/StdPeriphDriver/CH57x_timer0.o \
./Drivers/StdPeriphDriver/CH57x_timer1.o \
./Drivers/StdPeriphDriver/CH57x_timer2.o \
./Drivers/StdPeriphDriver/CH57x_timer3.o \
./Drivers/StdPeriphDriver/CH57x_uart0.o \
./Drivers/StdPeriphDriver/CH57x_uart1.o \
./Drivers/StdPeriphDriver/CH57x_uart2.o \
./Drivers/StdPeriphDriver/CH57x_uart3.o \
./Drivers/StdPeriphDriver/CH57x_usbdev.o \
./Drivers/StdPeriphDriver/CH57x_usbhostBase.o \
./Drivers/StdPeriphDriver/CH57x_usbhostClass.o 

C_DEPS += \
./Drivers/StdPeriphDriver/CH57x_adc.d \
./Drivers/StdPeriphDriver/CH57x_clk.d \
./Drivers/StdPeriphDriver/CH57x_flash.d \
./Drivers/StdPeriphDriver/CH57x_gpio.d \
./Drivers/StdPeriphDriver/CH57x_pwm.d \
./Drivers/StdPeriphDriver/CH57x_pwr.d \
./Drivers/StdPeriphDriver/CH57x_spi0.d \
./Drivers/StdPeriphDriver/CH57x_sys.d \
./Drivers/StdPeriphDriver/CH57x_timer0.d \
./Drivers/StdPeriphDriver/CH57x_timer1.d \
./Drivers/StdPeriphDriver/CH57x_timer2.d \
./Drivers/StdPeriphDriver/CH57x_timer3.d \
./Drivers/StdPeriphDriver/CH57x_uart0.d \
./Drivers/StdPeriphDriver/CH57x_uart1.d \
./Drivers/StdPeriphDriver/CH57x_uart2.d \
./Drivers/StdPeriphDriver/CH57x_uart3.d \
./Drivers/StdPeriphDriver/CH57x_usbdev.d \
./Drivers/StdPeriphDriver/CH57x_usbhostBase.d \
./Drivers/StdPeriphDriver/CH57x_usbhostClass.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/StdPeriphDriver/%.o: ../Drivers/StdPeriphDriver/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DDEBUG=1 -DBLE_MAC=1 -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\OS\ProtoThread-Core" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\Startup" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Src\APP\include" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\StdPeriphDriver\inc" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\BLE\HAL\include" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\Ld" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\BLE\LIB" -I"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

