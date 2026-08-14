#include <LPC214x.h>

void delay_ms(unsigned int ms)
{
    unsigned int i,j;
    for(i=0;i<ms;i++)
        for(j=0;j<6000;j++);
}

void lcd_command(unsigned char cmd)
{
    IO0CLR = 0x000000F7;

    IO0CLR = (1<<0);          // RS = 0
    IO0CLR = (1<<1);          // RW = 0

    IO0SET = cmd & 0xF0;

    IO0SET = (1<<2);          // EN = 1
    delay_ms(2);
    IO0CLR = (1<<2);          // EN = 0

    IO0CLR = 0x000000F0;
    IO0SET = (cmd<<4) & 0xF0;

    IO0SET = (1<<2);
    delay_ms(2);
    IO0CLR = (1<<2);
}

void lcd_data(unsigned char ch)
{
    IO0CLR = 0x000000F7;

    IO0SET = (1<<0);          // RS = 1
    IO0CLR = (1<<1);          // RW = 0

    IO0SET = ch & 0xF0;

    IO0SET = (1<<2);
    delay_ms(2);
    IO0CLR = (1<<2);

    IO0CLR = 0x000000F0;
    IO0SET = (ch<<4) & 0xF0;

    IO0SET = (1<<2);
    delay_ms(2);
    IO0CLR = (1<<2);
}

void lcd_string(char *str)
{
    while(*str)
    {
        lcd_data(*str++);
    }
}

void lcd_init(void)
{
    delay_ms(20);

    lcd_command(0x02);
    lcd_command(0x28);
    lcd_command(0x0C);
    lcd_command(0x06);
    lcd_command(0x01);

    delay_ms(2);
}

int main()
{
    IO0DIR = 0x000000F7;      // P0.0,P0.1,P0.2,P0.4-P0.7 Output

    lcd_init();

    lcd_command(0x80);        // First line
    lcd_string("HELLO");

    while(1);
}