// Simple program to demonstrate controlling the speed and direction
// of a DC motor using the L298 H-bridge module

//Motor test 1 (for final)

// Pin connections
const int in1aPin = 7;
const int in2aPin = 6;
const int in3aPin = 5;
const int in4aPin = 4;

const int in1bPin = A0;
const int in2bPin = A1;
const int in3bPin = A2;
const int in4bPin = A3;

const int swPin1 = 2; //for testing

void setup() {
  pinMode(in1aPin, OUTPUT);
  pinMode(in2aPin, OUTPUT);
  pinMode(in3aPin, OUTPUT);
  pinMode(in4aPin, OUTPUT);

  pinMode(in1bPin, OUTPUT);
  pinMode(in2bPin, OUTPUT);
  pinMode(in3bPin, OUTPUT);
  pinMode(in4bPin, OUTPUT);
}

void loop() {

  if (digitalRead(swPin1) == HIGH) { //Front
    digitalWrite(in1aPin, LOW);
    digitalWrite(in2aPin, HIGH);
    digitalWrite(in3aPin, LOW);
    digitalWrite(in4aPin, HIGH);

    digitalWrite(in1bPin, LOW);
    digitalWrite(in2bPin, HIGH);
    digitalWrite(in3bPin, LOW);
    digitalWrite(in4bPin, HIGH);
  }
  else {
    digitalWrite(in1aPin, HIGH);
    digitalWrite(in2aPin, HIGH);
    digitalWrite(in3aPin, HIGH);
    digitalWrite(in4aPin, HIGH);

    digitalWrite(in1bPin, HIGH);
    digitalWrite(in2bPin, HIGH);
    digitalWrite(in3bPin, HIGH);
    digitalWrite(in4bPin, HIGH);
  }
}

// Front
//    digitalWrite(in1aPin, LOW);
//    digitalWrite(in2aPin, HIGH);
//    digitalWrite(in3aPin, LOW);
//    digitalWrite(in4aPin, HIGH);
//
//    digitalWrite(in1bPin, LOW);
//    digitalWrite(in2bPin, HIGH);
//    digitalWrite(in3bPin, LOW);
//    digitalWrite(in4bPin, HIGH);

//Back
//    digitalWrite(in1aPin, HIGH);
//    digitalWrite(in2aPin, LOW);
//    digitalWrite(in3aPin, HIGH);
//    digitalWrite(in4aPin, LOW);
//
//    digitalWrite(in1bPin, HIGH);
//    digitalWrite(in2bPin, LOW);
//    digitalWrite(in3bPin, HIGH);
//    digitalWrite(in4bPin, LOW);
