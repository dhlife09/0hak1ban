#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);     // 접근주소: 0x3F or 0x27

//개인정보(이름)
String name = "Hong Gildong";

//1번 질문: 코로나19 임상증상 여부(체온측정)

//2번 질문: 학생 또는 동거인 코로나19 검사결과 대기 중 여부
bool ans2 = false;

//3번 질문: 학생 또는 동거인 자가격리 중 여부
bool ans3 = false;

//4번 질문: 학생 동거인 중 확진자 여부
bool ans4 = false;

const int buttonPin=2;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  lcd.init();                      // LCD 초기화
  lcd.backlight();                // 백라이트 켜기
  lcdStatusUpdate(0, 0);
}

void lcdStatusUpdate(int code, float temp) {
  //미참여(0), 등교가능(1), 등교불가(2), 체온측정중(3), 체온측정완료(4), 기타조건에의한 등교불가(5)
  lcd.init();                      // LCD 초기화
  lcd.setCursor(0,0);             // 1번째, 1라인
  lcd.print("Bia High School");
  lcd.setCursor(0,1);             // 1번째, 2라인
  lcd.print("" + name);             // 1번째, 2라인
  lcd.setCursor(0,2);
  lcd.print("--------------------");
  lcd.setCursor(0,3);
  if(code == 1) {
    lcd.print("You can go school!");
    return;
  } else if(code == 2) {
    lcd.print("You can't go school!");
    return;
  } else if(code == 3) {
    lcd.print("Checking..");
  } else if(code == 4) {
    String strtemp = String(temp, 1);
    String giho = "'C";
    lcd.print(strtemp+giho);
  } else if(code == 5) {
    lcd.print("You can't go school!");
    delay(1500);
    lcd.init();                      // LCD 초기화
    lcd.setCursor(0,0);             // 1번째, 1라인
    lcd.print("Bia High School");
    lcd.setCursor(0,1);             // 1번째, 2라인
    lcd.print("" + name);             // 1번째, 2라인
    lcd.setCursor(0,2);
    lcd.print("--------------------");
    lcd.setCursor(0,3);
    lcd.print("Some questions");
    delay(2000);
    lcd.setCursor(0,3);
    lcd.print("are checked true!");
  } else {
    lcd.print("Please check!!");
  }
}

void printTemp(float a) {
  Serial.print("[알림] 측정된 체온: " + String(a, 1) + "°C\n");
}


void loop() {
    int val=digitalRead(buttonPin);
    if(val == LOW) {
        //버튼을 누르지 않은 상태
    } else {
        //버튼을 누른 상태(체온측정)
        lcdStatusUpdate(3, 0);
        Serial.println("[알림] 체온 측정 중");
        delay(1500);
        float temp=random(359,380)/10.0;
        if(temp>=37.5) {
          Serial.println("[주의] 코로나19 증상(발열)이 있습니다.");
          printTemp(temp);
          lcdStatusUpdate(4, temp);
          delay(700);
          lcdStatusUpdate(2, 0);
        } else {
          printTemp(temp);
          lcdStatusUpdate(4, temp);
          delay(700);
          if(ans2 == false && ans3 == false && ans4 == false) {
            Serial.println("[완료] 등교할 수 있습니다.");
            lcdStatusUpdate(1, 0);  //발열 증상 없고 모든 조건에 문제없음
          } else {
            Serial.println("[주의] 발열 증상이 없으나 다른 질문 항목에 체크되어있습니다.");
            lcdStatusUpdate(5, 0);  //발열 증상 없으나 다른 조건에 의한 등교불가
          }
        }
    }
}
