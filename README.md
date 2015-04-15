# hortibuddy_arduino-i2c

### Introduction

Arduino sketch from Horti'Buddy project. This script setup a slave I2C communication and pilot some peripherals like temp probe or motor dimmer. There are 2 steps in operation between Raspberry Pi and Arduino. First, RPi sent a command order with parameters, Arduino compute that and save result into a variable. After a short delay, RPi get the result.

### Horti'Buddy protocol specs 

There are two kind of communication :
* A command to process with parameters : Using onReceive event from Wire lib.
* A value to get : Using onRequest event from Wire lib.

Command fonction take 3 bytes has a parameters :
* First byte is command id.
* Second byte is PIN id.
* Third byte is value to apply, optional.

We need to normalize command id and PIN id

### About Horti'Buddy project
* Project overview : http://blog.gamb.fr/index.php?post/2014/03/10/Horti-Buddy-episode1
* Installing OS on RPi : http://blog.gamb.fr/index.php?post/2014/05/03/Raspberry-PI-%3A-Installation-du-syst%C3%A8me


|                      |                                          |
|:---------------------|:-----------------------------------------|
| **Author:**          | Gilian Gambini (<gamb@gamb.fr>)
| **Copyright:**       | Gamb
| **License:**         | AGPL v3, see the COPYING file.
