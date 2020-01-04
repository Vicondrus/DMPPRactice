#define m00 5
#define m01 6
#define m10 3
#define m11 11

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
}

void loop() {
  // put your main code here, to run repeatedly:

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

void rotateWith(int dir){
  //rotate with dir * 45 degrees (8 directions)
  motorGo(m00,m01,1,128);
  motorGo(m10,m11,0,128);
  delay(dir * 250);
  motorGo(m00,m01,0,0);
  motorGo(m10,m11,0,0);
}

int searchLight() {
  int x = 0;
  int maxim = -1;
  int dir = -1;
  for (int i = 0; i < 8; i++) {
    
    x = analogRead(A0); //read forward light
    if (maxim < x) {  //compare with maximum
      maxim = x;
      dir = i;
    }

    rotateWith(1);  //rotate another 45 degrees
    
  }
  //reach innitial position
  return dir;
}

void euglena(){
  int dir = searchLight();
  rotateWith(dir);
}
