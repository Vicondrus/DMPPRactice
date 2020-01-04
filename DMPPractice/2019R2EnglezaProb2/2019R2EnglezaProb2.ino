void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  uint32_t pressure = readSensor();
  Serial.println(pressure);
  delay(3000);
}

uint32_t readSensor(){
  uint32_t pressure = 0;
  Serial1.write('p');
  while(!Serial1.available()){}
  int q = Serial1.read();
  pressure = q;
  q = Serial1.read();
  pressure = (pressure<<8)+q;
  q = Serial1.read();
  pressure = (pressure<<8)+q;
  return pressure;
}
