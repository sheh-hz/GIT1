#include <Wire.h>

#define SLAVE_ADDRESS 0x08

char rxData[32];
volatile bool dataReceived = false;

void receiveEvent(int numBytes)
{
  int i = 0;

  while (Wire.available() && i < sizeof(rxData) - 1)
  {
    rxData[i++] = Wire.read();
  }

  rxData[i] = '\0';      // Null-terminate the received string
  dataReceived = true;
}

void setup()
{
  Serial.begin(115200);

  Wire.begin(SLAVE_ADDRESS);   // ESP32 as I2C Slave

  Wire.onReceive(receiveEvent);

  Serial.println("ESP32 I2C Slave Ready");
}

void loop()
{
  if (dataReceived)
  {
    Serial.print("Received: ");
    Serial.println(rxData);

    dataReceived = false;
  }
}