PROJECT := uart

all: $(PROJECT).elf $(PROJECT).hex

%.elf: %.c
	avr-gcc -Wall -Os -DF_CPU=16000000UL -mmcu=atmega328p $(<) -o $(@)

%.hex: %.elf
	avr-objcopy -O ihex -R .eeprom $(<) $(@)

clean:
	@rm -rf *.elf *.hex

download: $(PROJECT).hex
	avrdude -b 57600 -c arduino -D -p atmega328p -P /dev/ttyUSB0 -U flash:w:$(<)

terminal:
	miniterm.py
