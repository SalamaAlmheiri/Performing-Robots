//Motor and Servo
//Both servo and motors are working.

#include <Servo.h>
Servo myservo;
Servo myservo2;

const int in1Pin = 7;
const int in2Pin = 6; // PWM pin! Left (back)
const int in3Pin = 5; // PWM pin! Right
const int in4Pin = 4;

const int button = 8;
bool moveServo1 = true;
bool moveServo2 = true;
bool moveDC = true;

void setup() {
  Serial.begin(9600);
  myservo.attach(3);
  myservo2.attach(2);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
}

void loop() { //(1,2=Left/ 3,4=right)
  int buttonState = digitalRead(button);
  Serial.println(buttonState);
  if (buttonState == HIGH) { // 1)Button pressed
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

    if (moveDC == true) { // 3)DC Motor sequence played
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
      delay(3000);
      moveDC = false;
    }
  }
  else {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, HIGH);
    digitalWrite(in3Pin, HIGH);
    digitalWrite(in4Pin, HIGH);
  }
}
