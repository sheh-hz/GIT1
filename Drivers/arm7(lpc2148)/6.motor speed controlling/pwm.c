#include <LPC214x.h>
#include<stdio.h>
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

void PWM_Init(void)
{
    PINSEL1 &= ~(3<<10);
    PINSEL1 |=  (1<<10);      // P0.21 = PWM5

    PWMTCR = 0x02;            // Reset PWM Counter

    PWMPR  = 59;              // 1 MHz PWM clock (PCLK = 60 MHz)

    PWMMR0 = 1000;            // PWM Period = 1 ms

    PWMMR5 = 500;             // 50% Duty Cycle

    PWMMCR = (1<<1);          // Reset on MR0

    PWMLER = (1<<0) | (1<<5); // Load MR0 and MR5

    PWMPCR = (1<<13);         // Enable PWM5 output

    PWMTCR = 0x09;            // Enable Counter and PWM
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

void send(char ch)
{
    while(!(U0LSR & (1<<5)));

    U0THR = ch;
}

void strsend(char *str)
{
    while(*str)
    {
        send(*str++);
    }
}
char uartrec(void)
{
    while(!(U0LSR & (1<<0)));   // Wait until data received

    return U0RBR;               // Read received character
}
void ADC_Init(void)
{
    // Configure P0.28 as AD0.1
    PINSEL1 &= ~(3 << 24);
    PINSEL1 |=  (1 << 24);

    AD0CR = 0;
    AD0CR |= (1 << 1);      // Select Channel AD0.1
    AD0CR |= (15 << 8);     // ADC Clock Divider
    AD0CR |= (1 << 21);     // Power ON ADC
}
int main()
{
		int adc_value,duty ;
		char a[20];
		PLL_Init();
    UART0_Init();
		ADC_Init();
		PWM_Init();
    while(1)
    {
			AD0CR &= ~(7<<24);      // Clear START bits
			AD0CR |=  (1<<24);      // Start conversion
			while(!(AD0DR1 & (1 << 31)));   // Wait until DONE bit is set
			adc_value = ((AD0DR1 >> 6) & 0x03FF);  // Return 10-bit ADC value
			sprintf(a,"%d\r\n",adc_value);
			strsend(a);
			duty = (adc_value * 1000) / 1023;
      PWMMR1 = duty;
      PWMLER = (1<<5);
			

        
    }
}