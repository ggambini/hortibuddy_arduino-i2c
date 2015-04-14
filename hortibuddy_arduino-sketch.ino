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
// Liste des commandes :
// 0x00 : NoCommand
// 0x01 : Lecture temperature digitale
// 0x02 : Lecture hygro digitale

// Libs necessaires
#include <Wire.h>
//include <DHT22.h>

//
// Conf
//
  // I2C address
  #define I2C_ADDRESS 0x03
  volatile byte command = 0;
  volatile byte result = 0;

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
  // OnReceive
  // Execute une fonction qui stockera le resultat dans result
  void getCommand(int nb_octets) {
    
  }
  
  // OnRequest
  // Envoi le contenu de result, donc de la derniere commande executee
  void sendResult() {
    
  }

//
// Traitement
//
  void loop() {
 
  

  }
