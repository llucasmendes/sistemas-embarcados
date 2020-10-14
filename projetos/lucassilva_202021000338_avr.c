
// lucassilva_202021000338_avr
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

// #define F_CPU 16000000UL
#define BAUD 9600

#include <util/setbaud.h>

void inicializar_uart0()
{
	// Configurando taxa de transmissao
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	// Habilitando recepcao e transmissao
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	// Modo assincrono e sem paridade
	// Quadro com 8 bits com 1 bit de parada
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}
// Funcao para envio de dado pela UART 0
int enviar_dado_uart0(char dado, FILE *fluxo)
{
	// Checando por quebra de linha
	if (dado == '\n')
	{
		enviar_dado_uart0('\r', fluxo);
	}
	// Esperando por envio pendente
	while (!(UCSR0A & (1 << UDRE0)))
		;
	// Enviando dado
	UDR0 = dado;
	// Retornando sem erro
	return 0;
}
// Funcao para recebimento de dado pela UART 0
int receber_dado_uart0(FILE *fluxo)
{
	// Esperando por recebimento
	while (!(UCSR0A & (1 << RXC0)))
		;
	// Retornando registrador de dado
	return UDR0;
}

// Criando fluxos de E/S para serial
FILE stdin_uart0 = FDEV_SETUP_STREAM(NULL, receber_dado_uart0, _FDEV_SETUP_READ);
FILE stdout_uart0 = FDEV_SETUP_STREAM(enviar_dado_uart0, NULL, _FDEV_SETUP_WRITE);
// Caracteres de texto
char texto[100] = {0};

void ponto()
{

	PORTB = PORTB | (1 << PORTB5);
	_delay_ms(250);
	PORTB = PORTB & ~(1 << PORTB5);
	_delay_ms(250);
}

void traco()
{

	PORTB = PORTB | (1 << PORTB5);
	_delay_ms(250 * 3);
	PORTB = PORTB & ~(1 << PORTB5);
	_delay_ms(250);
}

void A()
{

	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}

void B()
{

	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}

void C()
{

	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void D()
{
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void E()
{
	ponto();
	_delay_ms(250);
}
void f()
{
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void G()
{
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void H()
{
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void I()
{
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void J()
{
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void K()
{
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void L()
{
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void M()
{
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void N()
{
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void O()
{
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void P()
{
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	ponto();
}
void Q()
{
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void R()
{
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void S()
{
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void T()
{
	traco();
	_delay_ms(250);
}
void U()
{
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void V()
{
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void W()
{
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void X()
{
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void Y()
{
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void Z()
{
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void um()
{
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void dois()
{
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void tres()
{
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void quatro()
{
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void cinco()
{
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void seis()
{
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void sete()
{
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void oito()
{
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void nove()
{
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	ponto();
	_delay_ms(250);
}
void zero()
{
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
	traco();
	_delay_ms(250);
}
void morse(char *ch)
{
	for (int i = 0; i <= sizeof(ch); i++)
	{
		if (ch[i] == 'A' || ch[i] == 'a')
		{
			A();
		}
		else if (ch[i] == 'B' || ch[i] == 'b')
		{
			B();
		}
		else if (ch[i] == 'C' || ch[i] == 'c')
		{
			C();
		}
		else if (ch[i] == 'D' || ch[i] == 'd')
		{
			D();
		}
		else if (ch[i] == 'E' || ch[i] == 'e')
		{
			E();
		}
		else if (ch[i] == 'f' || ch[i] == 'f')
		{
			f();
		}
		else if (ch[i] == 'G' || ch[i] == 'g')
		{
			G();
		}
		else if (ch[i] == 'H' || ch[i] == 'h')
		{
			H();
		}
		else if (ch[i] == 'I' || ch[i] == 'i')
		{
			I();
		}
		else if (ch[i] == 'J' || ch[i] == 'j')
		{
			J();
		}
		else if (ch[i] == 'K' || ch[i] == 'k')
		{
			K();
		}
		else if (ch[i] == 'L' || ch[i] == 'l')
		{
			L();
		}
		else if (ch[i] == 'M' || ch[i] == 'm')
		{
			M();
		}
		else if (ch[i] == 'N' || ch[i] == 'n')
		{
			N();
		}
		else if (ch[i] == 'O' || ch[i] == 'o')
		{
			O();
		}
		else if (ch[i] == 'P' || ch[i] == 'p')
		{
			P();
		}
		else if (ch[i] == 'Q' || ch[i] == 'q')
		{
			Q();
		}
		else if (ch[i] == 'R' || ch[i] == 'r')
		{
			R();
		}
		else if (ch[i] == 'S' || ch[i] == 's')
		{
			S();
		}
		else if (ch[i] == 'T' || ch[i] == 't')
		{
			T();
		}
		else if (ch[i] == 'U' || ch[i] == 'u')
		{
			U();
		}
		else if (ch[i] == 'V' || ch[i] == 'v')
		{
			V();
		}
		else if (ch[i] == 'W' || ch[i] == 'w')
		{
			W();
		}
		else if (ch[i] == 'X' || ch[i] == 'x')
		{
			X();
		}
		else if (ch[i] == 'Y' || ch[i] == 'y')
		{
			Y();
		}
		else if (ch[i] == 'Z' || ch[i] == 'z')
		{
			Z();
		}
		else if (ch[i] == '0')
		{
			zero();
		}
		else if (ch[i] == '1')
		{
			um();
		}
		else if (ch[i] == '2')
		{
			dois();
		}
		else if (ch[i] == '3')
		{
			tres();
		}
		else if (ch[i] == '4')
		{
			quatro();
		}
		else if (ch[i] == '5')
		{
			cinco();
		}
		else if (ch[i] == '6')
		{
			seis();
		}
		else if (ch[i] == '7')
		{
			sete();
		}
		else if (ch[i] == '8')
		{
			oito();
		}
		else if (ch[i] == '9')
		{
			nove();
		}
		else if (ch[i] == ' ')
		{
			_delay_ms(250 * 7);
		}
	}
}

int main()
{
	// Inicializando UART 0
	inicializar_uart0();
	// Reconfigurando E/S padrao
	stdin = &stdin_uart0;
	stdout = &stdout_uart0;
	// Mensagem de inicializacao
	// Ajustando pino como saida
	DDRB = DDRB | (1 << DDB5);

	printf("*** MORSE TERMINAL ***\n");
	// Laco infinito
	while (1)
	{
		printf("-> ");
		gets(texto);
		printf("%s\n", texto);
		morse(texto);
		
	}
}