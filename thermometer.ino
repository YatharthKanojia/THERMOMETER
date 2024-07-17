#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
#define sensor A0
float tempOffset = -65.0; // Initialize with no offset

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" Digital ");
  lcd.setCursor(0, 1);
  lcd.print(" Thermometer ");
  delay(2000);
  lcd.clear();
}

void loop()
{
  float reading = analogRead(sensor);
  float voltage = (reading / 1023.0) * 5.0; // Convert reading to voltage
  float temperature = (voltage-0.5) * 100.0; // LM35 output is 10 mV per degree Celsius
  temperature += tempOffset; // Apply calibration offset

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Temperature");
  lcd.setCursor(4, 1);
  lcd.print(temperature);
  lcd.write("\xDF"); // Display the degree symbol
  lcd.print("C");
  delay(1000);
}
