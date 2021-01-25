// move the servo motor
// helper code to prepare the servoce at the starting angle for the robot

// pin assignment
// A0 V G
// A1 V G
// A2 V G
// 8  V G
// 9  V G
//
// A3 V G
// A4 V G
// A5 V G
// 6  V G
// 7  V G
//
// S V G

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;// variable to store the servo position

void setup() {
  myservo.write(0);              // tell servo to go to position in variable 'pos'
  delay(100);
  myservo.attach(A0);  // attaches the servo on pin 7 to the servo object
}

void loop() {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);
}
