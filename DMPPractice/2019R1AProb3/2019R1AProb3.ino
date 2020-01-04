#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  pinMode(A0, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  int distance = readSensor();
  writeOnLcd(distance);
  delay(3000);
}

float customMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int readSensor() {
  int input = analogRead(A0);
  float voltage = input * 0.049; //(5V / 2015 units)
  float distance = -1;
  if (2 < voltage < 4.5) {
    distance = customMap(voltage, 4.5, 2, 5, 15); //linear interpolation between known values
  } else if (1 < voltage < 2) {
    distance = customMap(voltage, 2, 1, 15, 30);
  } else if (0.5 < voltage < 1) {
    distance = customMap(voltage, 1, 0.5, 30, 45);
  }
  return (int) distance;
}

void writeOnLcd(int a){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(a);
}
