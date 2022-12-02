void setup(){
  // 시리얼 통신 속도 설정 9600bps
  Serial.begin(9600);  
}

void loop(){
  // 시리얼 모니터에 "Hello World" 를 출력합니다.
  Serial.println("Hello World");
}
