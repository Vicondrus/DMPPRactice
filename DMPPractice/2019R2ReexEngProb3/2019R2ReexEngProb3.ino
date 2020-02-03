#include <Wire.h>

int centigrades = -1;

void setup() {
  pinMode(A0, INPUT);
  Wire.begin(0x4C);
  Wire.onRequest(sendData);
}

void loop() {
  int x = analogRead(A0);
  int centigrades = (x*5/1024)/0.01;
  delay(200);
}

void sendData(){
  Wire.write(centigrades);
}
