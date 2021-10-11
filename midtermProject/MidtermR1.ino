/*
  Salama Almheiri
  Midterm (reciever)
  Oct 10 2021
  Version 2
*/
#include <Servo.h>
Servo myservo;
Servo myservo2;

const int CEPIN = 9;
const int CSNPIN = 10;
int pos = 0;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(CEPIN, CSNPIN);  // CE, CSN
// Byte of array representing the address.
// This is the address where we will send the data.
// This should be same on the receiving side.
const byte address[6] = "00001";

// Motor controller pins
const int in1Pin = 7;
const int in2Pin = 6; // PWM pin! Left (back)
const int in3Pin = 5; // PWM pin! Right
const int in4Pin = 4;
bool moveDC = true;

//Servo
bool moveServo1 = true;
bool moveServo2 = true;


void setup() {
  // Servo Motors
  myservo.attach(3);
  myservo2.attach(2);
  // DC Motors
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  Serial.begin(115200);

  // RF24 setup
  bool retval = radio.begin();
  // Serial.println(retval);
  radio.openReadingPipe(0, address);  // Destination address
  radio.setPALevel(RF24_PA_MIN);      // Min or max
  radio.startListening();             // sets  module as receiver
}
void loop() {
  if (radio.available())  //Looking for the data.
  {
    int data;
    radio.read(&data, sizeof(data));  //Reading the data
    switch (data) { //Serial.println(data);
        break;
      case 0x01:
        Serial.println("Green Button");
        if (moveServo1 == true) { // 2)Servo moves once
          myservo.attach(3); //Green
          delay(15);
          myservo.write(50);
          delay(1000);
          myservo.write(160);
          delay(1000);
          myservo.detach();
          delay(1000);
          moveServo1 = false;
        }
        if (moveDC == true) {
          //Motor sequence
          // Stop
          Serial.println("stop");
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
          delay(1500);
          //Forward
          Serial.println("Forward");
          digitalWrite(in1Pin, LOW);
          analogWrite(in2Pin, 160);
          analogWrite(in3Pin, 80);
          digitalWrite(in4Pin, HIGH);
          delay(1000);
          moveDC = false;
        }
      break;

      case 0x02:
        Serial.println("Red Button");
        if (moveServo2 == true) {
          myservo2.attach(2); //Red
          delay(15);
          myservo2.write(90); //0= red to left //down
          delay(1000);
          myservo2.write(160);
          delay(1000);
          myservo2.detach();
          delay(1000);
          moveServo2 = false;
        }
        if (moveDC == true) {
          // Stop
          Serial.println("stop");
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
          delay(1500);
          // Left
          Serial.println("left");
          digitalWrite (in1Pin, HIGH);
          analogWrite (in2Pin, 255);
          analogWrite (in3Pin, 50);
          digitalWrite (in4Pin, HIGH);
          delay(1500);
          moveDC = false;
        }
      break;

      case 0x04: //Stop button
        Serial.println("stop"); //turning left
        digitalWrite(in1Pin, HIGH);
        digitalWrite(in2Pin, HIGH);
        digitalWrite(in3Pin, HIGH);
        digitalWrite(in4Pin, HIGH);
        break;

      default:
        Serial.println("invalid code");
        stop();
        digitalWrite(in3Pin, LOW);
        digitalWrite(in4Pin, LOW);
        break;
    }
  } else {
    Serial.println("stop");
    stop();
  }
  delay(5);
}

void stop() {
  digitalWrite (in1Pin, HIGH);
  analogWrite (in2Pin, 255);
  analogWrite (in3Pin, 255);
  digitalWrite (in4Pin, HIGH);
}
