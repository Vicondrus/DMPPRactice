int dataPin = 3;
int clkPin = 4;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clkPin, OUTPUT);
  digitalWrite(clkPin, LOW);
}

void loop() {
  
}

void transmitByte(byte x){
  for(int i=0;i<8;i++){ //for the 8 bits of a byte
    x = x>>1;
    if(x & 1 == 1){     //check whether LSB is 1 or 0
      digitalWrite(dataPin,HIGH);
    }else{
      digitalWrite(dataPin,LOW);
    }                             //then write it to dataPin
    delay(1);                    //keep low for 1 ms
    digitalWrite(clkPin,HIGH);   //make the rising edge
    delay(1);                    //keep up for 1 ms
    digitalWrite(clkPin,LOW);    //make falling edge
  }
  //clk period of 2ms = 500Hz
}
