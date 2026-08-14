#include <stdio.h>

#include "uart.h"
#include "adc.h"
#include "spi.h"
#include "sdcard.h"
#include "delah.h"

int main(void)
{
    unsigned int adc;

    char str[30];

    UART0_Init();

    ADC_Init();

    SPI_Init();

    SD_Init();

    while(1)
    {
        adc=ADC_Read();

        sprintf(str,"ADC=%u\r\n",adc);

        UART0_TxString(str);

        delay_ms(1000);
    }
}