#include <Wire.h>

int switchesPins[4] = {4, 5, 6, 7};
int ledsPins[8] = {30, 31, 32, 33, 34, 35, 36, 37};
int address = 5*16;

void setup() {
  //the address is not fixed, so Wire.begin(address)
  //should be called in the loop
  for(int i=0;i<4;i++){
    pinMode(switchesPins[i],INPUT);
  }
  for(int i=0;i<8;i++){
    pinMode(ledsPins[i],OUTPUT);
  }
}

void loop() {
  for(int i=0;i<4;i++){
    if(digitalRead(switchesPins[i]==HIGH)){
      address |= (1 << i);
    }else{
      address &= ~(1 << i);
    }
  }
  Wire.begin(address);
  Wire.onRequest(showLeds);
}

void showLeds(){
  while(Wire.available() < 0){}
  byte b = Wire.read();
  for(int i=0;i<8;i++){
    if((b >> i) & 1 == 1){
      digitalWrite(ledsPins[i],HIGH);
    }else{
      digitalWrite(ledsPins[i],LOW);
    }
  }
}
