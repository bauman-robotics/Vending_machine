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
int count1 = 0;
int count2 = 0;
int flag_timeout = 0;

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
    if(str == "1"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 7, ANODES_ACTIVE_STATE);    // anodes high
      while (digitalRead(IR_barrier_signal_pin) != 1 ){   
      }   
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "2"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 6, ANODES_ACTIVE_STATE);    // anodes high   
      while (digitalRead(IR_barrier_signal_pin) != 1 ){   
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "3"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 5, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }    
    else if (str == "4"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 4, ANODES_ACTIVE_STATE);    // anodes high       
      while (digitalRead(IR_barrier_signal_pin) != 1 ){   
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "5"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 3, ANODES_ACTIVE_STATE);    // anodes high   
      while (digitalRead(IR_barrier_signal_pin) != 1 ){   
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }  
    else if (str == "6"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 2, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "7"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 1, ANODES_ACTIVE_STATE);    // anodes high   
      while (digitalRead(IR_barrier_signal_pin) != 1 ){
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }    
    else if (str == "8"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 0, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);    // anodes high
      while (digitalRead(IR_barrier_signal_pin) != 1 ){      
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    //-------------
    else if(str == "9"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 7, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "10"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 6, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "11"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 5, ANODES_ACTIVE_STATE);    // anodes high   
      while (digitalRead(IR_barrier_signal_pin) != 1 ){   
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }    
    else if (str == "12"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 4, ANODES_ACTIVE_STATE);    // anodes high
      while (digitalRead(IR_barrier_signal_pin) != 1 ){      
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "13"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 3, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }  
    else if (str == "14"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 2, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "15"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 1, ANODES_ACTIVE_STATE);    // anodes high  
      while (digitalRead(IR_barrier_signal_pin) != 1 ){    
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }    
    else if (str == "16"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 1, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }    
    //-------------
    else if(str == "17"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 7, ANODES_ACTIVE_STATE);    // anodes high
      while (digitalRead(IR_barrier_signal_pin) != 1 ){      
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "18"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 6, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "19"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 5, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }    
    else if (str == "20"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 4, ANODES_ACTIVE_STATE);    // anodes high
      while (digitalRead(IR_barrier_signal_pin) != 1 ){      
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "21"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 3, ANODES_ACTIVE_STATE);    // anodes high
      while (digitalRead(IR_barrier_signal_pin) != 1 ){      
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }  
    else if (str == "22"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 2, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "23"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 1, ANODES_ACTIVE_STATE);    // anodes high
      while (digitalRead(IR_barrier_signal_pin) != 1 ){      
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }    
    else if (str == "24"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 2, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);    // anodes high
      while (digitalRead(IR_barrier_signal_pin) != 1 ){      
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }  
    //-------------
    else if(str == "25"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 7, ANODES_ACTIVE_STATE);    // anodes high  
      while (digitalRead(IR_barrier_signal_pin) != 1 ){    
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "26"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 6, ANODES_ACTIVE_STATE);    // anodes high
      while (digitalRead(IR_barrier_signal_pin) != 1 ){      
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "27"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 5, ANODES_ACTIVE_STATE);    // anodes high
      while (digitalRead(IR_barrier_signal_pin) != 1 ){      
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }    
    else if (str == "28"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 4, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "29"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 3, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }  
    else if (str == "30"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 2, ANODES_ACTIVE_STATE);    // anodes high    
      while (digitalRead(IR_barrier_signal_pin) != 1 ){  
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }
    else if (str == "31"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 1, ANODES_ACTIVE_STATE);    // anodes high 
      while (digitalRead(IR_barrier_signal_pin) != 1 ){     
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH);
    }    
    else if (str == "32"){
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      digitalWrite(IR_barrier_reset_pin,LOW);
      delay(IR_DELAY_START);
      mosfet.digitalWrite(0, 3, CATODES_PASSIVE_STATE);  // catodes  
      mosfet.digitalWrite(1, 0, ANODES_ACTIVE_STATE);    // anodes high   
      while (digitalRead(IR_barrier_signal_pin) != 1 ){   
      }
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive
      Serial.write(49);  // ok, recieve right message from uart
      delay(IR_DELAY_STOP);
      digitalWrite(IR_barrier_reset_pin,HIGH); 
    } 
    else { 
      mosfet.digitalWrite(0, ALL, CATODES_ACTIVE_STATE); // catodes all passive
      mosfet.digitalWrite(1, ALL, ANODED_PASSIVE_STATE); // anodes all passive 
      Serial.write(48);  // trash come from Uart  // "0"                   
    }
  }
}
