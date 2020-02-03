int degr;
int motorPin = 11;

void setup() {
  pinMode(A0, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  //suppose that a sensor outputs exactly the the temperature
  int x = analogRead(A0);
  if(x < 20){
    digitalWrite(motorPin,0);
  }else if(x > 30){
    analogWrite(motorPin,1023);
  }else {
    analogWrite(motorPin,map(x,20,30,0,1023));
  }
  delay(3);
}
