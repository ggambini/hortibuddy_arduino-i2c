# hortibuddy_arduino-i2c

### Introduction

Arduino sketch from Horti'Buddy project. This script setup a slave I2C communication and pilot some peripherals like temp probe or motor dimmer. There are 2 steps in operation between Raspberry Pi and Arduino. First, RPi sent a command order with parameters, Arduino compute that and save result into a variable. After a short delay, RPi get the result.

### Horti'Buddy communication specs 

There are two communication methods :
* Set one parameter : Using onReceive event from Wire lib.
* Execute a command : Using onRequest event from Wire lib.

There are 3 parameters available on Arduino side :
* Parameter commandId with key 0x01.
* Parameter pinId with key 0x02.
* Parameter pinValue with key 0x03.

We need to normalize commandId and pinId on RPi side and Arduino side. 

### About Horti'Buddy project
* Project overview : http://blog.gamb.fr/index.php?post/2014/03/10/Horti-Buddy-episode1
* Installing OS on RPi : http://blog.gamb.fr/index.php?post/2014/05/03/Raspberry-PI-%3A-Installation-du-syst%C3%A8me


|                      |                                          |
|:---------------------|:-----------------------------------------|
| **Author:**          | Gilian Gambini (<gamb@gamb.fr>)
| **Copyright:**       | Gamb
| **License:**         | AGPL v3, see the LICENSE file.
