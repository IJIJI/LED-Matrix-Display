
#include "Arduino.h"
#include "LedControl.h"

#define thin


#define dispAmount 1 // amount of displays
#define switchPin 2

LedControl lc=LedControl(7,5,6, dispAmount - 1);  // Pins: DIN,CLK,CS, # of Display connected

int delayTime=200;  // Delay between Frames


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

// Font arrays vv

byte a[8]={0x30, 0x78, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0x00};    
byte b[8]={0xfc, 0x66, 0x66, 0x7c, 0x66, 0x66, 0xfc, 0x00};  
byte c[8]={0x3c, 0x66, 0xc0, 0xc0, 0xc0, 0x66, 0x3c, 0x00};  
byte d[8]={0xf8, 0x6c, 0x66, 0x66, 0x66, 0x6c, 0xf8, 0x00};  
byte e[8]={0xfe, 0x62, 0x68, 0x78, 0x68, 0x62, 0xfe, 0x00};
byte f[8]={0xfe, 0x62, 0x68, 0x78, 0x68, 0x60, 0xf0, 0x00};
byte g[8]={0x3c, 0x66, 0xc0, 0xc0, 0xce, 0x66, 0x3e, 0x00};


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
}

// cycle the alphabet
// TODO Optimise olphabet storage and displaying

void alphabet(){
  for (int x = 0; x < 8; x++){
    for (int z = 0; z < dispAmount; z++){
      lc.setRow(z,x,a[x]);
    }
  }
  delay(delayTime * 8);
  for (int x = 0; x < 8; x++){
    for (int z = 0; z < dispAmount; z++){
      lc.setRow(z,x,b[x]);
    }
  }
  delay(delayTime * 8);
  for (int x = 0; x < 8; x++){
    for (int z = 0; z < dispAmount; z++){
      lc.setRow(z,x,c[x]);
    }
  }
  delay(delayTime * 8);
  for (int x = 0; x < 8; x++){
    for (int z = 0; z < dispAmount; z++){
      lc.setRow(z,x,d[x]);
    }
  }
  delay(delayTime * 8);
  for (int x = 0; x < 8; x++){
    for (int z = 0; z < dispAmount; z++){
      lc.setRow(z,x,e[x]);
    }
  }
  delay(delayTime * 8);
  for (int x = 0; x < 8; x++){
    for (int z = 0; z < dispAmount; z++){
      lc.setRow(z,x,f[x]);
    }
  }
  delay(delayTime * 8);
  for (int x = 0; x < 8; x++){
    for (int z = 0; z < dispAmount; z++){
      lc.setRow(z,x,g[x]);
    }
  }
  delay(delayTime * 8);
  for (int z = 0; z < dispAmount; z++){
    lc.clearDisplay(z); 
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
    alphabet();
    white();
  }
}