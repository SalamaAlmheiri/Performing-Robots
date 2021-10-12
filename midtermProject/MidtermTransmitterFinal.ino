/*
  Salama Almheiri
  Midterm (transmitter)
  Oct 13 2021
  Version Final
*/

const int CEPIN = 9;
const int CSNPIN = 10;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(CEPIN, CSNPIN);

const byte address[6] = "00001"; 

// Push Buttons
const int greenButton = 4; //Green button
const int redButton = 2; //Red button

void setup() {
  Serial.begin(115200);

  // Radio connection
  boolean retval = radio.begin();
  Serial.println(retval);
  radio.openWritingPipe(address);  // Destination addres
  radio.setPALevel(RF24_PA_MIN);   // Min or max
  radio.stopListening();           // Sets the module as transmitter
}
void loop() {
int green = digitalRead(greenButton) << 1; //case 2
int red = digitalRead(redButton) << 0; //case 1 //bit position 0
int data = green| red;
    if (data) {
      Serial.print( "sending data = " );
      Serial.println(data);
      radio.write(&data, sizeof(data)) ;
    }
}
