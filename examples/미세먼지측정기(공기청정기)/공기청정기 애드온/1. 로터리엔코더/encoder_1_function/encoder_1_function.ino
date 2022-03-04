// 미세먼지측정기(공기청정기) 키트 - encoder_1_function.ino
// 함수를 활용한 로터리 엔코더 제어

// encoder_1.ino를 사용자 정의 함수를 활용하여 구현

#define encoderA 2
#define encoderB 3
#define encoderSW 7

int encoderVal = 0;
int prevA = HIGH;
int prevB = HIGH;
int swVal = HIGH;

void setup() {
  pinMode (encoderA, INPUT);
  pinMode (encoderB, INPUT);
  pinMode (encoderSW, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  int result = getEncoder();
  encoderVal = encoderVal + result;
  //encoderVal = constrain(encoderVal, 0, 255);
  Serial.println(encoderVal);
    
  if (isBtnPressed())
  {
    encoderVal = 0;
  }

}

int getEncoder() {
  int result = 0;
  int newA = digitalRead(encoderA);
  if (prevA != newA) {
    int newB = digitalRead(encoderB);
    if (newB != newA) {
      result = 5;
    } else {
      result = -5;
    }
  }
  prevA = newA;
  return result;
}


bool isBtnPressed()
{
  int newSwVal = digitalRead(encoderSW);
  bool result;
  
  if (swVal==HIGH && newSwVal==LOW){
    result=true;
    Serial.println("reset");
    delay(500);
  }
  else
    result = false;

  swVal=newSwVal;
  return result;
}
