#include <Servo.h>

Servo motor1;

void setup() {
  Serial.begin(9600);
  motor1.attach(21);
}

int run = 0;

void loop() {
  
  // run 5 times
  if (run < 5) {
    motor1.write(180); // move actuator forward
    Serial.println("forward");
    delay(800); // wait for actuator to finish
    motor1.write(90); // make actuator stop
    Serial.println("stop");

    delay(500); // keep actuator in place
    Serial.println("wait");

    motor1.write(0); // move actuator backward
    Serial.println("backward");
    delay(800); // wait for actuator to finish
    motor1.write(90); // make actuator stop
    Serial.println("stop");

    run++;
  }

  
}
