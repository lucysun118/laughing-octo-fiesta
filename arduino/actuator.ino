#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(10);
}

void loop() {
  myservo.write(180); // move actuator forward
  delay(800); // wait for actuator to finish
  myservo.write(90); // make actuator stop

  delay(500); // keep actuator in place

  myservo.write(0); // move actuator backward
  delay(800); // wait for actuator to finish
  myservo.write(90); // make actuator stop

  // while(1) ()
}
