################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_adc.c \
F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_clk.c \
F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_flash.c \
F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_gpio.c \
F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_pwr.c \
F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_sys.c \
F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart0.c \
F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart1.c 

OBJS += \
./StdPeriphDriver/CH57x_adc.o \
./StdPeriphDriver/CH57x_clk.o \
./StdPeriphDriver/CH57x_flash.o \
./StdPeriphDriver/CH57x_gpio.o \
./StdPeriphDriver/CH57x_pwr.o \
./StdPeriphDriver/CH57x_sys.o \
./StdPeriphDriver/CH57x_uart0.o \
./StdPeriphDriver/CH57x_uart1.o 

C_DEPS += \
./StdPeriphDriver/CH57x_adc.d \
./StdPeriphDriver/CH57x_clk.d \
./StdPeriphDriver/CH57x_flash.d \
./StdPeriphDriver/CH57x_gpio.d \
./StdPeriphDriver/CH57x_pwr.d \
./StdPeriphDriver/CH57x_sys.d \
./StdPeriphDriver/CH57x_uart0.d \
./StdPeriphDriver/CH57x_uart1.d 


# Each subdirectory must supply rules for building sources it contributes
StdPeriphDriver/CH57x_adc.o: F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused  -g -DDEBUG=1 -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\RVMSIS" -I"F:\文档\串口助手\评估版本\EVT\EXAM\UART1\src\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_clk.o: F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_clk.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused  -g -DDEBUG=1 -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\RVMSIS" -I"F:\文档\串口助手\评估版本\EVT\EXAM\UART1\src\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_flash.o: F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused  -g -DDEBUG=1 -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\RVMSIS" -I"F:\文档\串口助手\评估版本\EVT\EXAM\UART1\src\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_gpio.o: F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused  -g -DDEBUG=1 -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\RVMSIS" -I"F:\文档\串口助手\评估版本\EVT\EXAM\UART1\src\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_pwr.o: F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_pwr.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused  -g -DDEBUG=1 -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\RVMSIS" -I"F:\文档\串口助手\评估版本\EVT\EXAM\UART1\src\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_sys.o: F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_sys.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused  -g -DDEBUG=1 -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\RVMSIS" -I"F:\文档\串口助手\评估版本\EVT\EXAM\UART1\src\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_uart0.o: F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart0.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused  -g -DDEBUG=1 -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\RVMSIS" -I"F:\文档\串口助手\评估版本\EVT\EXAM\UART1\src\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_uart1.o: F:/文档/串口助手/评估版本/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart1.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused  -g -DDEBUG=1 -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\文档\串口助手\评估版本\EVT\EXAM\SRC\RVMSIS" -I"F:\文档\串口助手\评估版本\EVT\EXAM\UART1\src\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

