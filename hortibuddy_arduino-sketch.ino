//              Horti'Buddy - Arduino-sketch
// 
// Chaque operation est l'enchainement d'une ecriture suivit d'une lecture
// Donc en terme Arduino, un event onReceive puis un event onRequest
//
// OnReceive va declencher une commande "octet1" sur la PIN "octet2" avec la valeur facultative "octet3"
// puis stocker le resultat dans la variable "result"
//
// OnRequest renvoie simplement le contenu de la variable result et la reinit
//

// Libs necessaires
#include <Wire.h>
//include <DHT22.h>

//
// Conf
//
  // I2C address
  #define I2C_ADDRESS 0x03
  
  // COMMAND ID - 0x00 reserved / 0xFF disabled command
  #define TEMP_DHT22 0x01
  #define HYGRO_DHT22 0x02

  // GLOBAL VAR  
  volatile byte commandId;
  volatile byte pinId;
  volatile byte pinValue;
  volatile byte result;

//
// Init
//
  void setup() {
    // On passe en slave sur le bus I2C avec l'adresse I2C_ADDRESS
    Wire.begin(I2C_ADDRESS);
    
    // Fonctions de callback pour l'I2C
    Wire.onReceive(getCommand);
    Wire.onRequest(sendResult);
  }

//
// Fonctions
// 

  // PROBES
    // Temperature sonde DHT22
    void getTempDht22() {
      result = (byte)(digitalRead(pinId));
    }

  // OnReceive
  // Execute une fonction qui stockera le resultat dans result
  void getCommand(int nbOctets) {
    // On accepte que les commandes de 3 octets
    if (nbOctets == 3) {
      commandId = Wire.read();
      pinId = Wire.read();
      pinValue = Wire.read();
    } else {
      commandId = 0x00;
      pinId = 0x00;
      pinValue = 0x00;
    }
  }
  
  // OnRequest
  // Envoi le contenu de result, donc de la derniere commande executee
  void sendResult() {
    Wire.write(result);
  }

//
// Traitement
//
  void loop() {

    // commandId
    switch(commandId) {
     
     // Temp - Sonde DHT22
     case TEMP_DHT22 :
       getTempDht22();
       break;
  
    }
  }
  

