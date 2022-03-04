// 미세먼지측정기(공기청정기) 키트 - motor_3.ino
// 로터리엔코더를 활용한 팬모터 제어 (Enable 핀 활용)

#define encoderA 2
#define encoderB 3

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
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  
  // motorEn 핀에 PWM 값을 줘서 제어하기 때문에 팬모터 정방향 회전
  digitalWrite(motorA, HIGH);
  digitalWrite(motorB, LOW);
  
  analogWrite(motorEn, 0);
  Serial.begin(9600);
  attachInterrupt(0, setEncoderValue, CHANGE);
}

void loop()
{
  analogWrite(motorEn, encoderVal); // motorEn핀에 encoderVal 만큼 PWM 제어
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
