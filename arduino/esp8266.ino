#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include <SPI.h>
#include <MFRC522.h>

#define DHTPIN 5
#define DHTTYPE DHT11
#define SS_PIN 10
#define RST_PIN 9
#define TRIG_PIN 6
#define ECHO_PIN 7

DHT dht(DHTPIN, DHTTYPE);
MFRC522 rfid(SS_PIN, RST_PIN);
SoftwareSerial espSerial(2, 3);

float temperature = 0.0;
float humidity = 0.0;
long distance = 0;
String cardUID;

void setup() {
  Serial.begin(115200);
  espSerial.begin(9600);
  rfid.PCD_Init();
  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // RFID Kart Okuma
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    cardUID = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      cardUID += String(rfid.uid.uidByte[i], HEX);
      if (i < rfid.uid.size - 1) {
        cardUID += ":";
      }
    }
    cardUID.toUpperCase();
    rfid.PICC_HaltA();
  }

  // DHT11 Okuma
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  // HC-SR04 Mesafe Hesaplama
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.0344 / 2;

  // JSON Oluşturma
  StaticJsonDocument<200> jsonDoc;
  jsonDoc["temperature"] = temperature;
  jsonDoc["humidity"] = humidity;
  jsonDoc["distance"] = distance;
  jsonDoc["uid"] = cardUID;

  String jsonString;
  serializeJson(jsonDoc, jsonString);

  // ESP ve Seri Monitör
  espSerial.println(jsonString);
  Serial.println("Gelen Veri:");
  Serial.println(jsonString);

  delay(1500);
}
