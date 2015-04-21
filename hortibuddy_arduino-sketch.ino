//              Horti'Buddy - Arduino-sketch
// 
// Le RPi communique avec l'Arduino avec deux events : OnReceive et OnRequest. 
// Avec le premier, on définit un parametre. 
// Le second execute une operation en fonction des parametres.
//
// GetParameter recoit deux octets : une cle et une valeur.
// Stock la valeur dans le parametre corespondant a la cle
//
// ExecCommand lance une fonction correspondante a commandId avec comme 
// parametre pinId et pinValue. Le resultat de la fonction est ensuite ecrit
// sur le bus I2C
// 

// Libs necessaires
#include <Wire.h>
#include <DHT.h>

//
// Conf
//
  // I2C address
  #define I2C_ADDRESS 0x03

  // OPERATION REG  
  byte commandId;
  int pinId;
  byte pinValue;
  byte paramId;
  byte paramData;
  int result;
  
  //#define DHTPIN 2
  //#define DHTTYPE DHT22

  
//
// Init
//
  void setup() {
    // On passe en slave sur le bus I2C avec l'adresse I2C_ADDRESS
    Wire.begin(I2C_ADDRESS);
    
    // Fonctions de callback pour l'I2C
    Wire.onReceive(getParameter);
    Wire.onRequest(execCommand);
    
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
  }

//
// Fonctions
// 

  // PROBES
    // Temperature sonde DHT22
    void getTempDht22() {
      // On crée l'objet dht avec pinId et dht22 comme type
      //DHT dht(pinId, DHT22);
      DHT dht(pinId, DHT22);
      // Open communication
      dht.begin();
      // On lit la temperature en celsius
      float temp = dht.readTemperature();
      result = (int) temp;
      //dht.end();
    }
    
    void getLightModule() {
      pinMode(pinId, INPUT);
      result = digitalRead(pinId);
    }
    
  // TEST
    // Test function
    void getPinId() {
      result = pinId;  
    }
    void getPinValue() {
      result = pinValue;
    }

//
// Core
//

  // GetParameter - OnReceive
  // Stock octet2 dans var d'index octet1
  void getParameter(int nbOctets) {

    // Lecture - Octet1=Id, Octet2=data
    paramId = Wire.read();
    paramData = Wire.read(); 
    
    if (paramId == 0x01) {
      // Set commandId
      commandId = paramData; 
    }else if (paramId == 0x02) {
      // Set pinId
      pinId = paramData;
    }else if (paramId == 0x03) {
      // Set pinValue
      pinValue = paramData;
    }
    
  }
  
  // ExecCommand - OnRequest
  // Execute la fonction de nom commandId, renvoi le resultat
  void execCommand() {

    switch (commandId) {
      case 0x01 :
        getPinId();
        break;   
      case 0x02 :
        getPinValue();
        break;
      case 0x03 :
        getTempDht22();
        break;
      case 0x04 :
        //getHumiDht22
        break;
      case 0x05 :
        getLightModule();
        break;
    }

    Wire.write(result);
    result = 0x00;
  }

  // Loop
  void loop() {

    delay(100);

  }
  

