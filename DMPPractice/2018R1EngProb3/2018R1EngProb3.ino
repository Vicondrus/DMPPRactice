#include <Wire.h>

void setup() {
  Wire.begin();
}

void loop() {
  for(int i=0;i<20;i++){
    int y = (1.5 + 1.5*sin(i/20 * 2*PI))*10;
    int toSend = map(y,0,33,0,255);
    Wire.beginTransmission(0x65);
    Wire.write(toSend);
    Wire.endTransmission();
    delay(1);
  }
}
