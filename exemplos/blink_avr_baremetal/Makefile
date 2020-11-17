AVR_PREFIX      := avr
AVR_CC          := $(AVR_PREFIX)-gcc
ARM_OC          := $(AVR_PREFIX)-objcopy
AVR_CC_OPTIONS	:= -Wall -Os -DF_CPU=16000000UL -mmcu=atmega328p
PROJECT_NAME    := blink_avr

all: $(PROJECT_NAME).elf $(PROJECT_NAME).hex

$(PROJECT_NAME).elf: $(PROJECT_NAME).c
	$(AVR_CC) $(AVR_CC_OPTIONS) $(<) -o $(@)

$(PROJECT_NAME).hex: $(PROJECT_NAME).elf
	$(ARM_OC) -O ihex -R .eeprom $(<) $(@)

upload: $(PROJECT_NAME).hex
	 avrdude -b 57600 -c arduino -D -p atmega328p -P /dev/ttyUSB0 -U flash:w:$(<)

clean:
	@rm -rf *.elf *.hex
