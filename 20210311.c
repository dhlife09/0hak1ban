int led1=10, led2=9, led3=11;
//led1 = yellow
//led2 = green
//led3 = red

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  
  digitalWrite(led3, HIGH);
  delay(1000);
  digitalWrite(led3, LOW);
  digitalWrite(led1, HIGH);
  delay(700);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(1100);
}
