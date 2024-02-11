#include<LiquidCrystal.h>

LiquidCrystal lcd(0,1,2,3,4,5);
#define sensor1 8
#define sensor2 9
#define sensor3 10
#define sensor4 11
#define closeGate 6
#define openGate 7


// parking area full
byte park[8]={
  0b10001,
  0b10001,
  0b01010,
  0b00100,
  0b01010,
  0b10001,
  0b10001,
};

// parking area empty
byte npark[8]={
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
};

int pA1, pA2, pA3,IRead1,IRead2, IRead3;

void setup() {
  
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
 
  pinMode(openGate, OUTPUT);
  pinMode(closeGate, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);

  lcd.createChar(0, park);
  lcd.createChar(1, npark);

  lcd.begin(16, 2);
  lcd.print("Gate Opening");
  digitalWrite(openGate, HIGH);
  digitalWrite(closeGate, LOW);
  delay(1000);
  digitalWrite(openGate, LOW);
  digitalWrite(closeGate, LOW);
  lcd.clear();
}

void loop() {

  
  lcd.setCursor(0,0);
  lcd.print("PA1 PA2 PA3");
  pA1 = digitalRead(sensor1);
  pA2 = digitalRead(sensor2);
  pA3 = digitalRead(sensor3);

  IRead1 = digitalRead(A0);
  if(IRead1 == LOW){
    digitalWrite(13,HIGH);
    }else{
      digitalWrite(13,LOW);
      }

  IRead2 = digitalRead(A1);
  if(IRead2 == LOW){
    digitalWrite(12,HIGH);
    }else{
      digitalWrite(12,LOW);
    }

  IRead3 = digitalRead(A2);
  if(IRead3 == LOW){
    digitalWrite(11,HIGH);
    }else{
      digitalWrite(11,LOW);
      }

  // parking slot1
  if(pA1 == 1) {
    lcd.setCursor(1, 1);
    lcd.write(byte(1));
  } else {
    lcd.setCursor(1, 1);
    lcd.write(byte(0));
  }

  // parking slot2
  if(pA2 == 1) {
    lcd.setCursor(5, 1);
    lcd.write(byte(1));
  } else {
    lcd.setCursor(5, 1);
    lcd.write(byte(0));
  }

  // parking slot3
  if(pA3 == 1) {
    lcd.setCursor(9, 1);
    lcd.write(byte(1));
  } else {
    lcd.setCursor(9, 1);
    lcd.write(byte(0));
  }


  if(pA1 == 0 && pA2 == 0 && pA3 == 0 ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Gate closing");
    digitalWrite(closeGate, HIGH);
    digitalWrite(openGate, LOW);
    delay(1000);
    digitalWrite(closeGate, LOW);
    digitalWrite(openGate, LOW);
  }
}
