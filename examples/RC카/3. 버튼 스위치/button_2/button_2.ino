// RC카 키트 - Button_2.ino
// 버튼 스위치 조건 판별 

// digitalRead(핀번호) : 해당핀에서 디지털 신호를 읽어 true or false 출력

void setup(){
  pinMode(3, OUTPUT);
  pinMode(8, INPUT);
}

void loop(){
  if(digitalRead(8) == LOW){
    digitalWrite(3, HIGH);
  } 
  else{
    digitalWrite(3, LOW); 
  }
}
