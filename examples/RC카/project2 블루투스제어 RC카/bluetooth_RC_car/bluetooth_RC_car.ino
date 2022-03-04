// RC카 키트 - bluetooth_RC_car.ino
// 블루투스 통신을 활용한 스마트폰 원격 제어 RC카

// BLE모듈간 통신을 위한 소프트웨어시리얼 라이브러리 추가
#include <SoftwareSerial.h>

// 소프트웨어시리얼 객체 생성 (4,5번핀 활용)
SoftwareSerial BTSerial(4, 5);

// 핀 설정
int in1 = 9;  
int in2 = 6;
int in3 = 10;
int in4 = 11;

int LSpeed = 255;   //왼쪽 바퀴 속도 (0~255)
int RSpeed = 255;   //오른쪽 바퀴 속도 (0~255)

char data;

void setup() {
  Serial.begin(9600);
  // BLE모듈의 소프트웨어 시리얼 통신 초기화
  BTSerial.begin(9600);
}

void loop() {
  // BLE모듈을 통해 전송된 데이터가 있을 때
  if (BTSerial.available()) {
    data = BTSerial.read();

    // data가 'f'라면 
    if (data == 'f') {
      //전진
      analogWrite(in1, RSpeed);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, LSpeed);
    }
    // data가 'r'이라면 
    if (data == 'r') {
      //우회전
      analogWrite(in1, 0);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, LSpeed);
    }
    // data가 'l'이라면 
    if (data == 'l') {
      //좌회전(핀 출력 변경 필요)
      analogWrite(in1, RSpeed);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, 0);
    }
    // data가 'b'이라면 
    if (data == 'b') {
      //후진
      analogWrite(in1, 0);
      analogWrite(in2, RSpeed);
      analogWrite(in3, LSpeed);
      analogWrite(in4, 0);
    }
    // data가 's'이라면     
    if (data == 's') {
      //멈춤
      analogWrite(in1, 0);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, 0);
    }
  }
}
