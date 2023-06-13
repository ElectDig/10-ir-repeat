

![Austral Ingenieria](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQooGo7vQn4t9-6Bt46qZF-UY4_QFpYOeh7kVWzwpr_lbLr5wka)


#   Project 10-ir-repeat

  Electronica Digital - Austral 2023 - EAM

##  Tests controlling on off of an LG AC

  Using ESP32 development board

  Test made with LG AC model Dual Cool Inverter - 3025F 3517W S4-W12JA3AA
  Codes read from remote control LG model AKB75215403


### Hardware

  1 KY-022 Infrared receiver module  
  1 LED IR emitter 940 nm
  1 NPN transistor 2N3904
  1 100 ohm resistor
  1 47 ohm resistor
  Jumper wires  

### Software

  Uses library _IRremoteESP8266_

###  Connections

  Connect KY-022 GND to GND  
  Connect KY-022 VCC to 3.3 V  

  Connect GPIO "IR_PIN" to a side of 100 ohm resistor
  Connect other side iof 100 ohm resistor to transistor base
  Connect transistor emmiter to GND
  Connect transistor collector to a side of 47 ohm resistor
  Connect other side of 47 ohm resistor to IR LED cathode
  Connect IR LED anode to +5 Volt

  Connect a side of takt switch to GND
  Connect other side of takt switch to GPIO "PUSH_PIN"

  KY_022 output is left unconnected and it is used to monitor if IR LED is sending code, using the led that is on board on KY_022


###  Code comments

  In folder _src_ there is a file called _button.h_ that has a class named _Button_ used for debounde and decode a closure of takt switch.  
  The code, that resides in folder _src_ has a main file, named _main.cpp_. 

  The code in _main.cpp_ simply set the 'PUSH_PIN' GPIO for testing closure using _button.h_ call _begin_, set "LED_PIN" as output and set off led and, finally, prepare _irSender_ class for working with IR LED

  The main _loop_ is executed each 5 milliseconds; if detect a takt switch closure, then toggles "LED_PIN" and sends to air conditioner an _OFF_ or an _ON_ command, based on state of visual LED


