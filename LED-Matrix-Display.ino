
#include "Arduino.h"


#define dispAmount 30 // amount of displays
#define switch1 6
#define switch2 5
#define switch3 4




void setup()
{
  Serial.begin(9600);
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
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

}