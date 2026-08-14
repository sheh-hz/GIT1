#include <LPC214x.h>
#include <stdio.h>

#define DS1307_W 0xD0
#define DS1307_R 0xD1

void delay_ms(unsigned int ms)
{
    unsigned int i,j;
    for(i=0;i<ms;i++)
        for(j=0;j<6000;j++);
}

/*************** UART ****************/

void UART0_Init(void)
{
    PINSEL0 |= 0x00000005;   // P0.0 TXD0, P0.1 RXD0

    U0LCR = 0x83;            // 8-bit, 1 stop, DLAB=1
    U0DLL = 97;              // 9600 baud @15MHz
    U0DLM = 0;
    U0LCR = 0x03;            // DLAB=0
}

void UART0_TxChar(char ch)
{
    while(!(U0LSR & 0x20));
    U0THR = ch;
}

void UART0_TxString(char *str)
{
    while(*str)
        UART0_TxChar(*str++);
}

/*************** I2C ****************/

void I2C_Init(void)
{
    PINSEL0 &= ~(0xF<<4);
    PINSEL0 |=  (0x5<<4);   // P0.2=SCL0, P0.3=SDA0

    I2C0SCLH = 300;          // ~100kHz
    I2C0SCLL = 300;

    I2C0CONSET = 0x40;       // Enable I2C
}

void I2C_Start(void)
{
    I2C0CONSET = 0x20;       // STA
    while(!(I2C0CONSET & 0x08)); // Wait for SI
}

void I2C_Stop(void)
{
    I2C0CONSET = 0x10;       // STOP
    I2C0CONCLR = 0x08;       // Clear SI
    delay_ms(1);
}

void I2C_Write(unsigned char data)
{
    I2C0DAT = data;
    I2C0CONCLR = 0x28;       // Clear SI and STA
    while(!(I2C0CONSET & 0x08));
}

unsigned char I2C_Read_ACK(void)
{
    I2C0CONSET = 0x04;       // Send ACK
    I2C0CONCLR = 0x08;       // Clear SI
    while(!(I2C0CONSET & 0x08));
    return I2C0DAT;
}

unsigned char I2C_Read_NACK(void)
{
    I2C0CONCLR = 0x0C;       // Clear AA and SI (NACK)
    while(!(I2C0CONSET & 0x08));
    return I2C0DAT;
}

/*************** RTC ****************/

unsigned char BCDtoDEC(unsigned char bcd)
{
    return ((bcd>>4)*10)+(bcd&0x0F);
}

void RTC_SetTime(void)
{
    I2C_Start();

    I2C_Write(DS1307_W);   // Address + Write
    I2C_Write(0x00);       // Seconds register

    I2C_Write(0x00);       // Seconds
    I2C_Write(0x30);       // Minutes
    I2C_Write(0x12);       // Hours

    I2C_Stop();
}

void RTC_ReadTime(unsigned char *hh,unsigned char *mm,unsigned char *ss)
{
    I2C_Start();

    I2C_Write(DS1307_W);   // Write mode
    I2C_Write(0x00);       // Start from seconds register

    I2C_Start();           // Repeated START

    I2C_Write(DS1307_R);   // Read mode

    *ss = I2C_Read_ACK();   // Read seconds + ACK
    *mm = I2C_Read_ACK();   // Read minutes + ACK
    *hh = I2C_Read_NACK();  // Read hours + NACK

    I2C_Stop();
}

/*************** MAIN ****************/

int main(void)
{
    unsigned char hr,min,sec;
    char str[30];

    UART0_Init();
    I2C_Init();

    RTC_SetTime();    // Set once

    while(1)
    {
        RTC_ReadTime(&hr,&min,&sec);

        sprintf(str,"Time %02d:%02d:%02d\r\n",
                BCDtoDEC(hr),
                BCDtoDEC(min),
                BCDtoDEC(sec));

        UART0_TxString(str);

        delay_ms(1000);
    }
}