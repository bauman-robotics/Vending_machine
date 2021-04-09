// библиотека для работы с модулями по интерфейсу SPI
#include <SPI.h>
// библиотека для работы со сборкой силовых ключей
#include <AmperkaFET.h>
// пин выбора сборки устройств на шине SPI
#define PIN_CS  8
#define CATODES_ACTIVE_STATE HIGH
#define CATODES_PASSIVE_STATE LOW
#define ANODES_ACTIVE_STATE HIGH
#define ANODED_PASSIVE_STATE LOW

// создаём объект mosfet для работы со сборкой силовых ключей
// передаём номер пина выбора устройств на шине SPI
// и количество устройств подключённых в цепочке
FET mosfet(PIN_CS, 2);


void setup() {
  // начало работы с силовыми ключами
  mosfet.begin();
}

void loop() {
  // включаем второй ключ на нулевом модуле
  //mosfet.digitalWrite(0, 3, HIGH);
  
  //mosfet.digitalWrite(0, ALL, LOW); // catodes all active
  //mosfet.digitalWrite(1, ALL, HIGH); // anodes all active

  mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
  mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
  mosfet.digitalWrite(0, 7, CATODES_PASSIVE_STATE);
  mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);
  delay(100);
  mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
  mosfet.digitalWrite(1, ALL, LOW); // anodes all passive  
  mosfet.digitalWrite(0, 6, CATODES_PASSIVE_STATE);
  mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);
  delay(100);
  mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
  mosfet.digitalWrite(1, ALL, LOW); // anodes all passive  
  mosfet.digitalWrite(0, 5, CATODES_PASSIVE_STATE);
  mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);
  delay(100);
  mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
  mosfet.digitalWrite(1, ALL, LOW); // anodes all passive  
  mosfet.digitalWrite(0, 4, CATODES_PASSIVE_STATE);
  mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);
  delay(100);
  mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
  mosfet.digitalWrite(1, ALL, LOW); // anodes all passive  
  mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);
  mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);
  delay(100);
  mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
  mosfet.digitalWrite(1, ALL, LOW); // anodes all passive  
  mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);
  mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);
  delay(100);
  mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
  mosfet.digitalWrite(1, ALL, LOW); // anodes all passive  
  mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);
  mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);
  delay(100);
  mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
  mosfet.digitalWrite(1, ALL, LOW); // anodes all passive  
  mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);
  mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);
  delay(100); 
  
  // включаем все ключи на втором модуле
  //mosfet.digitalWrite(1, ALL, HIGH);
  // ждём пол секунды
  //delay(500);
  // выключаем все ключи на всех модулях
  //mosfet.digitalWrite(ALL, ALL, LOW);
  // ждём пол секунды
 // delay(500);
}
