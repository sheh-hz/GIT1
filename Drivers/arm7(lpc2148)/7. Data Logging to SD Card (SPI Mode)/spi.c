#include <LPC214x.h>

#define CS_LOW()  IO0CLR=(1<<7)
#define CS_HIGH() IO0SET=(1<<7)

void SPI_Init(void)
{
    PINSEL0 |= (1<<8);
    PINSEL0 |= (1<<10);
    PINSEL0 |= (1<<12);

    IO0DIR |= (1<<7);

    CS_HIGH();

    S0SPCCR=8;

    S0SPCR=0x20;
}

unsigned char SPI_TxRx(unsigned char data)
{
    S0SPDR=data;

    while(!(S0SPSR&(1<<7)));

    return S0SPDR;
}