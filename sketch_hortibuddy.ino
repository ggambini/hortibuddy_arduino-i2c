// Libs necessaires
#include <Wire.h>
//include <DHT22.h>

//
// Conf
//
  // I2C address
  #define I2C_ADDRESS 0x03


//
// Init
//
  void setup() {
    // En passe en slave sur le bus I2C avec l'adresse I2C_ADDRESS
    Wire.begin(I2C_ADDRESS);
    
    // Fonctions de callback pour l'I2C
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);
  }


//
// Traitement
//
  void loop() {

  
  

  }
