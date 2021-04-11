// библиотека для работы с модулями по интерфейсу SPI
#include <SPI.h>
// библиотека для работы со сборкой силовых ключей
#include <AmperkaFET.h>
// пин выбора сборки устройств на шине SPI
#define PIN_CS  8

// difines_for_led_dots
//#define CATODES_ACTIVE_STATE HIGH
//#define CATODES_PASSIVE_STATE LOW
//#define ANODES_ACTIVE_STATE HIGH
//#define ANODED_PASSIVE_STATE LOW

// инверсия певого байта.
// difines_Vending_machine
#define CATODES_ACTIVE_STATE LOW
#define CATODES_PASSIVE_STATE HIGH
#define ANODES_ACTIVE_STATE HIGH
#define ANODED_PASSIVE_STATE LOW



// создаём объект mosfet для работы со сборкой силовых ключей
// передаём номер пина выбора устройств на шине SPI
// и количество устройств подключённых в цепочке
FET mosfet(PIN_CS, 2);
String str;
int IR_barrier_reset_pin = 15;  //A1
int IR_barrier_signal_pin = 14; //A0
int IR_LED_ON = 0;  // active_state
int IR_LED_OFF = 1;  // 
int IR_ACTIVE_STATE = 0; 
int IR_PASSIVE_STATE = 1; 
int IR_LED_ON_LATCH = 0;
int IR_LED_ON_LATCH_START = 0;
int IR_LED_ON_LATCH_START_ONCE_EVENT = 0;
int IR_LED_ON_LATCH_STOP = 0;
long IR_LED_ON_TIME_COUNTER = 0;
int ret = 0; 

void setup() {
  pinMode(IR_barrier_reset_pin, OUTPUT);
  pinMode(IR_barrier_signal_pin, INPUT_PULLUP);  
  digitalWrite(IR_barrier_reset_pin, IR_LED_OFF);  // 
  // начало работы с силовыми ключами
  mosfet.begin();
  mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
  mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
  Serial.begin(115200); 
  Serial.setTimeout(10);
  //mosfet.digitalWrite(0, 7, LOW); //LED1 - ON
  //mosfet.digitalWrite(1, 0, HIGH);
}

//String ard2 = Serial1.readString(); 
void loop() {
  //  
  if ((digitalRead(IR_barrier_signal_pin) == IR_ACTIVE_STATE) && (IR_LED_ON_LATCH_START == 0)) {
    IR_LED_ON_LATCH_START = 1; 
    IR_LED_ON_LATCH_START_ONCE_EVENT = 1;   
    mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
    mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
  }  
  if ((IR_LED_ON_LATCH_START) && (IR_LED_ON_LATCH_STOP == 0)) {
    digitalWrite(IR_barrier_reset_pin, IR_LED_ON);
  } 
  else if (IR_LED_ON_LATCH_STOP) {
    digitalWrite(IR_barrier_reset_pin, IR_LED_OFF); 
    if (digitalRead(IR_barrier_signal_pin) == IR_PASSIVE_STATE) {
       IR_LED_ON_LATCH_START = 0;
       IR_LED_ON_LATCH_STOP = 0;
    }
  }
  if (IR_LED_ON_LATCH_START) {
    IR_LED_ON_TIME_COUNTER ++;
  } else IR_LED_ON_TIME_COUNTER = 0;
  if (IR_LED_ON_TIME_COUNTER > 25000) {
    IR_LED_ON_TIME_COUNTER = 0;
    IR_LED_ON_LATCH_STOP = 1;
    digitalWrite(IR_barrier_reset_pin, IR_LED_OFF);
  }
  if (IR_LED_ON_LATCH_START_ONCE_EVENT) {
      IR_LED_ON_LATCH_START_ONCE_EVENT = 0;
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      //if (ret == 1) {
        Serial.write(49); // отправляем байт со значением 49 "1"
      //  ret = 0;
      //}
  }
  if (Serial.available() > 0) {
    str = Serial.readString();
    //Serial.print(str);
    if(str == "1"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 7, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }
    else if (str == "2"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 6, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "3"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 5, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "4"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 4, CATODES_PASSIVE_STATE);  // catodes   
      mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "5"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }  
    else if (str == "6"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "7"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "8"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }
    //-------------
    else if(str == "9"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 7, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 1, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }
    else if (str == "10"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 6, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 1, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "11"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 5, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 1, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "12"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 4, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 1, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "13"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 1, ANODES_ACTIVE_STATE);    // anodes high       
      ret = 1;
    }  
    else if (str == "14"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 1, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "15"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 1, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "16"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 1, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }    
    //-------------
    else if(str == "17"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 7, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 2, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }
    else if (str == "18"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 6, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 2, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "19"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 5, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 2, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "20"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 4, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 2, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "21"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 2, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }  
    else if (str == "22"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 2, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "23"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes
      mosfet.digitalWrite(1, 2, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "24"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 2, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }  
    //-------------
    else if(str == "25"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 7, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 3, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }
    else if (str == "26"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 6, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 3, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "27"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 5, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 3, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "28"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 4, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 3, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "29"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 3, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }  
    else if (str == "30"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 3, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "31"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 3, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "32"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 3, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }  
    //-------------
    else if(str == "33"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 7, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 4, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }
    else if (str == "34"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 6, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 4, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "35"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 5, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 4, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "36"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 4, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 4, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "37"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 4, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }  
    else if (str == "38"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 4, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "39"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 4, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "40"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 4, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }  
    //-------------
    else if(str == "41"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 7, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 5, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }
    else if (str == "42"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 6, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 5, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "43"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 5, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 5, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "44"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 4, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 5, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "45"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 5, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }  
    else if (str == "46"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);   // catodes  
      mosfet.digitalWrite(1, 5, ANODES_ACTIVE_STATE); // anodes high      
      ret = 1;
    }
    else if (str == "47"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 5, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "48"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 5, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }     
    //-------------
    else if(str == "49"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 7, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 6, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }
    else if (str == "50"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 6, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 6, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "51"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 5, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 6, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "52"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 4, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 6, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "53"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 6, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }  
    else if (str == "54"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 6, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "55"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 6, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "56"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 6, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }      
    //-------------
    else if(str == "57"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 7, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 7, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    }
    else if (str == "58"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 6, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 7, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "59"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 5, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 7, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }    
    else if (str == "60"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 4, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 7, ANODES_ACTIVE_STATE);    // anodes high      
      ret = 1;
    }
    else if (str == "61"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 7, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;      
    }  
    else if (str == "62"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 7, ANODES_ACTIVE_STATE);    // anodes high    
      ret = 1;  
    }
    else if (str == "63"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 7, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;      
    }    
    else if (str == "64"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 7, ANODES_ACTIVE_STATE);    // anodes high
      ret = 1;
    } else { 
      ret = 2;                        
    }
    if (ret == 1) {    // for test
      Serial.write(49);  // ok, recieve right message from uart
      ret = 0;
    } else if (ret == 2)  { // for test
        Serial.write(48);  // trash come from Uart
        ret = 0;
    }
  }
 
 
}
