#include <DHT.h>
#include <Adafruit_Sensor.h>

#define ledVermelho 2
#define ledAzul 3

DHT dht(4, DHT22);


void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
  delay(1000);
  if(temperatura>25.00){
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVermelho, HIGH);
  }else{
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAzul, HIGH);
  }
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" *C || Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");

}

