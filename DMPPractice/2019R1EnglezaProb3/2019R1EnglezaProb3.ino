#define m00 5
#define m01 6
#define m10 3
#define m11 11

int searchTime = 3000;

void setup() {
  // put your setup code here, to run once:
  digitalWrite(m00, 0);
  digitalWrite(m01, 0);
  digitalWrite(m10, 0);
  digitalWrite(m11, 0);
  pinMode(m00, OUTPUT);
  pinMode(m01, OUTPUT);
  pinMode(m10, OUTPUT);
  pinMode(m11, OUTPUT);
  pinMode(A0, INPUT);
  euglena();
}

void loop() {
  
}

void motorGo(int m1, int m2, int forward, int speed)
{
  if (speed == 0) {
    digitalWrite(m1, 0);
    digitalWrite(m2, 0);
  } else if (forward == 1) {
    analogWrite(m1, speed);
    digitalWrite(m2, 0);
  } else {
    digitalWrite(m1, 0);
    analogWrite(m2, speed);
  }
}

void rotateWith(int dir) {
  //rotate with dir * 45 degrees (8 directions)
  motorGo(m00, m01, 1, 128);
  motorGo(m10, m11, 0, 128);
  delay(dir * 250);
  motorGo(m00, m01, 0, 0);
  motorGo(m10, m11, 0, 0);
}

int searchLight() {
  int startTime = millis();
  int maxim = -1;
  int x;
  while (millis() - startTime < searchTime) {

    x = analogRead(A0); //read forward light
    if (maxim < x) {  //compare with maximum
      maxim = x;
    }

    rotateWith(1);  //rotate another 45 degrees

  }
  return maxim;
}

void euglena() {
  int maxim = searchLight();
  int x = analogRead(A0);;
  while ((maxim - x) > 5) {
    rotateWith(1);
    x = analogRead(A0);
  }
}
