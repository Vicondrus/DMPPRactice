

void setup() {
  pinMode(A0,INPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  bipOverFifty();
  delay(1000);
}

int readTemperature(){
  int x = analogRead(A0);
  float voltage = x * 0.0049; //(5V / 1024 units)
  float temp = (voltage - 2) / 0.01; //(voltage / (voltage per degrees))
  return (int) temp;
}

void bipOverFifty(){
  int temp = readTemperature();
  if (temp > 50){
    tone(5, 100, 500);
    delay(500);
    tone(5, 100, 500);
    delay(500);
    noTone(5);
  }
}
