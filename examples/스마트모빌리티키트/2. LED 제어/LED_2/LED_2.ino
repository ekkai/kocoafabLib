void setup(){
}

void loop(){
  // LED의 밝기를 최대로 점등
  analogWrite(9, 255);
  delay(500);
  
  // LED의 밝기를 중간값으로 점등
  analogWrite(9, 128);
  delay(500);
  
  // LED 소등
  analogWrite(9, 0); 
  delay(500); 
}
