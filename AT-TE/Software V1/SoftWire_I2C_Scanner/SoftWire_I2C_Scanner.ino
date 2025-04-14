// Forum: https://forum.arduino.cc/t/i2c-communication-with-softwire-library/1237721
// This Wokwi project: https://wokwi.com/projects/392870739462268929
// 
// Question: Does the SoftWire library work on a Arduino Mega ?
// Answer: Yes, I think it does.


#include <SoftWire.h>

// PINS for Custom SDA ans SCL
#define SDA_PIN 3   
#define SCL_PIN 2

// Instantiate SoftWire with custom pins
SoftWire mywire = SoftWire(SDA_PIN, SCL_PIN); 

void setup() 
{
  Serial.begin(9600);
  mywire.begin();

  Serial.print("Scan: ");
  for(int address=1; address<=127; address++)
  {
    mywire.beginTransmission(address);
    int error = mywire.endTransmission();
    if(error==0)
    {
      Serial.print("0x");
      Serial.print(address,HEX);
      Serial.print(" ");
    }
  }
  Serial.println("  --> Finished");
}

void loop() 
{
  delay(10);
}