#include <Arduino.h>

/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// partly from https://community.platformio.org/t/libraries-still-not-adding-what-am-i-doing-wrong/15998

// Import required libraries
//#include "WiFi.h"
//#include "ESPAsyncWebServer.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#define LED 5  //sparkfun esp32 thing internal led

DHT my_sensor(27,DHT11);

float temperature, humidity;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  my_sensor.begin();
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  Serial.println("LED most vilagit");
  delay(1900);
  digitalWrite(LED, LOW);
  Serial.println("LED most ujra sotet");
  delay(1600);

  humidity = my_sensor.readHumidity();
  temperature = my_sensor.readTemperature();
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);

}
