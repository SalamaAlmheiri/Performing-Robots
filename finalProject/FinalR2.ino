// For final: receiver version 1
#include <Servo.h>
#include "Sweeper.h"
const int CEPIN = 9;
const int CSNPIN = 10;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(CEPIN, CSNPIN);  // CE, CSN

// NEOPIXEL FACE
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> 
#endif
#define PIN        3 
#define NUMPIXELS 64
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500 
const int bashfulPixels[] = {9,11,13,15,18,22,28,33,38,42,43,44,45};
const int bashfulCount = 13;
const int happyPixels[] = {10,14,17,19,21,23,33,36,39,42,46,51,52,53};
const int happyCount = 14;
const int happyPin = 7;
const int bashfulPin = 2;
// END OF NEOPIXEL

// Address where we send the data.
const byte address[6] = "00002";

// Motor controller pins
const int in1aPin = 7;
const int in2aPin = 6;
const int in3aPin = 5;
const int in4aPin = 4;

const int in1bPin = A0;
const int in2bPin = A1;
const int in3bPin = A2;
const int in4bPin = A3;
Sweeper myservo(15);
const int swPin1 = 2;
int val= 0;


void setup() {
  // neopixel
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  Serial.begin(9600);
  pinMode(happyPin, INPUT_PULLUP);
  pinMode(bashfulPin, INPUT_PULLUP);
  strip.begin();
  // end neopixel
  
  // Motor controller pins
  pinMode(in1aPin, OUTPUT);
  pinMode(in2aPin, OUTPUT);
  pinMode(in3aPin, OUTPUT);
  pinMode(in4aPin, OUTPUT);

  pinMode(in1bPin, OUTPUT);
  pinMode(in2bPin, OUTPUT);
  pinMode(in3bPin, OUTPUT);
  pinMode(in4bPin, OUTPUT);

  //myservo.Attach(8);

  Serial.begin(9600);

  // RF24 setup
  if (!radio.begin()) {
    Serial.println("radio  initialization failed");
    while (1)
      ;
  } else {
    Serial.println("radio successfully initialized");
  }
  radio.openReadingPipe(0, address);  // Destination address
  radio.setPALevel(RF24_PA_MIN);      // Min or max
  radio.startListening();             // sets  module as receiver
}
void loop() {
  strip.show();
 
  uint8_t pipeNum;
  if (radio.available(&pipeNum))  //Looking for the data.
  {
    int data;
    
//    if (data > 100 && data <= 180) {
//        myservo.Attach(8);
//        myservo.Update();
//        playHappy();
//    } else if (data < 100) {
//      myservo.Detach();
//    } else if (data > 180 && data < 300) {
//      playBashful();
//    } 
    
    Serial.print("data available on pipe ");
    Serial.println(pipeNum);
    radio.read(&data, sizeof(data));  //Reading the data
    Serial.print("data = ");
    Serial.println( data);

    switch (data) {
      case 0b00010000: //0x01
        Serial.println("turning right");
        digitalWrite(in1aPin, LOW);
        digitalWrite(in2aPin, HIGH);
        digitalWrite(in3aPin, HIGH);
        digitalWrite(in4aPin, HIGH);

        digitalWrite(in1bPin, LOW);
        digitalWrite(in2bPin, HIGH);
        digitalWrite(in3bPin, HIGH);
        digitalWrite(in4bPin, HIGH);
        break;
      case 0b00001000: //0x02
        Serial.println("forward");
        digitalWrite(in1aPin, LOW);
        digitalWrite(in2aPin, HIGH);
        digitalWrite(in3aPin, LOW);
        digitalWrite(in4aPin, HIGH);

        digitalWrite(in1bPin, LOW);
        digitalWrite(in2bPin, HIGH);
        digitalWrite(in3bPin, LOW);
        digitalWrite(in4bPin, HIGH);
        break;
      case 0b00000100: //0x04
        Serial.println("turning left");
        digitalWrite(in1aPin, HIGH);
        digitalWrite(in2aPin, HIGH);
        digitalWrite(in3aPin, LOW);
        digitalWrite(in4aPin, HIGH);

        digitalWrite(in1bPin, HIGH);
        digitalWrite(in2bPin, HIGH);
        digitalWrite(in3bPin, LOW);
        digitalWrite(in4bPin, HIGH);
        break;
      case 0b00000010: //0x08
        Serial.println("backward");
        digitalWrite(in1aPin, HIGH);
        digitalWrite(in2aPin, LOW);
        digitalWrite(in3aPin, HIGH);
        digitalWrite(in4aPin, LOW);

        digitalWrite(in1bPin, HIGH);
        digitalWrite(in2bPin, LOW);
        digitalWrite(in3bPin, HIGH);
        digitalWrite(in4bPin, LOW);
        break;

      default:
      //  Serial.println("invalid code");
        stop();
        break;
    }
  } else {
    //Serial.println("stop");
    stop();
  }
  delay(5);
}

void stop() {
  digitalWrite(in1aPin, HIGH);
  digitalWrite(in2aPin, HIGH);
  digitalWrite(in3aPin, HIGH);
  digitalWrite(in4aPin, HIGH);

  digitalWrite(in1bPin, HIGH);
  digitalWrite(in2bPin, HIGH);
  digitalWrite(in3bPin, HIGH);
  digitalWrite(in4bPin, HIGH);
}

void playBashful() {
  strip.clear();
  for (int i = 0; i < bashfulCount; i++) {
    strip.setPixelColor(bashfulPixels[i], strip.Color(15, 0, 0));  
  }
}

void playHappy() {
  strip.clear();
  for (int i = 0; i < happyCount; i++) {
    strip.setPixelColor(happyPixels[i], strip.Color(10, 10, 0));  
  }
}
