ARM_PREFIX      := arm-none-eabi
ARM_AS          := $(ARM_PREFIX)-as
ARM_CC          := $(ARM_PREFIX)-gcc
ARM_LD          := $(ARM_PREFIX)-ld
ARM_OC          := $(ARM_PREFIX)-objcopy
ARM_AS_OPTIONS	:= -mcpu=cortex-m3 -mthumb -g
ARM_CC_OPTIONS	:= -Wall -Os -mcpu=cortex-m3 -mthumb -g -nostdlib -nostartfiles
C_SOURCES       := blink_arm.c
S_SOURCES       := start.s
PROJECT_NAME    := blink

all: $(PROJECT_NAME).bin
run: blink.bin
	qemu-system-arm -M netduino2 -nographic -monitor null -serial null -semihosting -kernel $(<)
debug: blink.bin
	qemu-system-arm -M netduino2 -nographic -monitor null -serial null -semihosting -s -S -kernel $(<)
clean:
	@rm -rf *.o *.elf *.bin
%.o: %.s
	$(ARM_AS) $(ARM_AS_OPTIONS) $(<) -o $(@)
%.o: %.c
	$(ARM_CC) $(ARM_CC_OPTIONS) -c $(<) -o $(@)
$(PROJECT_NAME).elf: stm32f103c8.ld $(S_SOURCES:.s=.o) $(C_SOURCES:.c=.o)
	$(ARM_CC) $(ARM_CC_OPTIONS) -T $(^) -o $(@)
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(ARM_OC) -O binary $(<) $(@)
