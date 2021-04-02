int water; // присваиваем имя для значений с аналогового входа A0
int water1; // присваиваем имя для значений с аналогового входа A0

const int c = 261;
const int d = 343;
const int buzzerPin = 7;

void setup() {
   pinMode(A0, INPUT);  // к входу A0 подключим датчик (англ. «intput»)
   pinMode(A1, INPUT);  // к входу A0 подключим датчик (англ. «intput»)
     pinMode(buzzerPin, OUTPUT);
   Serial.begin(9600);  // подключаем монитор порта
}
void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);

 
  //Increment counter

}

void loop() {
   water = analogRead(A0); // переменная "water" находится в интервале от 0 до 1023
   water1 = analogRead(A1); // переменная "water" находится в интервале от 0 до 1023
   Serial.println(water); // выводим значение датчика на монитор
   Serial.println(water1);
   delay(1000);           // задержка в одну секунду

 if (water >0)  beep(c, 250);  
 if (water1>0)  beep(d, 500);
}
