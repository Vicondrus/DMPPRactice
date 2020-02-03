

int toSend = -1;
int sen1, sen2, sen3, sen4;

void setup() {
  Serial1.begin(9600, SERIAL_8N1);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
}

void loop() {
  sen1 = analogRead(A0);
  sen2 = analogRead(A1);
  sen3 = analogRead(A2);
  sen4 = analogRead(A3);
  delay(3000);
}

void serialEvent1(){
  while(Serial1.available() < 0){}
  int received = Serial1.read();
  if(received == 1){
    Serial1.print(sen1);
  }else if(received == 2){
    Serial1.print(sen2);
  }else if(received == 3){
    Serial1.print(sen3);
  }else if(received == 4){
    Serial1.print(sen4);
  }else {
    Serial1.print(-1);
  }
}
