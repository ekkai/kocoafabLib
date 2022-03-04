// 미세먼지측정기(공기청정기) 키트 - encoder_1.ino
// 로터리 엔코더 기초 제어 
// 로터리 엔코더의 시계/반시계 방향 회전과 버튼 스위치를 인식할 수 있는 기초예제

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
  
  int result =0;
  int newA = digitalRead(encoderA);
  if (prevA != newA) 
  {
    int newB = digitalRead(encoderB);
    if (newB != newA) {
      result = 1;
    } else {
      result = -1;
    }
  }
  prevA = newA;
  encoderVal = encoderVal + result;
  //encoderVal = constrain(encoderVal, 0, 255);
  Serial.println(encoderVal);
    
  int newSwVal = digitalRead(encoderSW);

  if (swVal==HIGH && newSwVal==LOW){
    Serial.println("reset");
    delay(500);
    encoderVal=0;
  }
  swVal=newSwVal;
}
