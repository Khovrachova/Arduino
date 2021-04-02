int green1=2;
int yellow1 = 3;
int red1=4;
int blue1=5;
int green2=6;
int yellow2 = 7;
int red2=8;
int blue2=9;
int green3=10;
int yellow3 = 11;
int red3=12;
int blue3=13;

int t = 100;

void setup() {
  // put your setup code here, to run once:
pinMode(green1, OUTPUT);
pinMode(yellow1, OUTPUT);
pinMode(red1, OUTPUT);
pinMode(blue1, OUTPUT);
pinMode(green2, OUTPUT);
pinMode(yellow2, OUTPUT);
pinMode(red2, OUTPUT);
pinMode(blue2, OUTPUT);
pinMode(green3, OUTPUT);
pinMode(yellow3, OUTPUT);
pinMode(red3, OUTPUT);
pinMode(blue3, OUTPUT);
}

void loop() {
digitalWrite(green1, HIGH);
digitalWrite(yellow1, HIGH);
digitalWrite(red1, HIGH);
digitalWrite(blue1, HIGH);
digitalWrite(green2, HIGH);
digitalWrite(yellow2, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(blue2, HIGH);
digitalWrite(green3, HIGH);
digitalWrite(yellow3, HIGH);
digitalWrite(red3, HIGH);
digitalWrite(blue3, HIGH);

// 2 этап включить все, выключить все
delay(t);

digitalWrite(green1, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(red1, LOW);
digitalWrite(blue1, LOW);
digitalWrite(green2, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(red2, LOW);
digitalWrite(blue2, LOW);
digitalWrite(green3, LOW);
digitalWrite(yellow3, LOW);
digitalWrite(red3, LOW);
digitalWrite(blue3, LOW);

delay(t);

//3 этап включить и выключить каждый по очереди

digitalWrite(green1, HIGH);
delay(t);
digitalWrite(green1, LOW);
delay(t);

digitalWrite(yellow1, HIGH);
delay(t);
digitalWrite(yellow1, LOW);
delay(t);

digitalWrite(red1, HIGH);
delay(t);
digitalWrite(red1, LOW);
delay(t);

digitalWrite(blue1, HIGH);
delay(t);
digitalWrite(blue1, LOW);
delay(t);

digitalWrite(green2, HIGH);
delay(t);
digitalWrite(green2, LOW);
delay(t);

digitalWrite(yellow2, HIGH);
delay(t);
digitalWrite(yellow2, LOW);
delay(t);

digitalWrite(red2, HIGH);
delay(t);
digitalWrite(red2, LOW);
delay(t);

digitalWrite(blue2, HIGH);
delay(t);
digitalWrite(blue2, LOW);
delay(t);

digitalWrite(green3, HIGH);
delay(t);
digitalWrite(green3, LOW);
delay(t);

digitalWrite(yellow3, HIGH);
delay(t);
digitalWrite(yellow3, LOW);
delay(t);

digitalWrite(red3, HIGH);
delay(t);
digitalWrite(red3, LOW);
delay(t);

digitalWrite(blue3, HIGH);
delay(t);
digitalWrite(blue3, LOW);
delay(t);

//3й этап сначала включить зеленые, затем желтые, потом красные и синие. Через задержку между цветами
digitalWrite(green1, HIGH);
digitalWrite(green2, HIGH);
digitalWrite(green3, HIGH);

delay(t);

digitalWrite(yellow1, HIGH);
digitalWrite(yellow2, HIGH);
digitalWrite(yellow3, HIGH);

delay(t);
digitalWrite(red1, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(red3, HIGH);

delay(t);
digitalWrite(blue1, HIGH);
digitalWrite(blue2, HIGH);
digitalWrite(blue3, HIGH);

delay(t);
//последнее задание: включить все по очереди и выключить в обратном порядке (через задержку!)

digitalWrite(green1, HIGH);
delay(t);
digitalWrite(yellow1, HIGH);
delay(t);
digitalWrite(red1, HIGH);
delay(t);
digitalWrite(blue1, HIGH);
delay(t);
digitalWrite(green2, HIGH);
delay(t);
digitalWrite(yellow2, HIGH);
delay(t);
digitalWrite(red2, HIGH);
delay(t);
digitalWrite(blue2, HIGH);
delay(t);
digitalWrite(green3, HIGH);
delay(t);
digitalWrite(yellow3, HIGH);
delay(t);
digitalWrite(red3, HIGH);
delay(t);
digitalWrite(blue3, HIGH);
delay(t);

digitalWrite(blue3, LOW);
delay(t);
digitalWrite(red3, LOW);
delay(t);
digitalWrite(yellow3, LOW);
delay(t);
digitalWrite(green3, LOW);
delay(t);
digitalWrite(blue2, LOW);
delay(t);
digitalWrite(red2, LOW);
delay(t);
digitalWrite(yellow2, LOW);
delay(t);
digitalWrite(green2, LOW);
delay(t);
digitalWrite(blue1, LOW);
delay(t);
digitalWrite(red1, LOW);
delay(t);
digitalWrite(yellow1, LOW);
delay(t);
digitalWrite(green1, LOW);
delay(t);
}
