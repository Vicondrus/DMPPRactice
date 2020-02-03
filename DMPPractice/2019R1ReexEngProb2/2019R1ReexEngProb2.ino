int interruptPin = 4;
volatile int zeroTime = -1;
volatile int oneTime = -1;
volatile int startTime;

void setup() {
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(4), analyze, CHANGE);
  Serial.begin(9600);
  startTime = micros();
}

void loop() {
  if (zeroTime != -1 && oneTime != -1) {
    Serial.print((oneTime * 100) / (oneTime + zeroTime));
    Serial.println("%");
  }
}

void analyze() {
  if (digitalRead(interruptPin) == HIGH) {
    //means that the preavious value (before CHANGE) was LOW
    zeroTime = micros() - startTime;
  } else {
    //previous value was HIGH
    oneTime = micros() - startTime;
  }
  startTime = micros();
}
