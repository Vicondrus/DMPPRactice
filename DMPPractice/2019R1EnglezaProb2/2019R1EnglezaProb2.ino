#include <Wire.h>

int data;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  readData();
  Serial.println(data);
  delay(3000);
}

void readData(){
  data = 0;
  char x;

  Wire.beginTransmission(0x65);
  Wire.write(1);
  Wire.endTransmission();

  Wire.requestFrom(0x65,1);

  while(!Wire.available()){}
  x = Wire.read();

  data = data * 256 + x;

  Wire.beginTransmission(0x65);
  Wire.write(0);
  Wire.endTransmission();

  Wire.requestFrom(0x65,1);

  while(!Wire.available()){}
  x = Wire.read();

  data = data * 256 + x;
  
}
