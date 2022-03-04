// RC카 키트 - serial_3.ino
// 조건 판별 결과 serial 출력

// Serial.begin(통신속도) : 해당 통신속도로 시리얼 통신 초기화
// Serial.print("문장" or 변수) : " "안의 문장 또는 변수 값을 시리얼 통신으로 출력

char data = 'a';

void setup(){
  Serial.begin(9600); 
}

void loop(){
    if(data == 'a'){ // 만약 문자형 변수 data의 값이 'a'와 같다면
      Serial.println("True");
    }
    else{ // 만약 문자형 변수 data의 값이 'a'와 같지 않다면
      Serial.println("False");
    }     
}
