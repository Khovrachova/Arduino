#include <DHT.h>      // подключаем библиотеку для датчика
DHT dht(2, DHT11);  // сообщаем на каком порту будет датчик

void setup() {
   dht.begin();                // запускаем датчик DHT11
   Serial.begin(9600);   // подключаем монитор порта
}

void loop() {
   // считываем температуру (t) и влажность (h)
   float h = dht.readHumidity();
   float t = dht.readTemperature();

   // выводим температуру (t) и влажность (h) на монитор порта
   Serial.print("Humidity: ");
   Serial.println(h);
   Serial.print("Temperature: ");
   Serial.println(t);
   delay(10000);
}
