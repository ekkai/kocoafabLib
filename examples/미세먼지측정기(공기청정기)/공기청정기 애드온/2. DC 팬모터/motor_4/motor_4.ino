// 미세먼지측정기(공기청정기) 키트 - motor_4.ino
// 로터리엔코더를 활용한 팬모터 제어 + I2C LCD 출력

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define encoderA 2
#define encoderB 3
LiquidCrystal_I2C lcd(0x27, 16, 2);

int encoderVal = 0;
int prevA = HIGH;
int prevB = HIGH;
int motorEn = 5;
int motorA = 10;
int motorB = 11;

// motorA, motorB 핀 출력모드 설정
// 인터럽트 활성화 setEncoderValue 함수 설정
void setup() {
  pinMode (encoderA, INPUT);
  pinMode (encoderB, INPUT);
  pinMode (motorA, OUTPUT);
  pinMode (motorB, OUTPUT);

  digitalWrite(motorA, HIGH);
  digitalWrite(motorB, LOW);
  analogWrite(motorEn, 0);
  
  Serial.begin(9600);
  attachInterrupt(0, setEncoderValue, CHANGE);

  // I2C LCD 초기화 및 백라이트 설정
  lcd.init();
  lcd.backlight();
}

void loop() {
 analogWrite(motorEn, encoderVal);

 // LCD 화면에 팬 모터 속도 표시
 lcd.setCursor(0, 0);
 lcd.print("speed : ");

 // 값 자릿수에 따른 간격 조절
 if(encoderVal<10)
 lcd.print("  ");
 else if(encoderVal<100)
 lcd.print(" ");

 lcd.print(encoderVal);
 lcd.setCursor(13,0);
 lcd.print("  "); 
}

int getEncoder()
{
  int result = 0;
  int newA = digitalRead(encoderA);
  if (prevA != newA)
  {  
    int newB = digitalRead(encoderB);
    if(newB != newA){
      result = 1;     }
    else{
      result = -1;
  }
}
  prevA = newA;
  return result;
}

// 인터럽트 함수 정의
int setEncoderValue()
{
  int interval = 5;
  encoderVal+= interval * getEncoder();
  encoderVal = constrain(encoderVal, 0, 255);
}
