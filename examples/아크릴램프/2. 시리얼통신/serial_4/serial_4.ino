// 아크릴램프 키트 - serial_4.ino
// 조건 판별 결과 serial 출력

// Serial.begin(통신속도) : 해당 통신속도로 시리얼 통신 초기화
// Serial.print("문장" or 변수) : " "안의 문장 또는 변수 값을 시리얼 통신으로 출력


char data = 'a';

void setup(){
  Serial.begin(9600); 
}

void loop(){
    if(data == 'a'){
      Serial.println("True");
    }
    else{
      Serial.println("False");
    }     
}
