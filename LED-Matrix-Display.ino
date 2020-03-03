
#include "Arduino.h"
#include "LedControl.h"
// #include "matrixDisplay.h"
#include "font.h"

#define thin


#define dispAmount 30 // amount of displays
#define switchPin 2



LedControl lc=LedControl(11,13,8, dispAmount - 1);  // Pins: DIN,CLK,CS, # of Display connected

#define delayTime 600  // Delay between Frames




void setup()
{
  for(int x = 0; x < dispAmount; x++){
    
    lc.shutdown(x,false);  // Wake up displays
    lc.setIntensity(x,15);  // Set intensity levels
    lc.clearDisplay(x);  // Clear Displays
    
    
  }
  Serial.begin(9600);
  pinMode(switchPin, INPUT_PULLUP);
}


// different swipe animations vv

void white(){
  for (int x = 0; x < 8; x++){
    for (int z = 0; z < dispAmount; z++){
      lc.setRow(z,x,255);
    }
  }
  delay(delayTime * 8);
}


// ? Improved Alphabet()

void fontCycle(){
  for (int i = 0; i < fontLength; i++){
    for (int x = 0; x < 8; x++){
      for (int z = 0; z < dispAmount; z++){
        lc.setRow(z,x,font[i][x]);
      }
    }
    delay(delayTime * 4);
  }
}


// Cycle through functions VV

void loop()
{
  if (digitalRead(switchPin) == HIGH){
    fontCycle();
    white();
  }
  else{
    
    char inData = ' ';
    while (Serial.available() > 0) {
      inData = char(Serial.read());
      delay(5);
      Serial.println(inData);

      for (int y = 0; y < fontLength; y++){
        if (inData == fontContent[y]){
          for (int x = 0; x < 8; x++){
            for (int z = 0; z < dispAmount; z++){
              lc.setRow(z,x,font[y][x]);
            }
          }
          delay(delayTime);
        }
      }
    }
  }
}