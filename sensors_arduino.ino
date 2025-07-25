#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

Adafruit_SSD1306 display(128, 64, &Wire);

void setup() {
  Serial.begin(9600);
  dht.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize OLED
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  display.clearDisplay();

  if (isnan(h) || isnan(t)) {
    display.setCursor(0,0);
    display.println("Sensor Error!");
  } else {
    display.setCursor(0,0);
    display.print("Temp: "); display.print(t); display.println(" C");
    display.print("Humidity: "); display.print(h); display.println(" %");
  }

  display.display();
}
