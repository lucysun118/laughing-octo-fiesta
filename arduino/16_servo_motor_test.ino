#include <Wire.h>

// Make sure to have the Adafruit Servo Motor Shield library installed
#include <Adafruit_ServoMotor.h>

Adafruit_ServoMotorShield pwm = Adafruit_ServoMotorShield();

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit Servo Motor Shield Test!");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  delay(10);
}

// This code uses nested loops to iterate through each servo and sweep it from its minimum position to its maximum position and then back. 
//Adjust the delay values if needed.

void loop() {
  for (uint16_t pulselen = pwm.getServoMinimum(); pulselen < pwm.getServoMaximum(); pulselen++) {
    for (uint8_t servoNum = 0; servoNum < 16; servoNum++) {
      pwm.setPWM(servoNum, 0, pulselen);
    }
    delay(10);
  }

  delay(1000);

  for (uint16_t pulselen = pwm.getServoMaximum(); pulselen > pwm.getServoMinimum(); pulselen--) {
    for (uint8_t servoNum = 0; servoNum < 16; servoNum++) {
      pwm.setPWM(servoNum, 0, pulselen);
    }
    delay(10);
  }

  delay(1000);
}