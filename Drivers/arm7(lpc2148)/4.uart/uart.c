#include <LPC214x.h>

void PLL_Init(void)
{
    PLL0CON = 0x01;             // Enable PLL
    PLL0CFG = 0x24;             // M = 5, P = 2

    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;

    while(!(PLL0STAT & (1 << 10)));   // Wait for PLL Lock

    PLL0CON = 0x03;             // Connect PLL

    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;

    VPBDIV = 0x01;              // PCLK = CCLK = 60 MHz
}

void delay(unsigned int delay)
{
    T0TCR = 0x02;               // Reset Timer
    T0PR  = 59999;              // 1 ms tick (PCLK = 60 MHz)
    T0TC  = 0;                  // Clear Timer Counter

    T0TCR = 0x01;               // Start Timer

    while(T0TC < delay);        // Wait

    T0TCR = 0x00;               // Stop Timer
}
void UART0_Init(void)
{
    PINSEL0 |= 0x05;

    U0LCR = 0x83;

    U0DLL = 134;
    U0DLM = 1;

    U0LCR = 0x03;
}

void UART0_TxChar(char ch)
{
    while(!(U0LSR & (1<<5)));

    U0THR = ch;
}

void UART0_String(char *str)
{
    while(*str)
    {
        UART0_TxChar(*str++);
    }
}
char UART0_RxChar(void)
{
    while(!(U0LSR & (1<<0)));   // Wait until data received

    return U0RBR;               // Read received character
}
int main()
{
		int i;
	char a[6];
		PLL_Init();
    UART0_Init();

    while(1)
    {
			for(i=0;i<5;i++)
			{
				a[i]=UART0_RxChar();
			}
			a[i]='\0';
        UART0_String(a);

        
    }
}