/*
  Salama Almheiri
  Midterm (reciever)
  Oct 13 2021
  Version Final
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
RF24 radio(CEPIN, CSNPIN);

const byte address[6] = "00001";

// DC Motor pins
const int in1Pin = 7;
const int in2Pin = 6; // PWM pin
const int in3Pin = 5; // PWM pin
const int in4Pin = 4;

bool moveDC = true;
bool moveDC2 = true;
bool moveDC3 = true;
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

  // RF24 connection
  bool retval = radio.begin();
  radio.openReadingPipe(0, address);  // Destination address
  radio.setPALevel(RF24_PA_MIN);      // Min or max
  radio.startListening();             // Sets module as receiver
}
void loop() {
  if (radio.available())
  {
    int data;
    radio.read(&data, sizeof(data));
    Serial.println(data);
    
    switch (data) {
      case 0x01: // Once green button is pressed:
        Serial.println("Green Button");
        if (moveServo1 == true) { // Right hand Servo moves to drawing position
          Serial.println("moveServo1 = true");
          myservo.attach(3);
          delay(15);
          myservo.write(50);
          delay(1000);
          myservo.write(160);
          delay(1000);
          myservo.detach();
          delay(1000);
          moveServo1 = false;
        }
        if (moveDC == true) { // Robot 'drawing' sequence 1
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
          analogWrite(in2Pin, 150);
          analogWrite(in3Pin, 90);
          digitalWrite(in4Pin, HIGH);
          delay(800);
          // Stop
          Serial.println("stop");
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
          delay(900);
          // Left
          Serial.println("left");
          digitalWrite (in1Pin, HIGH);
          analogWrite (in2Pin, 255);
          analogWrite (in3Pin, 50);
          digitalWrite (in4Pin, HIGH);
          delay(700);
          // Stop
          Serial.println("stop");
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
          delay(900);
          //Forward
          Serial.println("Forward");
          digitalWrite(in1Pin, LOW);
          analogWrite(in2Pin, 140);
          analogWrite(in3Pin, 100);
          digitalWrite(in4Pin, HIGH);
          delay(600);
          // Right
          Serial.println("right");
          digitalWrite (in1Pin, LOW);
          analogWrite (in2Pin, 150);
          analogWrite (in3Pin, 255);
          digitalWrite (in4Pin, HIGH);
          delay(800);
          //Forward
          Serial.println("Forward");
          digitalWrite(in1Pin, LOW);
          analogWrite(in2Pin, 140);
          analogWrite(in3Pin, 100);
          digitalWrite(in4Pin, HIGH);
          delay(1400);
          // Stop
          Serial.println("stop");
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
          delay(900);
          // Right
          Serial.println("right");
          digitalWrite (in1Pin, LOW);
          analogWrite (in2Pin, 150);
          analogWrite (in3Pin, 255);
          digitalWrite (in4Pin, HIGH);
          delay(850);
          //Forward
          Serial.println("Forward");
          digitalWrite(in1Pin, LOW);
          analogWrite(in2Pin, 140);
          analogWrite(in3Pin, 100);
          digitalWrite(in4Pin, HIGH);
          delay(500);
          // Stop
          Serial.println("stop");
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
          delay(900);
          // Right
          Serial.println("right");
          digitalWrite (in1Pin, LOW);
          analogWrite (in2Pin, 150);
          analogWrite (in3Pin, 255);
          digitalWrite (in4Pin, HIGH);
          delay(850);
          // Left
          Serial.println("left");
          digitalWrite (in1Pin, HIGH);
          analogWrite (in2Pin, 255);
          analogWrite (in3Pin, 50);
          digitalWrite (in4Pin, HIGH);
          delay(200);
          // Right
          Serial.println("right");
          digitalWrite (in1Pin, LOW);
          analogWrite (in2Pin, 150);
          analogWrite (in3Pin, 255);
          digitalWrite (in4Pin, HIGH);
          delay(400);
          // Left
          Serial.println("left");
          digitalWrite (in1Pin, HIGH);
          analogWrite (in2Pin, 255);
          analogWrite (in3Pin, 50);
          digitalWrite (in4Pin, HIGH);
          delay(400);
          // Right
          Serial.println("right");
          digitalWrite (in1Pin, LOW);
          analogWrite (in2Pin, 150);
          analogWrite (in3Pin, 255);
          digitalWrite (in4Pin, HIGH);
          delay(300);
          //Forward
          Serial.println("Forward");
          digitalWrite(in1Pin, LOW);
          analogWrite(in2Pin, 140);
          analogWrite(in3Pin, 100);
          digitalWrite(in4Pin, HIGH);
          delay(300);
          // Left
          Serial.println("left");
          digitalWrite (in1Pin, HIGH);
          analogWrite (in2Pin, 255);
          analogWrite (in3Pin, 50);
          digitalWrite (in4Pin, HIGH);
          delay(200);
          //Forward
          Serial.println("Forward");
          digitalWrite(in1Pin, LOW);
          analogWrite(in2Pin, 140);
          analogWrite(in3Pin, 100);
          digitalWrite(in4Pin, HIGH);
          delay(300);
          // Right
          Serial.println("right");
          digitalWrite (in1Pin, LOW);
          analogWrite (in2Pin, 150);
          analogWrite (in3Pin, 255);
          digitalWrite (in4Pin, HIGH);
          delay(400);
          //Forward
          Serial.println("Forward");
          digitalWrite(in1Pin, LOW);
          analogWrite(in2Pin, 140);
          analogWrite(in3Pin, 100);
          digitalWrite(in4Pin, HIGH);
          delay(700);
          // Stop
          Serial.println("stop");
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
          delay(900);
          // Left C1
          Serial.println("left");
          digitalWrite (in1Pin, HIGH);
          analogWrite (in2Pin, 255);
          analogWrite (in3Pin, 50);
          digitalWrite (in4Pin, HIGH);
          delay(2000);
          moveDC = false;
        }
        break;

      case 0x02: //Once red button is pressed:
        Serial.println("Red Button");
        if (moveServo2 == true) {
          Serial.println("moveServo2 = true"); // // Left hand/ red Servo moves to drawing position
          myservo2.attach(2);
          delay(15);
          myservo2.write(90);
          delay(1000);
          myservo2.write(160);
          delay(1000);
          myservo2.detach();
          delay(1000);
          moveServo2 = false;
        }
        if (moveDC2 == true) { // Robot 'drawing' sequence 2
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
          analogWrite(in2Pin, 150);
          analogWrite(in3Pin, 60);
          digitalWrite(in4Pin, HIGH);
          delay(700);
          // Stop
          Serial.println("stop");
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
          delay(900);
          // Right
          Serial.println("right");
          digitalWrite (in1Pin, LOW);
          analogWrite (in2Pin, 160);
          analogWrite (in3Pin, 255);
          digitalWrite (in4Pin, HIGH);
          delay(200);
          // Stop
          Serial.println("stop");
          digitalWrite(in1Pin, HIGH);
          digitalWrite(in2Pin, HIGH);
          digitalWrite(in3Pin, HIGH);
          digitalWrite(in4Pin, HIGH);
          delay(900);

          // Left C1
          Serial.println("left");
          digitalWrite (in1Pin, HIGH);
          analogWrite (in2Pin, 255);
          analogWrite (in3Pin, 50);
          digitalWrite (in4Pin, HIGH);
          delay(500);
          // Right
          Serial.println("right");
          digitalWrite (in1Pin, LOW);
          analogWrite (in2Pin, 150);
          analogWrite (in3Pin, 255);
          digitalWrite (in4Pin, HIGH);
          delay(500);
          //Forward
          Serial.println("Forward");
          digitalWrite(in1Pin, LOW);
          analogWrite(in2Pin, 150);
          analogWrite(in3Pin, 60);
          digitalWrite(in4Pin, HIGH);
          delay(600);
          // Left C1
          Serial.println("left");
          digitalWrite (in1Pin, HIGH);
          analogWrite (in2Pin, 255);
          analogWrite (in3Pin, 50);
          digitalWrite (in4Pin, HIGH);
          delay(300);
          // Right
          Serial.println("right");
          digitalWrite (in1Pin, LOW);
          analogWrite (in2Pin, 150);
          analogWrite (in3Pin, 255);
          digitalWrite (in4Pin, HIGH);
          delay(500);
          moveDC2 = false;
        }
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
