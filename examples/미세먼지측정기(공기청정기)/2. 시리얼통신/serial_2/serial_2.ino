// 미세먼지측정기(공기청정기) 키트 - serial_2.ino
// 변수를 활용한 serial 통신

// Serial.begin(통신속도) : 해당 통신속도로 시리얼 통신 초기화
// Serial.print("문장" or 변수) : " "안의 문장 또는 변수 값을 시리얼 통신으로 출력

char data = 'a';

void setup(){
  Serial.begin(9600); 
}

void loop(){
  Serial.println(data);   
}
