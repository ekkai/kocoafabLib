// 스마일팟 키트 - led_matrix_2.ino
// LED 매트릭스에 다양한 표정 출력 

// lc.shutdown(매트릭스 번호, 모드) : 해당 번호의 LED매트릭스의 절전 모드 사용 여부(true/false)를 설정
// lc.setIntensity(매트릭스 번호, 세기) : 해당 번호의 LED매트릭스의 밝기 정도를 설정
// lc.clearDisplay(매트릭스 번호) : 해당 번호의 LED매트릭스를 모두 초기화
// lc.setRow(매트릭스 번호, 매트릭스의 열 위치, 바이너리 데이터) : 해당 매트릭스의 '열 위치'에 '바이너리 데이터'대로 출력

#include "LedControl.h" 

LedControl lc = LedControl(12, 10, 11, 1);

// 웃는 표정
byte a[8] = {
  B00000000,
  B00100100,
  B00100100,
  B00000000,
  B01111110,
  B01111110,
  B00111100,
  B00000000
};

// 우는 표정
byte b[8] = {
  B00000000,
  B11100111,
  B01000010,
  B01000010,
  B00000000,
  B00111100,
  B01000010,
  B10000001
};

// 화난 표정
byte c[8] = {
  B10000001,
  B01000010,
  B00100100,
  B00000000,
  B00000000,
  B00111100,
  B01111110,
  B11111111
};

void setup() {
  Serial.begin(9600);
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}
void loop(){
  // 토양수분센서 값 value에 저장
  int value = analogRead(A0);

  // value값 시리얼 모니터 출력
  Serial.print("read sensor value : ");
  Serial.println(value);

 
  if(value < 300)  // 만약 측정 값이 300 미만이면  
  { 
    for(int i = 0; i < 8; i++){
    lc.setRow(0, i, a[i]); // LED_matrix에 a배열(웃는표정) 출력 
  }
    delay(1000); 
  }
  else if(value < 600)  // 만약 측정 값이 300이상, 600 미만이면  
  { 
    for(int i = 0; i < 8; i++){
    lc.setRow(0, i, b[i]); // LED_matrix에 a배열(우는표정) 출력
  }
    delay(1000);
  }
  
  else // 둘 다 아니면(만약 측정 값이 600 이상이면)
  { 
    for(int i = 0; i < 8; i++){
    lc.setRow(0, i, c[i]); // LED_matrix에 a배열(화난표정) 출력
  }
    delay(1000);
  }
}
