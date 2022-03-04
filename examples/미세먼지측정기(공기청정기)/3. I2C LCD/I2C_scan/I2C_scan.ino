// 미세먼지측정기(공기청정기) 키트 - I2C_scan.ino
// I2C LCD 모듈 고유 주소값 확인용 예제

#include <Wire.h>

void setup()
{
  // I2C 통신 초기화
  Wire.begin();

  Serial.begin(9600);
  while (!Serial);           
  Serial.println("\nI2C Scanner");
}

void loop()
{
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
        Serial.print(address,HEX);
        Serial.println("  !");

      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknow error at address 0x");
      if (address<16) 
        Serial.print("0");
        Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(5000);
}
 
