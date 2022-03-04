// 미세먼지측정기(공기청정기) 키트 - encoder_2.ino
// 로터리 엔코더 값 I2C LCD에 출력

// attachInterrupt(번호, 인터럽트함수, 인터럽트방식) : 인터럽트 핀을 통해 인터럽트방식에 맞는 신호가 감지되면 인터럽트 함수를 실행

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define encoderA 2
#define encoderB 3
#define encoderSW 7
LiquidCrystal_I2C lcd(0x27, 16, 2);

int encoderVal = 0;
int prevA = HIGH;
int prevB = HIGH;
int swVal = HIGH;

void setup() {
  pinMode (encoderA, INPUT);
  pinMode (encoderB, INPUT);
  pinMode (encoderSW, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  attachInterrupt(0, setEncoderValue, CHANGE);

}
void loop() {
 lcd.setCursor(0,0);
 lcd.print("Encoder : "); 
 
 if(encoderVal<10)
 lcd.print("  ");
 else if(encoderVal<100)
 lcd.print(" ");
 
 lcd.print(encoderVal); 
 lcd.setCursor(13,0);
 lcd.print("  "); 

 if (isBtnPressed()){
    encoderVal = 0;
 }

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

int setEncoderValue()
{
  int interval = 5;
  encoderVal+= interval * getEncoder();
  //encoderVal = constrain(encoderVal, 0, 255);
}

bool isBtnPressed()
{
  int newSwVal = digitalRead(encoderSW);
  bool result;
  if (swVal==HIGH && newSwVal==LOW){
    lcd.clear();
    lcd.print("reset");
    result = true;
    delay(500);
  }
  else
  result = false;
  
  swVal=newSwVal;
  return result;
}
