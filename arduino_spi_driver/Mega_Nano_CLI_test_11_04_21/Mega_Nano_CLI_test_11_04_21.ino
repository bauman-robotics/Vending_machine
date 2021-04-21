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

  
int ShelfID = -1;
int MotorID = -1;
int Flag = -1;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  Serial.println("DATA INPUT FORMAT IS:");
  Serial.println("ShelfID;MotorID;Flag");
   // начало работы с силовыми ключами
  mosfet.begin();
// shutdown all FET
  mosfet.digitalWrite(ALL, ALL, LOW);
  pinMode(9,INPUT);
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
   Serial.println("WAIT FOR NANO READY...6s...");
  delay(6000);
  if (digitalRead(9) == 0){
    Serial.println("NANO READY");
  } else Serial.println("NANO ERROR/ RERSET CONTROLLER");
  
   
}
void loop() 
{
  
  
    if (Serial.available() > 0) 
  
    {
      String bufString = Serial.readString();
      byte dividerIndex = bufString.indexOf(';');
      String buf_1 = bufString.substring(0, dividerIndex);
      String buf_2 = bufString.substring(dividerIndex + 1);
      String buf_3 = bufString.substring(dividerIndex + 3);
      ShelfID = buf_1.toInt();
      MotorID = buf_2.toInt();
      Flag = buf_3.toInt();
   
    
        if (MotorID <= 7 && ShelfID <= 7){

          if (Flag == 0){

            
          Serial.println("FLAG = 0");
          Serial.println(ShelfID);
          Serial.println(MotorID);
          Serial.println(Flag);

         
         OneMotor(ShelfID,MotorID);
        
          
            
          }

          if (Flag == 1){
            
          Serial.println("FLAG = 1");
          Serial.println(ShelfID);
          Serial.println(MotorID);
          Serial.println(Flag);
            
          }
          
          
        } else{

           Serial.println("ERROR INPUT DATA!!!");
        }
            
    }
        
   

    
  }

void OneMotor(int Shelf, int Motor) {

         Serial.println("START IR ");
         
         digitalWrite(10,LOW);
         delay(500);
         Serial.println("START MOTORS ");
        while (digitalRead(9) != 1 ){

                    Serial.println(digitalRead(9));
          // activate GND (-) gate for Shelf. Gnd GATEs on N-FET 1
                    mosfet.digitalWrite(0, Shelf, HIGH);
                  // activate Vcc (+) P-FET
                    mosfet.digitalWrite(1, Motor, HIGH);
          
        }

        // shutdown all FET
        mosfet.digitalWrite(ALL, ALL, LOW);
            
        Serial.println("STOP MOTOR ");
        delay(2000);
        digitalWrite(10,HIGH); 
        Serial.println("STOP IR ");
 
  
   
}


  
