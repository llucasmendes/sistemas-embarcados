# Sistemas Embarcados
Repositório da Disciplina Sistemas embarcados do PROCC programa de Mestrado acadêmico da UFS

qemu-system-avr -version 
qemu-system-avr -machine help 

 avr-gcc -Wall -Os -DF_CPU=16000000UL -mmcu=atmega328p uart.c -o uart.elf
 avr-objcopy -O ihex -R .eeprom uart.elf uart.hex

// qemu-system-avr -machine uno -bios uart.elf -nographic -serial tcp::5678.server.wait

// telnet  localhost 5678 

// qemu-system-avr -machine uno -bios uart.elf -nographic -serial udp::4555@:4556

qemu-system-avr -machine uno -bios uart.elf -nographic -serial tcp::4444,server
telnet  localhost 4444 
