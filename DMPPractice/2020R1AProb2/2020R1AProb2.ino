#include "TimerOne.h"

byte cathodes[10];  // = {...};
int anPins[3] = {23, 24, 25};
int minusBut = 26;  //suppose we have an interrupt
int plusBut = 27;   //suppose we have an interurpt
int startBut = 28;  //suppose we have an interrupt
//cathodes connected to PORTA

volatile int timerValue = 0;
volatile bool countdown = false;

int litTime = 10; //???? how many FPS do the human eyes see?

int bcd[3];

void setup() {
  pinMode(minusBut, INPUT_PULLUP);
  pinMode(plusBut, INPUT_PULLUP);
  pinMode(startBut, INPUT_PULLUP);
  pinMode(A8, OUTPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(anPins[i], OUTPUT);
  }
  DDRA = 0b11111111;
  attachInterrupt(digitalPinToInterrupt(minusBut), decr, FALLING);
  attachInterrupt(digitalPinToInterrupt(plusBut), incr, FALLING);
  attachInterrupt(digitalPinToInterrupt(startBut), start, FALLING);
}

void loop() {
  if (countdown && timerValue == 0) {
    countdown = false;
    tone(A8, 100, 1000);
    Timer1.detachInterrupt();
  }
  printNb(timerValue);
}

void printNb(int nb) {
  convertToBCD(nb);
  for (int i = 0; i < 3; i++) {
    int millisStart = millis();
    digitalWrite(anPins[i], HIGH);
    PORTA = cathodes[bcd[i]];
    while (millis() - millisStart > litTime) {};
    digitalWrite(anPins[i], LOW);
  }
}

void convertToBCD(int nb) {
  for (int i = 2; i >= 0; i--) {
    bcd[i] = nb % 10;
    nb = nb / 10;
  }
}

void start() {
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(count);
  countdown = true;
}

void count() {
  timerValue--;
}

void incr() {
  if (timerValue < 999 && !countdown) {
    timerValue++;
  }
}

void decr() {
  if (timerValue > 0 && !countdown) {
    timerValue--;
  }
}
