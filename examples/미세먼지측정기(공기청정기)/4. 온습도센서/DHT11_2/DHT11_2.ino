// 미세먼지측정기(공기청정기) 키트 - DHT11_2.ino
// 온습도센서를 활용한 불쾌지수 산출

// dht.begin() : 온습도센서 초기화
// dht.readHumidity() : 온습도센서에서 습도값을 읽어와 출력
// dht.readTemperature() : 온습도센서에서 온도값을 읽어와 출력
// isnan(data) : data가 수치 값을 갖고 있지 않은 경우 판별 (nan = not a number) 

#include <DHT.h>

#define DHTPIN 6
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

  float discomfortIndex = (1.8 * t) - (0.55 * (1 - h / 100.0) * (1.8 * t - 26)) + 32;
  Serial.println(discomfortIndex);

  delay(1000);

}
