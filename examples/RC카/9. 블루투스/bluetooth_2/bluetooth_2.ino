// RC카 키트 - bluetooth_2.ino
// 자동으로 블루투스 장치 설정 

#include <SoftwareSerial.h> 

SoftwareSerial BTSerial(4, 5); 

void setup() {
  Serial.begin(9600);  
  BTSerial.begin(9600);
  delay(1000);
  BTSerial.write("AT+NAME");
  BTSerial.write("바꾸고 싶은 이름"); // "  " 안에 바꿀 장치 이름을 영문이나 숫자를 넣어 입력
  BTSerial.write("\r\n");
  delay(300);
  BTSerial.write("AT+RESET"); 
  BTSerial.write("\r\n");
  delay(300);
}

void loop() {
}
