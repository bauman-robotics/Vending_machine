// библиотека для работы с модулями по интерфейсу SPI
#include <SPI.h>
// библиотека для работы со сборкой силовых ключей
#include <AmperkaFET.h>
// пин выбора сборки устройств на шине SPI
#define PIN_CS  8


// создаём объект mosfet для работы со сборкой силовых ключей
// передаём номер пина выбора устройств на шине SPI
// и количество устройств подключённых в цепочке
FET mosfet(PIN_CS, 2);
String str;

void setup() {
  // начало работы с силовыми ключами
  mosfet.begin();
  Serial.begin(115200); 
  Serial.setTimeout(10);
  delay(500);
  mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
  mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
  //mosfet.digitalWrite(0, 7, LOW); //LED1 - ON
  //mosfet.digitalWrite(1, 0, HIGH);
}

//String ard2 = Serial1.readString(); 
void loop() {

  if (Serial.available() > 0) {
    str = Serial.readString();
    //Serial.print(str);
    if(str == "1"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 7, LOW);
      mosfet.digitalWrite(1, 0, HIGH);
    }
    else if (str == "2"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 6, LOW);
      mosfet.digitalWrite(1, 0, HIGH);      
    }
    else if (str == "3"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 5, LOW);
      mosfet.digitalWrite(1, 0, HIGH);      
    }    
    else if (str == "4"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 4, LOW);
      mosfet.digitalWrite(1, 0, HIGH);      
    }
    else if (str == "5"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 3, LOW);
      mosfet.digitalWrite(1, 0, HIGH);      
    }  
    else if (str == "6"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 2, LOW);
      mosfet.digitalWrite(1, 0, HIGH);      
    }
    else if (str == "7"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 1, LOW);
      mosfet.digitalWrite(1, 0, HIGH);      
    }    
    else if (str == "8"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 0, LOW);
      mosfet.digitalWrite(1, 0, HIGH);
    }
    //-------------
    else if(str == "9"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 7, LOW);
      mosfet.digitalWrite(1, 1, HIGH);
    }
    else if (str == "10"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 6, LOW);
      mosfet.digitalWrite(1, 1, HIGH);      
    }
    else if (str == "11"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 5, LOW);
      mosfet.digitalWrite(1, 1, HIGH);      
    }    
    else if (str == "12"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 4, LOW);
      mosfet.digitalWrite(1, 1, HIGH);      
    }
    else if (str == "13"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 3, LOW);
      mosfet.digitalWrite(1, 1, HIGH);      
    }  
    else if (str == "14"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 2, LOW);
      mosfet.digitalWrite(1, 1, HIGH);      
    }
    else if (str == "15"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 1, LOW);
      mosfet.digitalWrite(1, 1, HIGH);      
    }    
    else if (str == "16"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 0, LOW);
      mosfet.digitalWrite(1, 1, HIGH);
    }    
    //-------------
    else if(str == "17"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 7, LOW);
      mosfet.digitalWrite(1, 2, HIGH);
    }
    else if (str == "18"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 6, LOW);
      mosfet.digitalWrite(1, 2, HIGH);      
    }
    else if (str == "19"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 5, LOW);
      mosfet.digitalWrite(1, 2, HIGH);      
    }    
    else if (str == "20"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 4, LOW);
      mosfet.digitalWrite(1, 2, HIGH);      
    }
    else if (str == "21"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 3, LOW);
      mosfet.digitalWrite(1, 2, HIGH);      
    }  
    else if (str == "22"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 2, LOW);
      mosfet.digitalWrite(1, 2, HIGH);      
    }
    else if (str == "23"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 1, LOW);
      mosfet.digitalWrite(1, 2, HIGH);      
    }    
    else if (str == "24"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 0, LOW);
      mosfet.digitalWrite(1, 2, HIGH);
    }  
    //-------------
    else if(str == "25"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 7, LOW);
      mosfet.digitalWrite(1, 3, HIGH);
    }
    else if (str == "26"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 6, LOW);
      mosfet.digitalWrite(1, 3, HIGH);      
    }
    else if (str == "27"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 5, LOW);
      mosfet.digitalWrite(1, 3, HIGH);      
    }    
    else if (str == "28"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 4, LOW);
      mosfet.digitalWrite(1, 3, HIGH);      
    }
    else if (str == "29"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 3, LOW);
      mosfet.digitalWrite(1, 3, HIGH);      
    }  
    else if (str == "30"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 2, LOW);
      mosfet.digitalWrite(1, 3, HIGH);      
    }
    else if (str == "31"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 1, LOW);
      mosfet.digitalWrite(1, 3, HIGH);      
    }    
    else if (str == "32"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 0, LOW);
      mosfet.digitalWrite(1, 3, HIGH);
    }  
    //-------------
    else if(str == "33"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 7, LOW);
      mosfet.digitalWrite(1, 4, HIGH);
    }
    else if (str == "34"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 6, LOW);
      mosfet.digitalWrite(1, 4, HIGH);      
    }
    else if (str == "35"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 5, LOW);
      mosfet.digitalWrite(1, 4, HIGH);      
    }    
    else if (str == "36"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 4, LOW);
      mosfet.digitalWrite(1, 4, HIGH);      
    }
    else if (str == "37"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 3, LOW);
      mosfet.digitalWrite(1, 4, HIGH);      
    }  
    else if (str == "38"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 2, LOW);
      mosfet.digitalWrite(1, 4, HIGH);      
    }
    else if (str == "39"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 1, LOW);
      mosfet.digitalWrite(1, 4, HIGH);      
    }    
    else if (str == "40"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 0, LOW);
      mosfet.digitalWrite(1, 4, HIGH);
    }  
    //-------------
    else if(str == "41"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 7, LOW);
      mosfet.digitalWrite(1, 5, HIGH);
    }
    else if (str == "42"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 6, LOW);
      mosfet.digitalWrite(1, 5, HIGH);      
    }
    else if (str == "43"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 5, LOW);
      mosfet.digitalWrite(1, 5, HIGH);      
    }    
    else if (str == "44"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 4, LOW);
      mosfet.digitalWrite(1, 5, HIGH);      
    }
    else if (str == "45"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 3, LOW);
      mosfet.digitalWrite(1, 5, HIGH);      
    }  
    else if (str == "46"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 2, LOW);
      mosfet.digitalWrite(1, 5, HIGH);      
    }
    else if (str == "47"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 1, LOW);
      mosfet.digitalWrite(1, 5, HIGH);      
    }    
    else if (str == "48"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 0, LOW);
      mosfet.digitalWrite(1, 5, HIGH);
    }     
    //-------------
    else if(str == "49"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 7, LOW);
      mosfet.digitalWrite(1, 6, HIGH);
    }
    else if (str == "50"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 6, LOW);
      mosfet.digitalWrite(1, 6, HIGH);      
    }
    else if (str == "51"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 5, LOW);
      mosfet.digitalWrite(1, 6, HIGH);      
    }    
    else if (str == "52"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 4, LOW);
      mosfet.digitalWrite(1, 6, HIGH);      
    }
    else if (str == "53"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 3, LOW);
      mosfet.digitalWrite(1, 6, HIGH);      
    }  
    else if (str == "54"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 2, LOW);
      mosfet.digitalWrite(1, 6, HIGH);      
    }
    else if (str == "55"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 1, LOW);
      mosfet.digitalWrite(1, 6, HIGH);      
    }    
    else if (str == "56"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 0, LOW);
      mosfet.digitalWrite(1, 6, HIGH);
    }      
    //-------------
    else if(str == "57"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 7, LOW);
      mosfet.digitalWrite(1, 7, HIGH);
    }
    else if (str == "58"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 6, LOW);
      mosfet.digitalWrite(1, 7, HIGH);      
    }
    else if (str == "59"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 5, LOW);
      mosfet.digitalWrite(1, 7, HIGH);      
    }    
    else if (str == "60"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 4, LOW);
      mosfet.digitalWrite(1, 7, HIGH);      
    }
    else if (str == "61"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 3, LOW);
      mosfet.digitalWrite(1, 7, HIGH);      
    }  
    else if (str == "62"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 2, LOW);
      mosfet.digitalWrite(1, 7, HIGH);      
    }
    else if (str == "63"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 1, LOW);
      mosfet.digitalWrite(1, 7, HIGH);      
    }    
    else if (str == "64"){
      mosfet.digitalWrite(0, ALL, HIGH); // catodes all passive
      mosfet.digitalWrite(1, ALL, LOW); // anodes all passive
      mosfet.digitalWrite(0, 0, LOW);
      mosfet.digitalWrite(1, 7, HIGH);
    }                   
  }
 
 
}
