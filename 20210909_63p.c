int Led=13;
int Trig=7;
int Echo=6;

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Led, OUTPUT);
}

void loop() {
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  int duration = pulseIn(Echo, HIGH);
  int distance = duration /29 /2;
  Serial.print("Distance");
  Serial.print(distance);
  Serial.print("cm");
  if(distance<20) {
    digitalWrite(Led, HIGH);
  } else {
    digitalWrite(Led, LOW);
  }
}
