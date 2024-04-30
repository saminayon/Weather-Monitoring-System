#include <DHT.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int mq4Pin = A0;
const int yl83Pin = A1; // Corrected variable name

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

SoftwareSerial esp8266(9, 10); // RX, TX

void setup() {
  Serial.begin(9600);
  esp8266.begin(115200);
  dht.begin();
  lcd.begin(16, 2);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float gasValue = analogRead(mq4Pin);
  float soilMoisture = analogRead(yl83Pin); // Corrected variable name

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("C | Humidity: ");
  Serial.print(humidity);
  Serial.print("% | Gas: ");
  Serial.print(gasValue);
  Serial.print(" | Moisture: ");
  Serial.println(soilMoisture);

  sendDataToThingSpeak(temperature, humidity, gasValue, soilMoisture);

  delay(2000);
}

void sendDataToThingSpeak(float temp, float hum, float gas, float moisture) {
  String apiKey = "YOUR_API_KEY";
  String data = "field1=" + String(temp) + "&field2=" + String(hum) + "&field3=" + String(gas) + "&field4=" + String(moisture);
  String cmd = "AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80";
  esp8266.println(cmd);
  delay(2000);
  if (esp8266.find("OK")) {
    Serial.println("TCP connection established");
  }
  String postRequest = "POST /update HTTP/1.1\n";
  postRequest += "Host: api.thingspeak.com\n";
  postRequest += "Connection: close\n";
  postRequest += "X-THINGSPEAKAPIKEY: " + apiKey + "\n";
  postRequest += "Content-Type: application/x-www-form-urlencoded\n";
  postRequest += "Content-Length:" + String(data.length()) + "\n\n";
  postRequest += data;
  String sendCmd = "AT+CIPSEND=";
  sendCmd += String(postRequest.length());
  esp8266.println(sendCmd);
  delay(1000);
  if (esp8266.find(">")) {
    Serial.println("Sending data to ThingSpeak");
    esp8266.print(postRequest);
  }
  else {
    Serial.println("AT+CIPCLOSE");
    esp8266.println("AT+CIPCLOSE");
  }
}
