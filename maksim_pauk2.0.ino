#include <IRremote.h> // подключаем библиотеку для IR приемника

IRrecv irrecv(A3); // указываем пин, к которому подключен IR приемник
decode_results results;
#include <Servo.h>
Servo servo_L12;
Servo servo_L11;
Servo servo_R12;
 Servo servo_R11;

Servo servo_ZaD_L21;
Servo servo_ZaD_R21;
Servo servo_ZaD_R22;
Servo servo_ZaD_L22;

//-------//
int pinSensorRight    = A0;
int pinSensorLeft     = A1;
int pinSensorCenter   = A2;
int line = 210; // для сравнения значений приходящих с датчиков 450

int last_job = 0;
int interline = 0;
int val = 0;



int objectNumber = 0;
bool hasObject = false;

#define trig 3
#define echo 2
long duration,CM;

//------//

const unsigned long L12_R22_0 = 140; //120
const unsigned long L22_R12_0 = 40; //60
const unsigned long C1_0 = 90;
const unsigned long del_0 = 200;

///----///


void setup() {
  // put your setup code here, to run once:
servo_L12.attach(4); // левая передняя нога сустав
  servo_L11.attach(5); // левая передняя нога корпус
    irrecv.enableIRIn();  // запускаем прием инфракрасного сигнала
  servo_ZaD_L21.attach(6); // левая задняя нога корпус
  servo_ZaD_L22.attach(7); //левая задняя нога сустав
   pinMode(A3, INPUT); // пин A0 будет входом (англ. «intput»)
  
  servo_R12.attach(10); // правая передняя нога сустав
  servo_R11.attach(11); // правая передняя нога корпус
  
  servo_ZaD_R21.attach(9); // правая задняя нога корпус
  servo_ZaD_R22.attach(8); // правая задняя нога сустав
  
////////////////////////////////////////////////////////////////
 servo_L12.write(L12_R22_0); // левая передняя нога сустав
 servo_L11.write(C1_0); // левая передняя нога корпус
  
 servo_ZaD_L21.write(C1_0); // левая задняя нога корпус
 servo_ZaD_L22.write(L22_R12_0 + 20); //левая задняя нога сустав
  
 servo_R12.write(L22_R12_0); // правая передняя нога сустав
 servo_R11.write(C1_0); // правая передняя нога корпус
  
 servo_ZaD_R21.write(C1_0); // правая задняя нога корпус
 servo_ZaD_R22.write(L12_R22_0); // правая задняя нога сустав

delay(del_0);

////--///--//--///

 pinMode(pinSensorRight,   INPUT);
  pinMode(pinSensorLeft,    INPUT);
  pinMode(pinSensorCenter,  INPUT);

Serial.begin (115200);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
  
}
void notgo(){
 servo_L12.write(L12_R22_0); // левая передняя нога сустав
 servo_L11.write(C1_0); // левая передняя нога корпус
  
 servo_ZaD_L21.write(C1_0); // левая задняя нога корпус
 servo_ZaD_L22.write(L22_R12_0 + 20); //левая задняя нога сустав
  
 servo_R12.write(L22_R12_0); // правая передняя нога сустав
 servo_R11.write(C1_0); // правая передняя нога корпус
  
 servo_ZaD_R21.write(C1_0); // правая задняя нога корпус
 servo_ZaD_R22.write(L12_R22_0); // правая задняя нога сустав
}
void sonar (){
digitalWrite(trig,LOW);
delayMicroseconds(10);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
duration=pulseIn(echo,HIGH);
CM=(duration/2)/29.1;
Serial.print("Расстояние до объекта");
Serial.print(CM);
Serial.println("cm");
delay(350);  
}
void go () {
  
  servo_R12.write(L22_R12_0+30);
  servo_ZaD_L21.write(C1_0-40);
  servo_ZaD_L22.write(L22_R12_0+10);
  servo_R11.write(C1_0+20);

  delay(del_0);
  
  servo_R12.write(L22_R12_0);
  servo_ZaD_L22.write(L22_R12_0);
  
  delay(del_0);

  servo_L12.write(L12_R22_0-30);
  servo_ZaD_R21.write(C1_0+40);
  servo_ZaD_R22.write(L12_R22_0);
  servo_L11.write(C1_0-20);

  delay(del_0);
  
  servo_L12.write(L12_R22_0);
  servo_ZaD_R22.write(L12_R22_0);

  delay(del_0);

  servo_R11.write(C1_0-20);
  servo_ZaD_L21.write(C1_0);
  servo_L11.write(C1_0+20);
  servo_ZaD_R21.write(C1_0);

  delay(del_0);
  
}
void left () {
 servo_L12.write(L12_R22_0); // левая передняя нога сустав
 servo_L11.write(C1_0); // левая передняя нога корпус
  
 servo_ZaD_L21.write(C1_0); // левая задняя нога корпус
 servo_ZaD_L22.write(L22_R12_0 + 20); //левая задняя нога сустав
  
 servo_R12.write(L22_R12_0); // правая передняя нога сустав
 servo_R11.write(C1_0); // правая передняя нога корпус
  
 servo_ZaD_R21.write(C1_0); // правая задняя нога корпус
 servo_ZaD_R22.write(L12_R22_0); // правая задняя нога сустав
 delay(del_0);








}
void loop() {
  // put your main code here, to run repeatedly:
//if (CM > 40 )go();
//if (CM < 40 )notgo();
//int sensor1=analogRead(pinSensorCenter);
//if (sensor1>line) go();
 
  int ls_l=analogRead(pinSensorLeft),ls_s=analogRead(pinSensorCenter), ls_r=analogRead(pinSensorRight);
Serial.print ( " лево " );
  Serial.print ( ls_l );//SS2
  Serial.print ( " центр " );
  Serial.print ( ls_s );//SS3
  Serial.print ( " право " );
  Serial.println ( ls_r );//SS4
  delay(100);

 //if(ls_s>231)go();
//if(pinSensorLeft>211)notgo();
//if(pinSensorRight>211)notgo();
//if(ls_s<231)notgo();
 //  go();
   
//notgo();
 // delay(3000);
  servo_L11.write(C1_0+70); // левая передняя нога корпус
  servo_L12.write(L12_R22_0+50);
 servo_ZaD_L21.write(C1_0+70); // левая задняя нога кор
  servo_ZaD_L22.write(L22_R12_0 + 70);
 servo_R11.write(C1_0+70); // правая передняя нога корпус
  servo_R12.write(L22_R12_0+50); // правая передняя нога сустав
 servo_ZaD_R21.write(C1_0+70); // правая задняя нога корпус
 servo_ZaD_R22.write(L12_R22_0+50); // правая задняя нога сустав
 delay(del_0);
 servo_L11.write(C1_0-70); // левая передняя нога корпус
 servo_L12.write(L12_R22_0);
 servo_ZaD_L21.write(C1_0-70); // левая задняя нога корпус
 servo_ZaD_L22.write(L22_R12_0 + 20);
 servo_R11.write(C1_0-70); // правая передняя нога корпус
 servo_R12.write(L22_R12_0);
 servo_ZaD_R21.write(C1_0-70); // правая задняя нога корпус
  servo_ZaD_R22.write(L12_R22_0);
 delay(del_0);
}
   
