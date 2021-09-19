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
  //pwn: higher number= slower
  //Forward
  digitalWrite (in1Pin, LOW);
  digitalWrite (in2Pin, HIGH);
  digitalWrite (in3Pin, LOW);
  digitalWrite (in4Pin, HIGH);
  delay(3000);

  //Back
  digitalWrite (in1Pin, HIGH);
  analogWrite (in2Pin, 160);
  digitalWrite (in3Pin, HIGH);
  analogWrite (in4Pin, 160);
  delay(3000);

// Right
  digitalWrite (in1Pin, LOW);
  analogWrite (in2Pin, 75);
  digitalWrite (in3Pin, HIGH);
  analogWrite (in4Pin, 255);
  delay(2000);

//left 
  digitalWrite (in1Pin, HIGH);
  analogWrite (in2Pin, 255);
  digitalWrite (in3Pin, LOW);
  analogWrite (in4Pin, 95);
  delay(2000);
}
