// 미세먼지측정기(공기청정기) 키트 - dust_2.ino
// 미세먼지측정 센서 기초 활용

// dust.begin(핀번호1, 핀번호2) : 센서의 다섯번째 핀은 핀번호1에 네번째 핀은 핀번호2에 연결하여 센서 초기화
// dust.pm10Value() : 센서로부터 측정된 pm10 단위의 미세먼지 수치 출력
// dust.pm25Value() : 센서로부터 측정된 pm2.5 단위의 초미세먼지 수치 출력 
// dust.pm1Value() : 센서로부터 측정된 pm1 단위의 초미세먼지 수치 출력 
// lcd.clear() : 현재 LCD 화면을 모두 초기화

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dustSensor_kocoa.h>

dustSensor_kocoa dust;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  dust.begin(2, 3);
}

void loop() {
  int data = dust.pm10Value();
  Serial.println(data);

  lcd.clear();
  lcd.print("Dust : "); 
  lcd.print(data); 
  lcd.print("ug/m3");
  delay(1000);
}
