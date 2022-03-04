// 로봇팔 키트 - Serial_1.ino
// Serial 통신을 통해 데이터 받기

// Serial.begin(통신속도) : 해당 통신속도로 시리얼 통신 초기화
// Serial.available() : 시리얼통신을 통해 유효한 값이 전송 되었을 때 true
// Serial.read() : 시리얼통신을 통해 전송 받은 값을 읽어 저장 변수에 저장
// Serial.print(ln)("문장" or 변수) : 변수 데이터를 시리얼 통신을 통해 출력


char data;

void setup(){
  Serial.begin(9600); 
}

void loop(){
 if(Serial.available()){
    data = Serial.read();
    Serial.print("Input : ");
    Serial.println(data);   
 } 
}
