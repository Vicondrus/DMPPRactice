#include <Wire.h>

int mode = -1;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(0x21);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Wire.onReceive(receiveFunction);
  Wire.onRequest(requestFunction);
}

void loop() {
  
}

void receiveFunction(int bytes){
  int x = Wire.read();
  if(x == 0)
    mode = 0;
  else if (x == 1)
    mode = 1;
  else if (x == 2)
    mode = 2;
}

void requestFunction(){
  int data;
  if(mode == 0){
    data = analogRead(A0);
    Wire.write((byte) data);
  }else if (mode == 1){
    data = analogRead(A1);
    Wire.write((byte) data);
  }else if (mode == 2){
    data = analogRead(A2);
    Wire.write((byte) data);
  }
}
