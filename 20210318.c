void setup() {
  int iCount=11, iCountMax=13, delayTime=100;
  for (int i=iCount; i<iCountMax; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=11; i<13; i++) {
    digitalWrite(i, HIGH);
    delay(100);
  }
  for (int i=11; i<13; i++) {
    digitalWrite(i, LOW);
    delay(100);
  }
}
