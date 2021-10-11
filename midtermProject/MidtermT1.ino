/*
  Salama Almheiri
  Midterm (transmitter)
  Oct 5 2021
  Version 1
*/

const int CEPIN = 9;
const int CSNPIN = 10;

// In summary,
// nRF 24L01 pin    Arduino pin   name
//          1                     GND
//          2                     3.3V
//          3             9       CE
//          4             10      CSN  
//          5             13      SCLK
//          6             11      MOSI/COPI
//          7             12      MISO/CIPO 

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(CEPIN, CSNPIN);                // CE, CSN

// Byte of array representing the address. 
// This is the address where we will send the data. 
// This should be same on the receiving side.
const byte address[6] = "00001"; 

// pushbuttons
const int stopButton = 3; //Tiny Grey button
const int slowButton = 2; //Green button
const int fastButton = 4; //Red button

void setup() {
  Serial.begin(115200);

  boolean retval = radio.begin();   //Starting the Wireless communication
  Serial.println(retval);
  radio.openWritingPipe(address);  //destination addres
  radio.setPALevel(RF24_PA_MIN);   // min or max
  radio.stopListening();           //This sets the module as transmitter
}
void loop() {

int stopB = digitalRead(stopButton) << 2; //case 4
int slow = digitalRead(slowButton) << 1; //case 2
int fast = digitalRead(fastButton) << 0; //case 1 //bit position 0
int data = stopB | slow| fast;
    if (data) {
      Serial.print( "sending data = " );
      Serial.println(data);
      radio.write(&data, sizeof(data)) ;
    }
}
