#include<Arduino.h>
void Print_7SEG(byte number);
void Clear(); 
void quetled();
int DV=0;
int CHUC=0;
int TRAM =0;
int NGHIN=0;
int num;
int KDV=3; 
int KCHUC=7;
int KTRAM=6;
int KNGHIN=4;
int a=5;
int b=2;
int c=9;
int d=11;
int e=12;
int f=10;
int g=8;
int dl=10;
void setup() {
  pinMode(KDV, OUTPUT); 
  pinMode(KCHUC, OUTPUT);
  pinMode(KTRAM, OUTPUT);
  pinMode(KNGHIN, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT); 
  Serial.begin(9600);  // Khởi tạo kết nối với Python qua cổng Serial
}

void loop() {
 if (Serial.available()) {
    num = Serial.parseInt();
 }
    quetled();
    Serial.println("OK"); // Gửi tín hiệu "OK" để báo cho Python biết đã nhận được số
}
  
void quetled()
{
  NGHIN=(num/100)/10;
  TRAM=(num/100)%10;
  CHUC=(num%100)/10; 
  DV=num%10;
   Clear();
    digitalWrite(KDV, HIGH);
    digitalWrite(KCHUC, LOW);
    digitalWrite(KTRAM, LOW);
    digitalWrite(KNGHIN, LOW);
    Print_7SEG(DV);
    delay(dl);
    Clear();
     digitalWrite(KDV, LOW);
    digitalWrite(KCHUC, HIGH);
    digitalWrite(KTRAM, LOW);
    digitalWrite(KNGHIN, LOW);
    Print_7SEG(CHUC);
    delay(dl);
    Clear();
     digitalWrite(KDV, LOW);
    digitalWrite(KCHUC,LOW );
    digitalWrite(KTRAM, HIGH);
    digitalWrite(KNGHIN, LOW);
    Print_7SEG(TRAM);
    delay(dl);
    Clear(); 
      digitalWrite(KDV, LOW);
    digitalWrite(KCHUC,LOW );
    digitalWrite(KTRAM, LOW);
    digitalWrite(KNGHIN, HIGH);
    Print_7SEG(NGHIN);
    delay(dl);
    Clear();
}

void Clear()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void Print_7SEG(byte number)
{
  switch (number)
  {
    case 0:
      digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
      break;
    case 1:
      digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
      break;
    case 2:
      digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
      break;
    case 3:
      digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
      break;
    case 4:
      digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
      break;
    case 5:
      digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
      break;
    case 6:
     digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
      break;
    case 7:
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
      break;
    case 8:
     digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
      break;
    case 9:
      digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
      break;
  }
}
