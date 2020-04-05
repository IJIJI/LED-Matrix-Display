
#include "Arduino.h"

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <RF24.h>

String words[] = {"Hello", "World"};


#define switch1 6
#define switch2 5
#define switch3 4

RF24 radio(10, 9); // CE, CSN

const int RFaddress = 0xF5B3FCA46F;


// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 3

#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    8

// Hardware SPI connection
MD_Parola matrix = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
// MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

String inData;

void setup()
{
  Serial.begin(9600);
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);

  
  
  matrix.begin(1);
  matrix.setTextAlignment(PA_CENTER);
  matrix.setSpeed(0);
  matrix.setPause(0);
  matrix.setTextEffect(PA_PRINT, PA_NO_EFFECT);
  matrix.setZoneEffect(0, true, PA_FLIP_LR);

  radio.begin();
  radio.openReadingPipe(0, RFaddress);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  String y = "";
  for (int x = 0; x < MAX_DEVICES; x++){
    y += x+1;
    matrix.print(y);
    delay(300);
  }
  delay(1000);
  

  matrix.print("");
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
  
  // if(digitalRead(switch1) == LOW){
  //   for(int x = 0; x < 2; x++){
  //     matrix.print(words[x]);
  //     delay(4000);
  //   }
  // }
  // else {

  //   if (Serial.available()){
  //     inData = Serial.readStringUntil('\n');
  //     Serial.println("\nPrinting: " + inData);
  //     matrix.print(inData.substring(0,inData.length() - 1) );
  //   }
  // }

  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    matrix.print(text);
  }

}