/*
  Salama Almheiri
  Production Assignment Robot with Motor
  September 20 2021
*/

const int in1Pin = 7;
const int in2Pin = 6; //PWN Pin (analogue write)
const int in3Pin = 4;
const int in4Pin = 5; //PWN Pin (analogue write)

void setup() {
  Serial.begin(9600);
  pinMode (in1Pin, OUTPUT);
  pinMode (in2Pin, OUTPUT);
  pinMode (in3Pin, OUTPUT);
  pinMode (in4Pin, OUTPUT);
}

void loop() {
  //does not move at the start
  digitalWrite (in1Pin, HIGH);
  analogWrite (in2Pin, 255);
  digitalWrite (in3Pin, HIGH);
  analogWrite (in4Pin, 255);
  delay(4000);

  //Forward
  digitalWrite (in1Pin, LOW);
  analogWrite (in2Pin, 200);
  digitalWrite (in3Pin, LOW);
  analogWrite (in4Pin, 200);
  delay(3000);

  //Back
  digitalWrite (in1Pin, HIGH);
  analogWrite (in2Pin, 50);
  digitalWrite (in3Pin, HIGH);
  analogWrite (in4Pin, 50);
  delay(1000);

  // Right
  digitalWrite (in1Pin, LOW);
  analogWrite (in2Pin, 180);
  digitalWrite (in3Pin, HIGH);
  analogWrite (in4Pin, 255);
  delay(1000);

  //Back
  digitalWrite (in1Pin, HIGH);
  analogWrite (in2Pin, 50);
  digitalWrite (in3Pin, HIGH);
  analogWrite (in4Pin, 50);
  delay(1000);

  //left
  digitalWrite (in1Pin, HIGH);
  analogWrite (in2Pin, 255);
  digitalWrite (in3Pin, LOW);
  analogWrite (in4Pin, 180);
  delay(1000);
}
