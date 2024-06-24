################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Src/APP/subdir.mk
-include OS/ProtoThread-Core/transplant_ports/subdir.mk
-include OS/ProtoThread-Core/sys/subdir.mk
-include OS/ProtoThread-Core/lib/subdir.mk
-include OS/ProtoThread-Core/subdir.mk
-include Drivers/StdPeriphDriver/subdir.mk
-include Drivers/BLE/HAL/subdir.mk
-include Core/Startup/subdir.mk
-include Core/RVMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
CH573_PT_Template.hex \

SECONDARY_LIST += \
CH573_PT_Template.lst \

SECONDARY_SIZE += \
CH573_PT_Template.siz \


# All Target
all: CH573_PT_Template.elf secondary-outputs

# Tool invocations
CH573_PT_Template.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -T "F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Core\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -L"../" -L"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\BLE\LIB" -L"F:\文档\串口助手\ProtoThread\ProtoThread-Templates-main\CH573_PT_Template\Drivers\StdPeriphDriver" -Xlinker --print-memory-usage -Wl,-Map,"CH573_PT_Template.map" --specs=nano.specs --specs=nosys.specs -o "CH573_PT_Template.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
CH573_PT_Template.hex: CH573_PT_Template.elf
	@	riscv-none-embed-objcopy -O ihex "CH573_PT_Template.elf"  "CH573_PT_Template.hex"
	@	@
CH573_PT_Template.lst: CH573_PT_Template.elf
	@	riscv-none-embed-objdump --source --all-headers --demangle --line-numbers --wide "CH573_PT_Template.elf" > "CH573_PT_Template.lst"
	@	@
CH573_PT_Template.siz: CH573_PT_Template.elf
	@	riscv-none-embed-size --format=berkeley "CH573_PT_Template.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) CH573_PT_Template.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
