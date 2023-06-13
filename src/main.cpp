/*
 *  Project 10-ir-repeat
 *      file: main.cpp
 *
 *  Electronica Digital - Austral - 2023 - EAM
 *
 *  Test made with LG AC model Dual Cool Inverter - 3025F 3517W S4-W12JA3AA
 *  Codes read from remote control LG model AKB75215403
 */


#include <Arduino.h>

#include <IRremoteESP8266.h>
#include <IRsend.h>

#include "button.h"

Button btn1;
IRsend irSender(IR_PIN);;

/*
 *  Define LG air conditioner IR codes
 *  Only off (same for all conditions)
 *      and on, set fo following conditions 
 *      when applicable
 *      Set temperature = 24 C
 *      Air speed : F5 o maximo
 *
 *      Codes depends on mode
 */

unsigned long LGoff =       0x88C0051;
unsigned long LGonCold =    0x880394D;
unsigned long LGonAuto =    0x8803940;
unsigned long LGonDeshum =  0x880194E;
unsigned long LGonWarm =    0x8804941;
unsigned long LGonFan =     0x8802349;

void
setup(void)
{
    btn1.begin(PUSH_PIN);
    pinMode(LED_PIN,OUTPUT);
    digitalWrite(LED_PIN,LOW);
    // Initialize IR LED pin
    irSender.begin();
}

void
loop(void)
{
    int state;

    if (btn1.debounce())
    {
        digitalWrite(LED_PIN,!(state=digitalRead(LED_PIN)));
        irSender.sendLG(state?LGoff:LGonWarm);
    }
    delay(5);
}
