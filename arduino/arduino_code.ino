#include <Servo.h>
#include <ezButton.h>

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;
Servo motor6;
ezButton button(22); // Define a button on GPIO pin 21
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
#define ledRedPin   12 // GPIO23
#define ledGreenPin  14 // GPIO22
#define ledBluePin   27 // GPIO21

void setup() {
  Serial.begin(115200);
  motor1.attach(15);
  motor2.attach(2);
  motor3.attach(0);
  motor4.attach(4);
  motor5.attach(16);
  motor6.attach(17);

  button.setDebounceTime(50); // Set debounce time to 50 ms
  mySwitch.setDebounceTime(50); // set debounce time to 50 milliseconds

  pinMode(ledRedPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledBluePin, OUTPUT);
}

void move_servo_forward(int state, Servo &motor) {
  button.loop();
  mySwitch.loop();

  switch_state = mySwitch.getState();
  //Serial.println(switch_state);

   //Serial.print("moving forwards");
  // Serial.print(curr_elapsed_time);
  // Serial.print("state:");
  // Serial.println(state);
  // Serial.print(", switch pos:");
  // Serial.println(switch_state);

  if (button.isPressed()) {
    button_pressed_state = (button_pressed_state + 1) % 18;
    //Serial.print("button: " + button_pressed_state);
    motor_state = button_pressed_state / 2;
    // Serial.print("motor state: ");
    // Serial.println(motor_state);
  }

  if ((motor_state != state) || (curr_elapsed_time >= 7000) || (switch_state == HIGH)) {
    //Serial.print("state changed while moving forward");
    return;
  } else {
    motor.write(95); // Full speed in the opposite direction
    curr_elapsed_time = curr_elapsed_time + 200;
    delay(200);
    move_servo_forward(state, motor);
  }
}

void move_servo_backward(int state, Servo &motor) {

  button.loop();
  mySwitch.loop();

  switch_state = mySwitch.getState();
  //Serial.println(switch_state);

  //Serial.print("moving backwards");
  // Serial.print(curr_elapsed_time);
  // Serial.print("state:");
  // Serial.println(state);
  // Serial.print(", switch pos:");
  // Serial.println(switch_state);

  if (button.isPressed()) {
    button_pressed_state = (button_pressed_state + 1) % 18;
    //Serial.println("button: " + button_pressed_state);
    motor_state = button_pressed_state / 2;
    // Serial.print("motor state: ");
    // Serial.println(motor_state);
  }

  if ((motor_state != state) || (curr_elapsed_time <= -7000) || (switch_state == LOW)) {
    //Serial.print("state changed while moving backward");
    return;
  } else {
    motor.write(83); // Full speed in the opposite direction
    curr_elapsed_time = curr_elapsed_time - 200;
    delay(200);
    move_servo_backward(state, motor);
  }
}

