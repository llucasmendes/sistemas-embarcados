SHELL			:= /bin/bash
ARM_PREFIX      := arm-none-eabi
ARM_AS          := $(ARM_PREFIX)-as
ARM_CC          := $(ARM_PREFIX)-gcc
ARM_LD          := $(ARM_PREFIX)-ld
ARM_OC          := $(ARM_PREFIX)-objcopy
ARM_AS_OPTIONS	:= -mcpu=cortex-m3 -mthumb -g
ARM_CC_OPTIONS	:= -Wall -Os -mcpu=cortex-m3 -mthumb -g -nostdlib -nostartfiles
C_SOURCES       := echo.c
S_SOURCES       :=
PROJECT_NAME    := echo

all: $(PROJECT_NAME).bin
clean:
	@rm -rf *.o *.elf *.bin
debug: $(PROJECT_NAME).bin
	qemu-system-arm -icount shift=auto,align=on -M netduino2 -nographic -monitor null -serial stdio -s -S -kernel $(<) -d int < <(while read -r line; do word=($$line); sleep $${word[0]}; echo $${word[1]}; done < arm.input)
download: $(PROJECT_NAME).bin
	st-flash write $(PROJECT_NAME).bin 0x08000000
run: $(PROJECT_NAME).bin
	timeout --preserve-status 60s qemu-system-arm -icount shift=auto,align=on -M netduino2 -nographic -monitor null -serial stdio -kernel $(<) -d int < <(while read -r line; do word=($$line); sleep $${word[0]}; echo $${word[1]}; done < arm.input)
%.o: %.s
	$(ARM_AS) $(ARM_AS_OPTIONS) $(<) -o $(@)
%.o: %.c
	$(ARM_CC) $(ARM_CC_OPTIONS) -c $(<) -o $(@)
$(PROJECT_NAME).elf: stm32f205.ld $(S_SOURCES:.s=.o) $(C_SOURCES:.c=.o)
	$(ARM_CC) $(ARM_CC_OPTIONS) -T $(^) -o $(@)
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(ARM_OC) -O binary $(<) $(@)
