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
