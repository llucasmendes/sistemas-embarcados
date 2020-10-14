// Definicoes de E/S
#include <avr/io.h>
// Atraso de tempo
#include <util/delay.h>
// Funcao principal
int main() {
	// Ajustando pino como saida
	DDRB = DDRB | (1 << DDB5);
	// Laco infinito
	while(1) {
		// Ligando o LED
		PORTB = PORTB | (1 << PORTB5);
		// Atraso de 1 segundo
		_delay_ms(1000);
		// Ligando o LED
		PORTB = PORTB & ~(1 << PORTB5);
		// Atraso de 1 segundo
		_delay_ms(1000);
	}
}
