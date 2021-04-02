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

int lineIntensity = 210; // для сравнения значений приходящих с датчиков 450

int last_job = 0;
int interline = 0;
int val = 0;

int objectNumber = 0;
bool hasObject = false;

#define trigPin 3
#define echoPin 2


//------//

const unsigned long L12_R22_0 = 140; //120
const unsigned long L22_R12_0 = 40; //60
const unsigned long C1_0 = 90;
const unsigned long del_0 = 100;

///----///

void go () {
  
  servo_R12.write(L22_R12_0+40);
  servo_ZaD_L21.write(C1_0-40);
  servo_ZaD_L22.write(L22_R12_0+10);
  servo_R11.write(C1_0+20);

  delay(del_0);
  
  servo_R12.write(L22_R12_0);
  servo_ZaD_L22.write(L22_R12_0);
  
  delay(del_0);

  servo_L12.write(L12_R22_0-40);
  servo_ZaD_R21.write(C1_0+40);
  servo_ZaD_R22.write(L12_R22_0-10);
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
void setup() {

  // put your setup code here, to run once:
  servo_L12.attach(4); // левая передняя нога сустав
  servo_L11.attach(5); // левая передняя нога корпус
  
  servo_ZaD_L21.attach(6); // левая задняя нога корпус
  servo_ZaD_L22.attach(7); //левая задняя нога сустав
  
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

Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
  
}

void loop() {

   go();
}
