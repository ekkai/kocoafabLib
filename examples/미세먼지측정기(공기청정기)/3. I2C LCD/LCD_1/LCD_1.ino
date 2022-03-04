// 미세먼지측정기(공기청정기) 키트 - LCD_1.ino
// I2C LCD 기본 출력 예제

// lcd.init() : I2C LCD 초기화
// lcd.backlight() : I2C LCD의 백라이트 설정
// lcd.print("문장" or 변수) : I2C LCD의 화면에 해당 "문장" 또는 변수 내용 출력


// I2C 통신,LCD 라이브러리 추가
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C LCD 객체 생성 (0x27 또는 0x3F의 주소값 사용)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init(); 
  lcd.backlight();
  lcd.print("Hello, world!");
}

void loop()
{
}
