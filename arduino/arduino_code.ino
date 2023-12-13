#include <Servo.h>
#include <ezButton.h>

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;
Servo motor6;
ezButton button(21); // Define a button on GPIO pin 21
ezButton mySwitch(13); // create ezButton object that attaches to ESP32 pin GPIO16

int motor1_pos = 0;
int motor2_pos = 0;
int motor3_pos = 0;
int motor4_pos = 0;
int motor5_pos = 0;
int motor6_pos = 0;
int motor7_pos = 0;
int led_state_pos = 0;

int servo_curr_pos = 0;
bool servo_move_opp_dir = false;
bool first_time_run = true;
int button_pressed_state = 0;
int motor_state = 0;

int curr_elapsed_time = 0;
int switch_state;

// LED pin
const int ledPin = 3;

void setup() {
  Serial.begin(115200);
  motor1.attach(5);
  motor2.attach(6);
  motor3.attach(7);
  motor4.attach(8);
  motor5.attach(9);
  motor6.attach(10);

  button.setDebounceTime(50); // Set debounce time to 50 ms
  mySwitch.setDebounceTime(50); // set debounce time to 50 milliseconds

  pinMode(ledRedPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledBluePin, OUTPUT);
}

void move_servo_forward(Servo &motor) {
  mySwitch.loop();
  switch_state = mySwitch.getState();

  if ((curr_elapsed_time >= 7000) || (switch_state == HIGH)) {
    return;
  } else {
    motor.write(95); // Full speed in the opposite direction
    curr_elapsed_time = curr_elapsed_time + 200;
    delay(200);
    move_servo_forward(motor);
  }
}

void move_servo_backward(Servo &motor) {
  mySwitch.loop();
  switch_state = mySwitch.getState();

  if ((curr_elapsed_time <= -7000) || (switch_state == LOW)) {
    return;
  } else {
    motor.write(87); // Full speed in the opposite direction
    curr_elapsed_time = curr_elapsed_time - 200;
    delay(200);
    move_servo_backward(motor);
  }
}

void stop_servo(Servo &motor) {
  switch_state = mySwitch.getState();
  motor.write(90); // Stop the servo
  delay(1000);
}

void setRGB(int red, int green, int blue) {
  analogWrite(ledRedPin, red);
  analogWrite(ledGreenPin, green);
  analogWrite(ledBluePin, blue);
}

