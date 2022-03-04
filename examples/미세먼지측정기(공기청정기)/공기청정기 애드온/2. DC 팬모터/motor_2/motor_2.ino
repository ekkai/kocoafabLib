// 미세먼지측정기(공기청정기) 키트 - motor_2.ino
// 로터리엔코더를 활용한 팬모터 제어 (PWM 활용)

// #define 상수 값 : define을 활용해 상수를 선언하고 값을 부여

#define encoderA 2
#define encoderB 3

int encoderVal = 0;
int prevA = HIGH;
int prevB = HIGH;

int motorA = 10;
int motorB = 11;

// motorA, motorB 핀 출력모드 설정
// 인터럽트 활성화 setEncoderValue 함수 설정
void setup() {
  pinMode(encoderA, INPUT);
  pinMode(encoderB, INPUT);
  
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(0, setEncoderValue, CHANGE);
}

void loop() {
  
  analogWrite(motorA, encoderVal);
  analogWrite(motorB, 0);
  Serial.println(encoderVal);
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
