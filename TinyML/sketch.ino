#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
float a = 0.62655769;
float b = 0.10029774;
float c = 0.27626861;
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pressurePin = A0;
float pressureValue;

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
  lcd.setCursor(0, 0);
  lcd.print("Weather");
   lcd.setCursor(0, 1);
  lcd.print(" Monitoring ");
  delay(2000);
  lcd.clear();
}

void loop() {
  delay(2000);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  pressureValue = analogRead(pressurePin);
  float pressure = map(pressureValue, 0, 1023, 970, 980); 
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  delay(2000);
  lcd.setCursor(0, 0); 
  lcd.print("Pressure(in hPa): ");
  lcd.setCursor(0, 1); 
  lcd.print(pressure);
  delay(2000);
  lcd.setCursor(0, 0);
  float rainfall = -a*temperature - b*humidity + c*pressure - 242.65;
  lcd.print("Rainfall(in mm): ");
  lcd.setCursor(0, 1); 
  lcd.print(rainfall);
  delay(3000);
  lcd.clear();
}
