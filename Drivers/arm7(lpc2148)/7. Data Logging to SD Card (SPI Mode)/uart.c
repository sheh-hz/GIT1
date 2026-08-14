#include <LPC214x.h>

void UART0_Init(void)
{
    PINSEL0 |= 0x05;

    U0LCR=0x83;
    U0DLL=97;
    U0DLM=0;
    U0LCR=0x03;

    U0FCR=0x07;
}

void UART0_TxChar(char ch)
{
    while(!(U0LSR&(1<<5)));
    U0THR=ch;
}

void UART0_TxString(char *s)
{
    while(*s)
        UART0_TxChar(*s++);
}