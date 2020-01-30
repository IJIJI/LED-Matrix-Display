
#include "Arduino.h"
#include "LedControl.h"
#include "font.h"

#define thin


#define dispAmount 1 // amount of displays
#define switchPin 2



LedControl lc=LedControl(7,5,6, dispAmount - 1);  // Pins: DIN,CLK,CS, # of Display connected

int delayTime=200;  // Delay between Frames

// TODO implement a character define
// #define characters = 7

// different frames for swipe animations vv

byte frames[] =
{
  B10000000,
  B01000000,
  B00100000,
  B00010000,
  B00001000,
  B00000100,
#ifndef thin
  B00000010,
  B00000001,
#endif
  B00000000
};

byte sideFillFrames[]{
  B10000000,
  B11000000,
  B11100000,
  B11110000,
  B11111000,
  B11111100,
#ifndef thin
  B11111110,
  B11111111,
#endif
  B01111111,
  B00111111,
  B00011111,
  B00001111,
  B00000111,
#ifndef thin
  B00000011,
  B00000001,
#endif
  B00000000
};


//  Font arrays mk2

// char font[fontLength] = {'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.!?*#'};



void setup()
{
  for(int x = 0; x < dispAmount; x++){
    
    lc.shutdown(x,false);  // Wake up displays
    lc.setIntensity(x,5);  // Set intensity levels
    lc.clearDisplay(x);  // Clear Displays
    
    
  }
  
  pinMode(switchPin, INPUT_PULLUP);
}


// different swipe animations vv

void ledCycle(){
  for (int x = 0; x < 8; x++){
    for (int y = 0; y < sizeof(frames); y++){
      
      for (int z = 0; z < dispAmount; z++){
        lc.setRow(z,x,frames[y]);
      }
      
      delay(delayTime);
    }
  }
}

void sideFill(){
  for (int y = 0; y < sizeof(sideFillFrames); y++){
    for (int x = 0; x < 8; x++){
      
      for (int z = 0; z < dispAmount; z++){
        lc.setRow(z,x,sideFillFrames[y]);
      }
    }
    delay(delayTime * 2);
  }
  
}

void fill(){
  for (int x = 0; x < 8; x++){
    for (int z = 0; z < dispAmount; z++){
      
      lc.setRow(z,x,255);
    }
    delay(delayTime * 2);
  }
  for (int x = 0; x < 8; x++){
    for (int z = 0; z < dispAmount; z++){
      lc.setRow(z,x,0);
    }
    delay(delayTime * 2);
  }
}
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
  for (int i = 0; i < int(fontLength); i++){
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
    ledCycle();
    fill();
    sideFill();
  }
  else{
    fontCycle();
    white();
  }
}