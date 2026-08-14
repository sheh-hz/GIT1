#include <LPC214x.h>
#include <string.h>

void delay_ms(unsigned int ms)
{
    unsigned int i,j;
    for(i=0;i<ms;i++)
        for(j=0;j<6000;j++);
}

char password[] = "1234";
char entered[5];

char keypad[4][4]=
{
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'C','0','=','+'}
};

/**************** LCD FUNCTIONS ****************/

void lcd_command(unsigned char cmd)
{
    IO0CLR = 0xF7;

    IO0CLR = (1<<0);
    IO0CLR = (1<<1);

    IO0SET = cmd & 0xF0;

    IO0SET = (1<<2);
    delay_ms(2);
    IO0CLR = (1<<2);

    IO0CLR = 0xF0;
    IO0SET = (cmd<<4)&0xF0;

    IO0SET = (1<<2);
    delay_ms(2);
    IO0CLR = (1<<2);
}

void lcd_data(unsigned char ch)
{
    IO0CLR = 0xF7;

    IO0SET = (1<<0);
    IO0CLR = (1<<1);

    IO0SET = ch & 0xF0;

    IO0SET = (1<<2);
    delay_ms(2);
    IO0CLR = (1<<2);

    IO0CLR = 0xF0;
    IO0SET = (ch<<4)&0xF0;

    IO0SET = (1<<2);
    delay_ms(2);
    IO0CLR = (1<<2);
}

void lcd_string(char *str)
{
    while(*str)
        lcd_data(*str++);
}

void lcd_init(void)
{
    delay_ms(20);

    lcd_command(0x02);
    lcd_command(0x28);
    lcd_command(0x0C);
    lcd_command(0x06);
    lcd_command(0x01);

    delay_ms(5);
}

/**************** KEYPAD ****************/

char keypad_scan(void)
{
    int row,col;

    while(1)
    {
        IO0SET = 0x000F0000;      // Rows HIGH

        for(row=0; row<4; row++)
        {
            IO0SET = 0x000F0000;
            IO0CLR = (1<<(16+row));      // Current row LOW

            delay_ms(1);

            for(col=0; col<4; col++)
            {
                if(!(IO0PIN & (1<<(20+col))))
                {
                    

                    while(!(IO0PIN & (1<<(20+col))));

                    

                    return keypad[row][col];
                }
            }
        }
    }
}

/**************** MAIN ****************/

int main(void)
{
    int i;

    PINSEL0 = 0;
    PINSEL1 = 0;

    /* LCD */
    IO0DIR |= 0x000000F7;

    /* Keypad Rows Output */
    IO0DIR |= 0x000F0000;

    /* Keypad Columns Input */
    IO0DIR &= ~0x00F00000;

    /* LED Output */
    IO0DIR |= (1<<24);

    IO0SET = 0x000F0000;
    IO0CLR = (1<<24);

    lcd_init();

    while(1)
    {
        lcd_command(0x01);
        lcd_command(0x80);
        lcd_string("Enter Password");

        lcd_command(0xC0);

        for(i=0;i<4;i++)
        {
            entered[i]=keypad_scan();

            lcd_data('*');
        }

        entered[4]='\0';

        delay_ms(300);

        lcd_command(0x01);

        if(strcmp(entered,password)==0)
        {
            lcd_string("Access Granted");

            IO0SET = (1<<24);
        }
        else
        {
            lcd_string("Wrong Password");

            IO0CLR = (1<<24);
        }

        delay_ms(2000);

        IO0CLR = (1<<24);
    }
}