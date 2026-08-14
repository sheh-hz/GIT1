#include <LPC214x.h>

void PLL_Init(void);
void timer0_delay_ms(unsigned int delay);

int main(void)
{
    PLL_Init();

    IO0DIR = 0xFFFFFFFF;        // Configure Port0 as output

    while(1)
    {
        IO0SET = 0xFFFFFFFF;    // All Port0 HIGH
        timer0_delay_ms(1000);

        IO0CLR = 0xFFFFFFFF;    // All Port0 LOW
        timer0_delay_ms(1000);
    }
}

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

void timer0_delay_ms(unsigned int delay)
{
    T0TCR = 0x02;               // Reset Timer
    T0PR  = 59999;              // 1 ms tick (PCLK = 60 MHz)
    T0TC  = 0;                  // Clear Timer Counter

    T0TCR = 0x01;               // Start Timer

    while(T0TC < delay);        // Wait

    T0TCR = 0x00;               // Stop Timer
}