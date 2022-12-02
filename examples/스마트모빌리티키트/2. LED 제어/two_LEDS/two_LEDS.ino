void setup(){
}

void loop(){
  // 1번 LED 점등
  analogWrite(3, 255); 
  analogWrite(5, 255); 
  analogWrite(6, 255);
  
  analogWrite(9, 0); 
  analogWrite(10, 0); 
  analogWrite(11, 0); 
  delay(1000);

  // 2번 LED 점등
  analogWrite(3, 0); 
  analogWrite(5, 0); 
  analogWrite(6, 0);
  
  analogWrite(9, 255); 
  analogWrite(10, 255); 
  analogWrite(11, 255);
  delay(1000);  
}
