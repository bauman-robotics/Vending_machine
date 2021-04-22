// библиотека для работы с модулями по интерфейсу SPI
#include <SPI.h>
// библиотека для работы со сборкой силовых ключей
#include <AmperkaFET.h>
// пин выбора сборки устройств на шине SPI
#define PIN_CS  8

// инверсия певого байта.
// difines_Vending_machine
#define CATODES_ACTIVE_STATE LOW
#define CATODES_PASSIVE_STATE HIGH
#define ANODES_ACTIVE_STATE HIGH
#define ANODED_PASSIVE_STATE LOW

#define IR_DELAY_START 500 // IR Berrier reset time before start motors
#define IR_DELAY_STOP 2000 // IR Berrier reset time after stop motors

// создаём объект mosfet для работы со сборкой силовых ключей
// передаём номер пина выбора устройств на шине SPI
// и количество устройств подключённых в цепочке
FET mosfet(PIN_CS, 2);
String str;
int IR_barrier_reset_pin = 10;  // MEGA OUT
int IR_barrier_signal_pin = 9;  // MEGA IN

int ret = 0; 
void processing(int row, int column);

void setup() {
  pinMode(IR_barrier_reset_pin, OUTPUT);
  pinMode(IR_barrier_signal_pin, INPUT_PULLUP);  
  digitalWrite(IR_barrier_reset_pin, HIGH);  // 
  // начало работы с силовыми ключами
  mosfet.begin();
  mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
  mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
  Serial.begin(115200); 
  Serial.setTimeout(10);

  //Serial.println("WAIT FOR NANO READY...6s...");
  delay(6000);
  if (digitalRead(9) == 0){
    //Serial.println("NANO READY");
  } 
  else {
    //Serial.println("NANO ERROR/ RERSET CONTROLLER");
  }
}

void loop() {
	if (Serial.available() > 0) {
		str = Serial.readString();
		if		(str ==  "1") processing(0, 7);
		else if (str ==  "2") processing(0, 6);
		else if (str ==  "3") processing(0, 5);
		else if (str ==  "4") processing(0, 4);
		else if (str ==  "5") processing(0, 3);
		else if (str ==  "6") processing(0, 2);
		else if (str ==  "7") processing(0, 1);
		else if (str ==  "8") processing(0, 0);
		
		else if (str ==  "9") processing(1, 7);
		else if (str == "10") processing(1, 6);
		else if (str == "11") processing(1, 5);
		else if (str == "12") processing(1, 4);
		else if (str == "13") processing(1, 3);
		else if (str == "14") processing(1, 2);
		else if (str == "15") processing(1, 1);
		else if (str == "16") processing(1, 0);
		
		else if (str == "17") processing(2, 7);
		else if (str == "18") processing(2, 6);
		else if (str == "19") processing(2, 5);
		else if (str == "20") processing(2, 4);
		else if (str == "21") processing(2, 3);
		else if (str == "22") processing(2, 2);
		else if (str == "23") processing(2, 1);
		else if (str == "24") processing(2, 0);
		
		else if (str == "25") processing(3, 7);
		else if (str == "26") processing(3, 6);
		else if (str == "27") processing(3, 5);
		else if (str == "28") processing(3, 4);
		else if (str == "29") processing(3, 3);
		else if (str == "30") processing(3, 2);
		else if (str == "31") processing(3, 1);
		else if (str == "32") processing(3, 0);
		
		else { 
		  mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
		  mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive 
		  Serial.write(48);  // trash come from Uart  // "0"                   
		}
	}
}
  
void processing(int row, int column) {
	mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
	mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
	digitalWrite(IR_barrier_reset_pin,LOW);
	delay(IR_DELAY_START);
	mosfet.digitalWrite(0, row, CATODES_PASSIVE_STATE);  // catodes  
	mosfet.digitalWrite(1, column, ANODES_ACTIVE_STATE);    // anodes high
  while (digitalRead(IR_barrier_signal_pin) != 1 ){   
  }
	mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
	mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
  Serial.write(49);  // ok, recieve right message from uart
	delay(IR_DELAY_STOP);
	digitalWrite(IR_barrier_reset_pin,HIGH); 
}
	
