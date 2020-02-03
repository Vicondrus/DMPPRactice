int model = 0;
int si = 5;
int clk = 6;

void setup() {
  pinMode(si, OUTPUT);
  pinMode(clk, OUTPUT);
  digitalWrite(clk, LOW);
}

void loop() {
  int x = model;  //start from a bit then negate it repetedly
  for (int i = 0; i < 8; i++) {
    if (x == 1) {
      digitalWrite(si, HIGH);
    } else {
      digitalWrite(si, LOW);
    }
    delay(1); //wait for output to be stable
    digitalWrite(clk, HIGH);  //change clk
    delay(1); //wait
    digitalWrite(clk, LOW); //clk low for further changes
  }
  model = 1 - model;  //change the model
  delay(1000 - 16); //wait for the rest of the second

}
