void setup() {
}

void loop() {
  // 1초간 빨간색 점등
  analogWrite(9,255);
  analogWrite(10,0);
  analogWrite(11, 0); 
  delay(1000); 

  // 1초간 노란색 점등
  analogWrite(9,255);
  analogWrite(10,255);
  analogWrite(11, 0); 
  delay(1000);  

  // 1초간 초록색 점등
  analogWrite(9,0);
  analogWrite(10,0);
  analogWrite(11, 255); 
  delay(1000);
}
