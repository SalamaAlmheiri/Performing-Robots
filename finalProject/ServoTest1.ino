#include <Servo.h>
Servo myservo;

int pos = 0;    // variable to store the servo position
const int swPin1 = 2;

void setup() {
  myservo.attach(8);
}

void loop() {
  //  if (digitalRead(swPin1) == HIGH) {
  //    for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //      // in steps of 1 degree
  //      myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //      delay(15);                       // waits 15ms for the servo to reach the position
  //    }
  //    for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
  //      myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //      delay(15);                       // waits 15ms for the servo to reach the position
  //    }
  //  }

  if (digitalRead(swPin1) == HIGH) { //without this its continious
    //      myservo.write(pos);
    myservo.write(90);
    delay(1000);
    myservo.write(200);
    delay(1000);
    myservo.write(90);
    delay(1000);
    //    myservo.detach();
    //    delay(1000);

 }

}
