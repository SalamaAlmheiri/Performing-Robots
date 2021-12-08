// For final: transmitter version 1

const int CEPIN = 9;
const int CSNPIN = 10;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(CEPIN, CSNPIN);  // CE, CSN

// Address where we send the data.
const byte address[6] = "00002";

// Pins for the directional buttons
const int LEFT_BUTTON = 4;
const int RIGHT_BUTTON = 7;
const int UP_BUTTON = 8;
const int DOWN_BUTTON = 2;
const int POT1PIN = A1;
const int POT2PIN = A0;
int pot1, pot2;

void setup() {
  Serial.begin(9600);

  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);
  pinMode(POT1PIN, INPUT_PULLUP); //

  boolean retval = radio.begin();   //Starting the Wireless communication
  Serial.println(retval);
  radio.openWritingPipe(address);  //destination addres
  radio.setPALevel(RF24_PA_MIN);   // min or max
  radio.stopListening();           //This sets the module as transmitter
}

void loop() {
  pot1 = analogRead(POT1PIN); //from knob example
  pot1 = map(pot1, 0, 1023, 0, 180);
  //Serial.println(pot1);
  pot2 = analogRead(POT2PIN); //from knob example
  pot2 = map(pot2, 0, 1023, 190, 370);

  if (pot1) {
    //Serial.print( "pot1 sending data = " );
    //Serial.println(pot1);
    radio.write(&pot1, sizeof(pot1)) ;
  }

  if (pot2) {
    //Serial.print( "pot2 sending data = " );
    //Serial.println(pot2);
    radio.write(&pot2, sizeof(pot2)) ;
  }
  
  int left = !digitalRead(LEFT_BUTTON);
  int right = !digitalRead(RIGHT_BUTTON);
  int down = !digitalRead(DOWN_BUTTON);
  int up = !digitalRead(UP_BUTTON);

  int data =  
    (left << 4) |
    (up << 3) |
    (right << 2) | //receiving info but not working
    (down << 1) ;

  if (data) {
    Serial.print( "sending data = " );
    Serial.println(data, BIN);
    radio.write(&data, sizeof(data)) ;
  }
}
