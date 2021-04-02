const int pinFlame = 0; // Аналоговый пин для подключения датчика огня
const int pinBuzzer = 9;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600); // Инициализировать последовательный порт
 
    // Инициализировать порты ввода-вывода:
    pinMode(pinBuzzer, OUTPUT);
    pinMode(pinFlame, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
const int flameVal = analogRead(pinFlame); // Считать показания с датчика огня
 
    Serial.println(flameVal); // Вывести проказания в последовательный порт
 
    if (flameVal >= 600) // Пусть 600 - это критический уровень показаний с датчика огня
    {
        // Подать сигнал при достижении критического уровня
        digitalWrite(pinBuzzer, HIGH);
    }
    else
    {
        // Отключить сигнал при падении уровня ниже критического
        digitalWrite(pinBuzzer, LOW);
    }
 
    delay(500);
}
