#include <Servo.h>
//Servo myservo;  
Servo myservo1;  

void setup() {
  // put your setup code here, to run once:
//myservo.attach(8);
myservo1.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  //myservo.write(90);
  //delay(2000);
  
//  myservo1.write(0);
//  delay(2000);

  myservo1.write(90);
  delay(200);
  
// myservo1.write(180);
// delay(200);
}
