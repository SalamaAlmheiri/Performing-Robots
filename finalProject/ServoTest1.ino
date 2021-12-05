#include <Servo.h>
Servo myservo;

const int swPin1 = 2;

void setup() {
  myservo.attach(8);
}

void loop() {
  if (digitalRead(swPin1) == HIGH) { //(without this its continious)
    myservo.write(90);
    delay(1000);
    myservo.write(200);
    delay(1000);
    myservo.write(90);
    delay(1000);
 }
}
