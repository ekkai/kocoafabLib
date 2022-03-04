// 스마일팟 키트 - led_matrix_1.ino
// LED 매트릭스 출력 실습

// lc.shutdown(매트릭스 번호, 모드) : 해당 번호의 LED매트릭스의 절전 모드 사용 여부(true/false)를 설정
// lc.setIntensity(매트릭스 번호, 세기) : 해당 번호의 LED매트릭스의 밝기 정도를 설정
// lc.clearDisplay(매트릭스 번호) : 해당 번호의 LED매트릭스를 모두 초기화
// lc.setRow(매트릭스 번호, 매트릭스의 열 위치, 바이너리 데이터) : 해당 매트릭스의 '열 위치'에 '바이너리 데이터'대로 출력

#include "LedControl.h" 

LedControl lc = LedControl(12, 10, 11, 1);

// byte형 8칸 배열
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

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop(){
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, a[i]); // 한 열당 바이너리 데이터(a[i])의 1인 부분만 LED 점등
  }
  delay(1000);
}