void stop_servo(int state, Servo &motor) {
  button.loop();
  mySwitch.loop();

  switch_state = mySwitch.getState();
  //Serial.print("motor stopped");
  //Serial.println(switch_state);

  if (button.isPressed()) {
    button_pressed_state = (button_pressed_state + 1) % 18;
    //Serial.println("button: " + button_pressed_state);
    motor_state = button_pressed_state / 2;
    // Serial.print("motor state: ");
    // Serial.println(motor_state);
  }
  if (state != motor_state) {
    //Serial.print("state changed while stopped");
    return;
  }
  motor.write(90); // Stop the servo
  delay(1000);
  //stop_servo(motor_state, motor);
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
  //Serial.println(switch_state);

  if (button.isPressed()) {
    button_pressed_state = (button_pressed_state + 1) % 18;
    //Serial.println("button: " + button_pressed_state);
    motor_state = button_pressed_state / 2;

    // Stop all motors and turn off the LED
    // motor1.write(90);
    // motor2.write(90);
    // motor3.write(90);
    // motor4.write(90);
    // motor5.write(90);
    // motor6.write(90);
    // setRGB(0, 0, 0); // Turn off the RGB LED
  }
  Serial.print("motor state: ");
  Serial.println(motor_state);

  switch (motor_state) {
    case 0:
      // stop_servo(motor_state, motor1);
      // stop_servo(motor_state, motor2);
      // stop_servo(motor_state, motor3);
      // stop_servo(motor_state, motor4);
      // stop_servo(motor_state, motor5);
      // stop_servo(motor_state, motor6);
      // setRGB(0, 0, 0); // Turn off the RGB LED
      break;
    case 1:
      if ((motor_state == 1) && ((curr_elapsed_time <= -6800) || (switch_state == LOW))) {
        curr_elapsed_time = 0;
        move_servo_forward(motor_state, motor1);
      }
      // Stop the servo
      // Serial.print("finished moving forward");
      // Serial.print(motor_state);
      // Serial.print(curr_elapsed_time);
      while ((motor_state == 1) && (switch_state == LOW) && (curr_elapsed_time >= 6800)) {
        mySwitch.loop();
        switch_state = mySwitch.getState();
        stop_servo(motor_state, motor1);
      }

      // Rotate continuous servo in one direction (forward) for 7 seconds
      //Serial.print(motor1_pos);
      if ((motor_state == 1) && ((curr_elapsed_time >= 6800) || (switch_state == HIGH))) {
        curr_elapsed_time = 0;
        move_servo_backward(motor_state, motor1);
      }

      // Stop the servo
      // Serial.print("finished moving backward");
      // Serial.print(motor_state);
      // Serial.print(curr_elapsed_time);
      while ((motor_state == 1) && (switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
        mySwitch.loop();
        switch_state = mySwitch.getState();
        stop_servo(motor_state, motor1);
      }
      motor1.write(90);   // stop the motor
      motor2.write(90);   // stop the motor
      motor3.write(90);   // stop the motor
      motor4.write(90);   // stop the motor
      motor5.write(90);   // stop the motor
      motor6.write(90);   // stop the motor
      motor1_pos = curr_elapsed_time;
      curr_elapsed_time = 0;
      break;
    case 2:
      if ((motor_state == 2) && ((curr_elapsed_time <= -6800) || (switch_state == LOW))) {
        curr_elapsed_time = 0;
        move_servo_forward(motor_state, motor2);
      }
      // Stop the servo
      //Serial.print(motor2_pos);
      while ((motor_state == 2) && (switch_state == LOW) && (curr_elapsed_time >= 6800)) {
        mySwitch.loop();
        switch_state = mySwitch.getState();
        stop_servo(motor_state, motor2);
      }

      // Rotate continuous servo in one direction (forward) for 7 seconds
      if ((motor_state == 2) && ((curr_elapsed_time >= 6800) || (switch_state == HIGH))) {
        curr_elapsed_time = 0;
        move_servo_backward(motor_state, motor2);
      }

      // Stop the servo
      //Serial.print(motor2_pos);
      while ((motor_state == 2) && (switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
        mySwitch.loop();
        switch_state = mySwitch.getState();
        stop_servo(motor_state, motor2);
      }
      motor1.write(90);   // stop the motor
      motor2.write(90);   // stop the motor
      motor3.write(90);   // stop the motor
      motor4.write(90);   // stop the motor
      motor5.write(90);   // stop the motor
      motor6.write(90);   // stop the motor
      motor2_pos = curr_elapsed_time;
      curr_elapsed_time = 0;
      break;
    case 3:
      if ((motor_state == 3) && ((curr_elapsed_time <= -6800) || (switch_state == LOW))) {
        curr_elapsed_time = 0;
        move_servo_forward(motor_state, motor3);
      }
      // Stop the servo
      while ((motor_state == 3) && (switch_state == LOW) && (curr_elapsed_time >= 6800)) {
        mySwitch.loop();
        switch_state = mySwitch.getState();
        stop_servo(motor_state, motor3);
      }

      // Rotate continuous servo in one direction (forward) for 7 seconds
      if ((motor_state == 3) && ((curr_elapsed_time >= 6800) || (switch_state == HIGH))) {
        curr_elapsed_time = 0;
        move_servo_backward(motor_state, motor3);
      }

      // Stop the servo
      while ((motor_state == 3) && (switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
        mySwitch.loop();
        switch_state = mySwitch.getState();
        stop_servo(motor_state, motor3);
      }
      motor1.write(90);   // stop the motor
      motor2.write(90);   // stop the motor
      motor3.write(90);   // stop the motor
      motor4.write(90);   // stop the motor
      motor5.write(90);   // stop the motor
      motor6.write(90);   // stop the motor
      motor3_pos = curr_elapsed_time;
      curr_elapsed_time = 0;
      break;
    case 4:
      if ((motor_state == 4) && ((curr_elapsed_time <= -6800) || (switch_state == LOW))) {
        curr_elapsed_time = 0;
        move_servo_forward(motor_state, motor4);
      }
      // Stop the servo
      while ((motor_state == 4) && (switch_state == LOW) && (curr_elapsed_time >= 6800)) {
        mySwitch.loop();
        switch_state = mySwitch.getState();
        stop_servo(motor_state, motor4);
      }

      // Rotate continuous servo in one direction (forward) for 7 seconds
      if ((motor_state == 4) && ((curr_elapsed_time >= 6800) || (switch_state == HIGH))) {
        curr_elapsed_time = 0;
        move_servo_backward(motor_state, motor4);
      }

      // Stop the servo
      while ((motor_state == 4) && (switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
        mySwitch.loop();
        switch_state = mySwitch.getState();
        stop_servo(motor_state, motor4);
      }
      motor1.write(90);   // stop the motor
      motor2.write(90);   // stop the motor
      motor3.write(90);   // stop the motor
      motor4.write(90);   // stop the motor
      motor5.write(90);   // stop the motor
      motor6.write(90);   // stop the motor
      motor4_pos = curr_elapsed_time;
      curr_elapsed_time = 0;
      break;
    case 5:
      if ((motor_state == 5) && ((curr_elapsed_time <= -6800) || (switch_state == LOW))) {
        curr_elapsed_time = 0;
        move_servo_forward(motor_state, motor5);
      }
      // Stop the servo
      while ((motor_state == 5) && (switch_state == LOW) && (curr_elapsed_time >= 6800)) {
        mySwitch.loop();
        switch_state = mySwitch.getState();
        stop_servo(motor_state, motor5);
      }

      // Rotate continuous servo in one direction (forward) for 7 seconds
      if ((motor_state == 5) && ((curr_elapsed_time >= 6800) || (switch_state == HIGH))) {
        curr_elapsed_time = 0;
        move_servo_backward(motor_state, motor5);
      }

      // Stop the servo
      while ((motor_state == 5) && (switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
        mySwitch.loop();
        switch_state = mySwitch.getState();
        stop_servo(motor_state, motor5);
      }
      motor1.write(90);   // stop the motor
      motor2.write(90);   // stop the motor
      motor3.write(90);   // stop the motor
      motor4.write(90);   // stop the motor
      motor5.write(90);   // stop the motor
      motor6.write(90);   // stop the motor
      motor5_pos = curr_elapsed_time;
      curr_elapsed_time = 0;
      break;
    case 6:
      if ((motor_state == 6) && ((curr_elapsed_time <= -6800) || (switch_state == LOW))) {
        curr_elapsed_time = 0;
        move_servo_forward(motor_state, motor6);
      }
      // Stop the servo
      while ((motor_state == 6) && (switch_state == LOW) && (curr_elapsed_time >= 6800)) {
        mySwitch.loop();
        switch_state = mySwitch.getState();
        stop_servo(motor_state, motor6);
      }

      // Rotate continuous servo in one direction (forward) for 7 seconds
      if ((motor_state == 6) && ((curr_elapsed_time >= 6800) || (switch_state == HIGH))) {
        curr_elapsed_time = 0;
        move_servo_backward(motor_state, motor6);
      }

      // Stop the servo
      while ((motor_state == 6) && (switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
        mySwitch.loop();
        switch_state = mySwitch.getState();
        stop_servo(motor_state, motor6);
      }
      motor1.write(90);   // stop the motor
      motor2.write(90);   // stop the motor
      motor3.write(90);   // stop the motor
      motor4.write(90);   // stop the motor
      motor5.write(90);   // stop the motor
      motor6.write(90);   // stop the motor
      motor6_pos = curr_elapsed_time;
      curr_elapsed_time = 0;
      break;
    case 7:
      motor6.write(90);
      mySwitch.loop();
      switch_state = mySwitch.getState();
      if (switch_state == HIGH) {
        setRGB(255, 0, 0); // Set RGB LED to red
      } else {
        setRGB(0, 0, 0); // Turn off the RGB LED
      }
      
      led_state_pos = digitalRead(ledRedPin) ? 1 : 10;
      //setRGB(0, 0, 0); // Turn off the RGB LED
      //led_state_pos = 0;
      break;
    case 8:
      // first stop all servos and LED
      // stop_servo(motor_state, motor1);
      // stop_servo(motor_state, motor2);
      // stop_servo(motor_state, motor3);
      // stop_servo(motor_state, motor4);
      // stop_servo(motor_state, motor5);
      // stop_servo(motor_state, motor6);
      // setRGB(0, 0, 0); // Turn off the RGB LED

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