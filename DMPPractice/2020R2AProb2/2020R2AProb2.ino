#include <Wire.h>

char keyMap[4][4];// = {...}
int rowsPins[4] = {20, 21, 22, 23};
int colsPins[4] = {24, 25, 26, 27};
int number[4];
int nbSize = 0;
const char code[4]; //= {...};
int debTime = 100;

void setup() {
  Wire.begin();
  for (int i = 0; i < 4; i++) {
    pinMode(rowsPins[i], INPUT_PULLUP);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(colsPins[i], OUTPUT);
    digitalWrite(colsPins[i], HIGH);
  }
}

void loop() {
  char key = getKey();
  if (key != 0) {
    number[nbSize++] = key;
    if (nbSize == 4) {
      nbSize = 0;
      if (checkNb()) {
        Wire.beginTransmission(0x55);
        Wire.write("GRANTED");
        Wire.endTransmission();
      } else {
        Wire.beginTransmission(0x55);
        Wire.write("DENIED");
        Wire.endTransmission();
      }
    }
  }
}

bool checkNb() {
  if (number[0] == code[0] && number[1] == code[1] && number[2] == code[2] && number[3] == code[3]) {
    return true;
  }
  else {
    return false;
  }
}

char getKey() {
  char key = 0;
  for (int i = 0; i < 4; i++) {
    digitalWrite(colsPins[i], LOW);
    for (int j = 0; j < 4; j++) {
      if (digitalRead(rowsPins[i]) == LOW) {
        delay(debTime);
        while (digitalRead(rowsPins[i]) == LOW);
        key = keyMap[i][j];
      }
    }
    digitalWrite(colsPins[i], HIGH);
  }
  return key;
}