void loop() {
  button.loop();
  mySwitch.loop();

  switch_state = mySwitch.getState();

  if (button.isPressed()) {
    button_pressed_state = (button_pressed_state + 1) % 18;
    motor_state = button_pressed_state / 2;

    // Stop all motors and turn off the LED
    motor1.write(90);
    motor2.write(90);
    motor3.write(90);
    motor4.write(90);
    motor5.write(90);
    motor6.write(90);
    setRGB(0, 0, 0); // Turn off the RGB LED

    switch (motor_state) {
      case 1:
        if ((curr_elapsed_time <= -6800) || (switch_state == LOW)) {
          curr_elapsed_time = 0;
          move_servo_forward(motor1);
        }
        // Stop the servo
        while ((switch_state == LOW) && (curr_elapsed_time >= 6800)) {
          mySwitch.loop();
          switch_state = mySwitch.getState();
          stop_servo(motor1);
        }

        // Rotate continuous servo in one direction (forward) for 7 seconds
        if ((curr_elapsed_time >= 6800) || (switch_state == HIGH)) {
          curr_elapsed_time = 0;
          move_servo_backward(motor1);
        }

        // Stop the servo
        while ((switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
          mySwitch.loop();
          switch_state = mySwitch.getState();
          stop_servo(motor1);
        }
        motor1_pos = curr_elapsed_time;
        curr_elapsed_time = 0;
        break;
      case 2:
        if ((curr_elapsed_time <= -6800) || (switch_state == LOW)) {
          curr_elapsed_time = 0;
          move_servo_forward(motor2);
        }
        // Stop the servo
        while ((switch_state == LOW) && (curr_elapsed_time >= 6800)) {
          mySwitch.loop();
          switch_state = mySwitch.getState();
          stop_servo(motor2);
        }

        // Rotate continuous servo in one direction (forward) for 7 seconds
        if ((curr_elapsed_time >= 6800) || (switch_state == HIGH)) {
          curr_elapsed_time = 0;
          move_servo_backward(motor2);
        }

        // Stop the servo
        while ((switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
          mySwitch.loop();
          switch_state = mySwitch.getState();
          stop_servo(motor2);
        }
        motor2_pos = curr_elapsed_time;
        curr_elapsed_time = 0;
        break;
      case 3:
        if ((curr_elapsed_time <= -6800) || (switch_state == LOW)) {
          curr_elapsed_time = 0;
          move_servo_forward(motor3);
        }
        // Stop the servo
        while ((switch_state == LOW) && (curr_elapsed_time >= 6800)) {
          mySwitch.loop();
          switch_state = mySwitch.getState();
          stop_servo(motor3);
        }

        // Rotate continuous servo in one direction (forward) for 7 seconds
        if ((curr_elapsed_time >= 6800) || (switch_state == HIGH)) {
          curr_elapsed_time = 0;
          move_servo_backward(motor3);
        }

        // Stop the servo
        while ((switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
          mySwitch.loop();
          switch_state = mySwitch.getState();
          stop_servo(motor3);
        }
        motor3_pos = curr_elapsed_time;
        curr_elapsed_time = 0;
        break;
      case 4:
        if ((curr_elapsed_time <= -6800) || (switch_state == LOW)) {
          curr_elapsed_time = 0;
          move_servo_forward(motor4);
        }
        // Stop the servo
        while ((switch_state == LOW) && (curr_elapsed_time >= 6800)) {
          mySwitch.loop();
          switch_state = mySwitch.getState();
          stop_servo(motor4);
        }

        // Rotate continuous servo in one direction (forward) for 7 seconds
        if ((curr_elapsed_time >= 6800) || (switch_state == HIGH)) {
          curr_elapsed_time = 0;
          move_servo_backward(motor4);
        }

        // Stop the servo
        while ((switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
          mySwitch.loop();
          switch_state = mySwitch.getState();
          stop_servo(motor4);
        }
        motor4_pos = curr_elapsed_time;
        curr_elapsed_time = 0;
        break;
      case 5:
        if ((curr_elapsed_time <= -6800) || (switch_state == LOW)) {
          curr_elapsed_time = 0;
          move_servo_forward(motor5);
        }
        // Stop the servo
        while ((switch_state == LOW) && (curr_elapsed_time >= 6800)) {
          mySwitch.loop();
          switch_state = mySwitch.getState();
          stop_servo(motor5);
        }

        // Rotate continuous servo in one direction (forward) for 7 seconds
        if ((curr_elapsed_time >= 6800) || (switch_state == HIGH)) {
          curr_elapsed_time = 0;
          move_servo_backward(motor5);
        }

        // Stop the servo
        while ((switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
          mySwitch.loop();
          switch_state = mySwitch.getState();
          stop_servo(motor5);
        }
        motor5_pos = curr_elapsed_time;
        curr_elapsed_time = 0;
        break;
      case 6:
        if ((curr_elapsed_time <= -6800) || (switch_state == LOW)) {
          curr_elapsed_time = 0;
          move_servo_forward(motor6);
        }
        // Stop the servo
        while ((switch_state == LOW) && (curr_elapsed_time >= 6800)) {
          mySwitch.loop();
          switch_state = mySwitch.getState();
          stop_servo(motor6);
        }

        // Rotate continuous servo in one direction (forward) for 7 seconds
        if ((curr_elapsed_time >= 6800) || (switch_state == HIGH)) {
          curr_elapsed_time = 0;
          move_servo_backward(motor6);
        }

        // Stop the servo
        while ((switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
          mySwitch.loop();
          switch_state = mySwitch.getState();
          stop_servo(motor6);
        }
        motor6_pos = curr_elapsed_time;
        curr_elapsed_time = 0;
        break;
      case 7:
        mySwitch.loop();
        switch_state = mySwitch.getState();
        if (switch_state == HIGH) {
          setRGB(255, 0, 0); // Set RGB LED to red
        } else {
          setRGB(0, 0, 0); // Turn off the RGB LED
        }
        led_state_pos = digitalRead(ledRedPin) ? 10 : 1;
        break;
      case 8:
        Serial.print("e:");
        Serial.println(motor1_pos);

        Serial.print("n:");
        Serial.println(motor2_pos);

        Serial.print("m:");
        Serial.println(motor3_pos);

        Serial.print("t:");
        Serial.println(motor4_pos);

        Serial.print("u:");
        Serial.println(motor5_pos);

        Serial.print("r:");
        Serial.println(motor6_pos);

        Serial.print("j:");
        Serial.println(led_state_pos);

        break;
    }

    delay(200);
  }
}