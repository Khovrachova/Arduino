#define trig 9
#define echo 8
long duration,CM;

#define trig1 10
#define echo1 11
long duration1,CM1;

#include <Wire.h> // библиотека для управления устройствами по I2C 
#include <LiquidCrystal_I2C.h> // подключаем библиотеку для QAPASS 1602

LiquidCrystal_I2C LCD(0x27,16,2); // присваиваем имя LCD для дисплея
void setup() {
  // put your setup code here, to run once:
pinMode (trig, OUTPUT);
pinMode (echo, INPUT);
Serial.begin(9600);

pinMode (trig1, OUTPUT);
pinMode (echo1, INPUT);

LCD.init(); // инициализация LCD дисплея
LCD.backlight(); // включение подсветки дисплея
}

void sonar1(){
digitalWrite(trig,LOW);
delayMicroseconds(5);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

duration=pulseIn(echo,HIGH);
CM=(duration/2)/29.1;

Serial.print("левый");
Serial.print(CM);
Serial.println("cm");
delay(500);}

void sonar2(){
digitalWrite(trig1,LOW);
delayMicroseconds(5);
digitalWrite(trig1,HIGH);
delayMicroseconds(10);
digitalWrite(trig1,LOW);
duration1=pulseIn(echo1,HIGH);
CM1=(duration1/2)/29.1;

Serial.print("правый");
Serial.print(CM1);
Serial.println("cm");
delay(500);}


void loop() {
  // put your main code here, to run repeatedly:
  sonar2();
  sonar1();

   LCD.display();
   LCD.setCursor(1,0);
      LCD.print(CM);     // печатаем сообщение на первой 
   LCD.setCursor(1,1);     // ставим курсор на 1 символ первой строки
      LCD.print(CM1);
   delay(500);
   LCD.clear();
}
