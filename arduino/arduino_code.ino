#include <Servo.h>
#include <ezButton.h>

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;
Servo motor6;
Servo motor7;
ezButton button(21); // Define a button on GPIO pin 21
ezButton mySwitch(13);  // create ezButton object that attach to ESP32 pin GPIO16

int servo_curr_pos = 0;
bool servo_move_opp_dir = false;
bool first_time_run = true;
int button_pressed_state = 0;
int motor_state = 0;

int curr_elapsed_time = 0;
int switch_state;

void setup() {
  Serial.begin(115200);
  motor1.attach(5); // Attach the servo to pin 5
  motor2.attach(); // Attach the servo to pin 5
  motor3.attach(); // Attach the servo to pin 5
  motor4.attach(); // Attach the servo to pin 5
  motor5.attach(); // Attach the servo to pin 5
  motor6.attach(); // Attach the servo to pin 5
  motor7.attach(); // Attach the servo to pin 5

  button.setDebounceTime(50); // Set debounce time to 50 ms
  mySwitch.setDebounceTime(50); // set debounce time to 50 milliseconds
}

// void setServoAngle(int angle) {
//   motor1.write(angle);
// }

void move_servo_forward() {
  mySwitch.loop();
  switch_state = mySwitch.getState();
  //Serial.println(switch_state);
  if ((curr_elapsed_time >= 7000) || (switch_state == HIGH)){
    //curr_elapsed_time = 0;
    return;
  } else {
    //Serial.println("Forward");
    //Serial.println(curr_elapsed_time);
    motor1.write(95); // Full speed in the opposite direction
    curr_elapsed_time = curr_elapsed_time + 200;
    delay(200);
    move_servo_forward();
  }
}

void move_servo_backward() {
  mySwitch.loop();
  switch_state = mySwitch.getState();
  //Serial.println(switch_state);
  if ((curr_elapsed_time <= -7000) || (switch_state == LOW)) {
    //curr_elapsed_time = 0;
    return;
  } else {
    //Serial.println("Backward");
    //Serial.println(curr_elapsed_time);
    motor1.write(87); // Full speed in the opposite direction
    curr_elapsed_time = curr_elapsed_time - 200;
    delay(200);
    move_servo_backward();
  }
}

void stop_servo() {
  switch_state = mySwitch.getState();
  motor1.write(90); // Full speed in the opposite direction
  delay(1000);
}

void loop() {
  button.loop(); // Call the loop function to update the button state
  mySwitch.loop(); // MUST call the loop() function first

  // update switch state
  switch_state = mySwitch.getState();

  if (button.isPressed()) {
    // Toggle button state between 0 and 8
    button_pressed_state = (button_pressed_state + 1) % 18;
    motor_state = button_pressed_state / 2;

    //Serial.print("button state changed to ");
    //Serial.println(button_pressed_state / 2);

    delay(200); // Optional delay to debounce the button
  }

  // if (first_time_run) {
  //   motor1.write(80);
      //motor2.write(80);
      //motor3.write(80);
      //motor4.write(80);
      //motor5.write(80);
      //motor6.write(80);
      //motor7.write(80);
  //   delay(8000);
  //   first_time_run = false;
  // }

  // Rotate continuous servo in the opposite direction (backward) for 7 seconds
  if ((curr_elapsed_time <= -6800) || (switch_state == LOW)) {
    curr_elapsed_time = 0;
    move_servo_forward();
    //curr_elapsed_time = 0;
  }
  // Stop the servo
  //Serial.print("Time elapsed (to send): ");
  Serial.println(curr_elapsed_time);
  while ((switch_state == LOW) && (curr_elapsed_time >= 6800)) {
    mySwitch.loop();
    switch_state = mySwitch.getState();
    //Serial.print("please toggle switch to HIGH to continue moving");
    stop_servo();
  }
  //curr_elapsed_time = 0;

  // Rotate continuous servo in one direction (forward) for 7 seconds
  if ((curr_elapsed_time >= 6800) || (switch_state == HIGH)) {
    curr_elapsed_time = 0;
    move_servo_backward();
    //curr_elapsed_time = 0;
  }

  // Stop the servo
  //Serial.print("Time elapsed (to send): ");
  Serial.println(curr_elapsed_time);
  while ((switch_state == HIGH) && (curr_elapsed_time <= -6800)) {
    mySwitch.loop();
    switch_state = mySwitch.getState();
    //Serial.print("please toggle switch to LOW to continue moving");
    stop_servo();
  }
  //curr_elapsed_time = 0;
}
