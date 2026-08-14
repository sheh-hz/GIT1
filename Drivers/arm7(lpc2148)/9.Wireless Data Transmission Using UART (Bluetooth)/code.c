#include <LPC214x.h>

void UART0_Init(void);
void UART0_TxChar(char ch);
void UART0_TxString(char *str);
char UART0_RxChar(void);

void UART0_Init(void)
{
    // P0.0 = TXD0
    // P0.1 = RXD0

    PINSEL0 &= ~0x0000000F;
    PINSEL0 |=  0x00000005;

    // 8-bit, 1 stop, no parity, DLAB = 1
    U0LCR = 0x83;

    // For PCLK = 15 MHz, approximately 9600 baud
    U0DLL = 97;
    U0DLM = 0;

    // DLAB = 0
    U0LCR = 0x03;
}

void UART0_TxChar(char ch)
{
    while (!(U0LSR & 0x20));

    U0THR = ch;
}

void UART0_TxString(char *str)
{
    while (*str)
    {
        UART0_TxChar(*str);
        str++;
    }
}

char UART0_RxChar(void)
{
    while (!(U0LSR & 0x01));

    return U0RBR;
}

int main(void)
{
    char command;

    UART0_Init();

    UART0_TxString("LPC2148 Bluetooth Started\r\n");

    while (1)
    {
        UART0_TxString("Sensor Value: 100\r\n");

        // Wait for command from Bluetooth
        command = UART0_RxChar();

        if (command == '1')
        {
            UART0_TxString("LED ON\r\n");

            IO0SET = (1 << 10);
        }

        else if (command == '0')
        {
            UART0_TxString("LED OFF\r\n");

            IO0CLR = (1 << 10);
        }
    }
}