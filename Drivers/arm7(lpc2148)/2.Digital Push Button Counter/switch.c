/*#include <LPC214x.h>

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
int main(void)
{
		int flag=0;
    PLL_Init();
    IO0DIR = 0x0000FFFF;        // Configure Port0 as output
	  
    while(1)
    {
        if(IO0PIN&(1<<16))
				{
					while(IO0PIN&(1<<16));
					flag=!flag;
					
				}
				if(flag==1)
					IO0SET=0xFFFFFFFF;
				else
					IO0CLR=0xFFFFFFFF;
    }
}
*/
#include <LPC214x.h>

unsigned char seg_code[10] =
{
    0x3F,   //0
    0x06,   //1
    0x5B,   //2
    0x4F,   //3
    0x66,   //4
    0x6D,   //5
    0x7D,   //6
    0x07,   //7
    0x7F,   //8
    0x6F    //9
};

void PLL_Init(void)
{
    PLL0CON = 0x01;
    PLL0CFG = 0x24;

    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;

    while(!(PLL0STAT & (1<<10)));

    PLL0CON = 0x03;

    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;

    VPBDIV = 0x01;
}

void timer0_delay_ms(unsigned int ms)
{
    T0TCR = 0x02;
    T0PR = 59999;
    T0TC = 0;

    T0TCR = 0x01;

    while(T0TC < ms);

    T0TCR = 0x00;
}

int main()
{
    unsigned int count = 0;

    PLL_Init();

    /* P0.16-P0.23 -> Output */
    IO0DIR |= 0x00FF0000;

    /* P0.11 -> Input */
    IO0DIR &= ~(1<<11);

    /* Display 0 initially */
    IO0CLR = 0x00FF0000;
    IO0SET = ((unsigned int)seg_code[count] << 16);

    while(1)
    {
        if(IO0PIN & (1<<11))
        {
            timer0_delay_ms(20);

            if(IO0PIN & (1<<11))
            {
                while(IO0PIN & (1<<11));

                count++;

                if(count > 9)
                    count = 0;

                IO0CLR = 0x00FF0000;
                IO0SET = ((unsigned int)seg_code[count] << 16);
            }
        }
    }
}