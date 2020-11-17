// Tipos inteiros de tamanho fixo
#include <stdint.h>
// Definição do registrador de RCC
#define	RCC_APB2ENR			(0x40023844)
#define	RCC_USART1_EN  		(4)
// Definição de registradores de USART1
#define	USART1_SR			(0x40011000)
#define	USART1_DR			(0x40011004)
#define	USART1_BRR			(0x40011008)
#define	USART1_CR1			(0x4001100C)
#define	USART1_CR2			(0x40011010)
#define	USART1_RXNE			(5)
#define	USART1_TXE			(7)
#define	USART1_UE			(13)
#define	USART1_TE			(3)
#define	USART1_RE			(2)
// Declaração de topo da pilha e de funções
extern char _estack;
int main();
// Tabela de vetor de interrupção
uint32_t (* const vector_table[]) __attribute__ ((section(".text.vector_table"))) = {
	(uint32_t*)(&_estack),	// Topo da pilha
	(uint32_t*)(main),		// Reset
	0,						// NMI
	0,						// Hard fault
	0,						// Memory management fault
	0,						// Bus fault
	0,						// Usage fault
	0, 0, 0, 0,				// Reservado
	0,						// SVCall
	0,						// Debug monitor
	0,						// Reservado
	0,						// PendSV
	0,						// SysTick
	0,						// Window Watchdog interrupt
	0,						// PVD through EXTI Line detection interrupt
	0,						// Tamper interrupt
	0,						// RTC global interrupt
	0,						// Flash global interrupt
	0,						// RCC global interrupt
	0,						// EXTI Line0 interrupt
	0,						// EXTI Line1 interrupt
	0,						// EXTI Line2 interrupt
	0,						// EXTI Line3 interrupt
	0,						// EXTI Line4 interrupt
	0,						// EXTI Line4 interrupt
	0,						// DMA1 Stream0 global interrupt
	0,						// DMA1 Stream1 global interrupt
	0,						// DMA1 Stream2 global interrupt
	0,						// DMA1 Stream3 global interrupt
	0,						// DMA1 Stream4 global interrupt
	0,						// DMA1 Stream5 global interrupt
	0,						// DMA1 Stream6 global interrupt
	0,						// ADC1, ADC2 and ADC3 global interrupts
	0,						// CAN1 TX interrupts
	0,						// CAN1 RX0 interrupts
	0,						// CAN1 RX1 interrupt
	0,						// CAN1 SCE interrupt
	0,						// EXTI Line[9:5] interrupts
	0,						// TIM1 Break interrupt and TIM9 global interrupt
	0,						// TIM1 Update interrupt and TIM10 global interrupt
	0,						// TIM1 Trigger and Commutation interrupts and TIM11 global interrupt
	0,						// TIM1 Capture Compare interrupt
	0,						// TIM2 global interrupt
	0,						// TIM3 global interrupt
	0,						// TIM4 global interrupt
	0,						// I2C1 event interrupt
	0,						// I2C1 error interrupt
	0,						// I2C2 event interrupt
	0,						// I2C2 error interrupt
	0,						// SPI1 global interrupt
	0,						// SPI2 global interrupt
	0						// USART1 global interrupt
};
// Reset and Clock Control (RCC)
volatile uint32_t* const APB2ENR = (volatile uint32_t*)(RCC_APB2ENR);
// USART1
volatile uint32_t* const U1SR = (volatile uint32_t*)(USART1_SR);
volatile uint32_t* const U1DR = (volatile uint32_t*)(USART1_DR);
volatile uint32_t* const U1BRR = (volatile uint32_t*)(USART1_BRR);
volatile uint32_t* const U1CR1 = (volatile uint32_t*)(USART1_CR1);
volatile uint32_t* const U1CR2 = (volatile uint32_t*)(USART1_CR2);
// Configurar USART1
void configurar_usart1() {
	// Habilitando clock do USART1
	(*APB2ENR) |= (1 << RCC_USART1_EN);
	// Habilitando USART (1 start bit + 8 bits de dados + 1 stop bit)
	(*U1CR1) |= (1 << USART1_UE);
	// Ajustando baud rate para 9600 bps (52,083 @ 8 MHz)
	(*U1BRR) = 0x341;
	// Habilitando recepção e transmissão
	(*U1CR1) |= (1 << USART1_RE) | (1 << USART1_TE);
}
// Enviar dado pela USART1
void enviar_usart1(uint8_t dado) {
	// Escrevendo dado
	(*U1DR) = dado;
	// Esperando envio do dado
	while(!((*U1SR) & (1 << USART1_TXE)));
}
// Receber dado pela USART1
uint8_t receber_usart1() {
	// Aguardando recebimento do dado
	while(!((*U1SR) & (1 << USART1_RXNE)));
	// Retornando dado
	return (*U1DR);
}
// Versão simplificada do printf
void print_serial(char* string) {
	// Índice da string
	uint32_t i = 0;
	// Repete até encontrar caractere nulo
	while(string[i]) {
		// Enviando caractere via USART1
		enviar_usart1(string[i++]);
	}
}
// Versão simplificada do scanf
void scan_serial(char* string) {
	// Índice da string
	uint32_t i = 0;
	// Recebendo dado da USART1
	do string[i] = receber_usart1();
	// Repete até receber quebra de linha
	while(string[i++] != '\n');
	// Inserindo caractere nulo
	string[i] = 0;
}
// Função principal
int main() {
	// Caracteres de texto
	char texto[100];
	// Configuração da USART1
	configurar_usart1();
	// Mensagem de inicialização
	print_serial("RX2TX4EVER\n");
	// Laço infinito
	while(1) {
		// Recebendo e enviando dados
		scan_serial(texto);
		print_serial(texto);
	}
}