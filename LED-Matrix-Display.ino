
#include "Arduino.h"

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define dispAmount 30 // amount of displays

#define switch1 6
#define switch2 5
#define switch3 4

#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    8

// #define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW 

// Hardware SPI connection
MD_Parola matrix = MD_Parola(HARDWARE_TYPE, CS_PIN, dispAmount);
// Arbitrary output pins
// MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

String inData;

void setup()
{
  Serial.begin(9600);
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);

  matrix.begin();


  matrix.setTextAlignment(PA_CENTER);
}


// TODO improve to byte instead of int ?

int readSwitches(){
  int mode = 0;
  if (digitalRead(switch1) == LOW)
  {
    mode += 1;
  }
  if (digitalRead(switch2) == LOW)
  {
    mode += 2;
  }
  if (digitalRead(switch3) == LOW){
    mode += 4;
  }
  
  
}




// Cycle through functions VV

void loop()
{

  if (Serial.available()){
    inData = "";
    while (Serial.available() > 0) {
      inData += char(Serial.read());
      delay(5);
    
    }
    Serial.println();
    Serial.println(inData);

    // matrix.displayText(inData, PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
    matrix.print(inData);
  }
}