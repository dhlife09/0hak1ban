void setup(){
  Serial.begin(9600);
}
void loop(){
  Serial.print("arduino ");
  Serial.print("world!!");
  Serial.end();
}

//arduino 프로그램에서 돋보기 모양을 누르면 시리얼모니터 확인가능
