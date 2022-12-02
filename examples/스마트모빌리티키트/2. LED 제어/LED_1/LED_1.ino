void setup(){
  // LED가 연결된 디지털 9번핀을 출력핀으로 설정합니다.
  pinMode(9, OUTPUT);  
}

void loop(){
  // 1초마다 LED를 깜빡입니다.
  digitalWrite(9, HIGH); 
  delay(1000);
  digitalWrite(9, LOW);
  delay(1000);  
}
