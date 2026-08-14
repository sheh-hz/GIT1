#include <LPC214x.h>

void ADC_Init(void)
{
    PINSEL1 &= ~(3<<24);
    PINSEL1 |= (1<<24);

    AD0CR=(1<<1)|(15<<8)|(1<<21);
}

unsigned int ADC_Read(void)
{
    AD0CR &= ~(7<<24);
    AD0CR |= (1<<24);

    while(!(AD0GDR&(1<<31)));

    return (AD0GDR>>6)&0x3FF;
}