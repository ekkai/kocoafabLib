// 미세먼지측정기(공기청정기) 키트 - DHT11_2.ino
// 온습도센서 값을 I2C LCD에 출력

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 6    
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  lcd.init();
  lcd.backlight();
  dht.begin();
}
void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print(t); lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print(h); lcd.print("%");

  delay(1500);
}
