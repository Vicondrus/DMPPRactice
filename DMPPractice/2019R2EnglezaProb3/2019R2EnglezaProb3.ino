#include<Servo.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

Servo srv;

int degree = -1;
int closest = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
}

void loop() {
  searchClosest(8); //a pin with PWM
  int dist = convertToCm(closest);
  writeOnLcd(degree, dist);
}

void searchClosest(int pin){
  closest = 1000;
  degree = -1;
  srv.attach(pin);
  int dist;
  for(int i=0;i<180;i++){
    srv.write(i);
    delay(20);
    dist = analogRead(A0);
    if(dist < closest){
      closest = dist;
      degree = i;
    }
  }
  srv.detach();
}

void writeOnLcd(int a, int b){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write((byte)a);
  lcd.setCursor(0,1);
  lcd.write((byte)b);
}

int convertToCm(int input){
  float voltage = ((float )input) * 0.0049; // (5 V /1024 units);
  float distance = voltage / 0.05;
  return (int) voltage;
}
