int heat = 0;

void setup() {
  Serial1.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  heatOn();
  if(heat == 1){
    //something like turnHeaterOn();
    digitalWrite(13, HIGH);
  }else{
    //turnHeaterOff();
    digitalWrite(13, LOW);
  }
  delay(3000);
}

int readTemperature(){
  while(!Serial1.available()){}
  int x = Serial1.read();
  int temp = x - 128;
  return temp;
}

void heatOn(){
  int temp = readTemperature();
  if(temp < 21){
    temp = 1;
  }else{
    temp = 0;
  }
}
