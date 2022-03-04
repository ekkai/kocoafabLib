// 미세먼지측정기(공기청정기) 키트 - LCD_2.ino
// I2C LCD의 원하는 줄, 칸에 내용 출력

// lcd.setCursor(칸, 줄) : LCD의 원하는 위치(0~15 칸, 0~1 줄)에 내용 출력

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0); 
  lcd.print("Your Name");
  lcd.setCursor(0, 1);
  lcd.print("Phone Number");
}
