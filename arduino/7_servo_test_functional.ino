#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo
Servo myservo5;  // create servo object to control a servo
Servo myservo6;  // create servo object to control a servo
Servo myservo7;  // create servo object to control a servo

void setup() {
  myservo1.attach(15);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(2);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(0);  // attaches the servo on pin 9 to the servo object
  myservo4.attach(4);  // attaches the servo on pin 9 to the servo object
  myservo5.attach(16);  // attaches the servo on pin 9 to the servo object
  myservo6.attach(17);  // attaches the servo on pin 9 to the servo object
  myservo7.attach(5);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = 150;
  myservo1.write(val);                  // sets the servo position according to the scaled value between 0-180
  delay(1000);                           // waits for the servo to get there

  myservo2.write(val);                  // sets the servo position according to the scaled value between 0-180
  delay(1000);                           // waits for the servo to get there

  myservo3.write(val);                  // sets the servo position according to the scaled value between 0-180
  delay(1000);                           // waits for the servo to get there

  myservo4.write(val);                  // sets the servo position according to the scaled value between 0-180
  delay(1000);                           // waits for the servo to get there

  myservo5.write(val);                  // sets the servo position according to the scaled value between 0-180
  delay(1000);                           // waits for the servo to get there

  myservo6.write(val);                  // sets the servo position according to the scaled value between 0-180
  delay(1000);                           // waits for the servo to get there

  myservo7.write(val);                  // sets the servo position according to the scaled value between 0-180
  delay(1000);                           // waits for the servo to get there
}