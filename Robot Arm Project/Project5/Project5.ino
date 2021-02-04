// This is the code for controlling the robot arm

// pin assignment
// A0 V G - arm forward servo
// A1 V G - base pivot servo
// A2 V G
// 8  V G - arm retract servo
// 9  V G - claw servo
//
// A3 V G
// A4 V G
// A5 V G
// 6  V G
// 7  V G
//
// S V G

#include <Servo.h>
Servo basePivot;  // move base left and right, left analog X, A1
Servo armForward; // move arm forvard, servo, 2, left analog Y positive, A0
Servo armRetract; // retract arm, servo 3, left analog Y negative, 8
Servo claw; // moves claw, servo 4, right analog Y, 9

//int basePos=90, arm1Pos=60, arm2Pos=130, clawPos=0;
int basePos=90, arm1Pos=60, arm2Pos=130, clawPos=0;
// left controller is 1, right controller is 2

const int X1 = A3; //x axis analog data
const int Y1 = A4; //y axis analog data
const int Z1 = 8; // pressing down the analog stick is a digital signal

const int X2 = A2;
const int Y2 = A5; //
const int Z2 = 6;

float ANALOG_MIDDLE = 350;
const float ANGLE_CHANGE_MAX = 3;

int ANALOG_X1_REF = 350;
int ANALOG_Y1_REF = 350;
int ANALOG_X2_REF = 350;

#include <Servo.h>

void MoveServo(const float& dir, const int& changeMax, int& analogPos, Servo& servo, int& pos,int& refPos) {

  // we will only apply a control if the 
  float delta = dir;
  if(analogPos > refPos+50) {
    delta = dir*1;
  }
  else if (analogPos < refPos-50) {
    delta = -1*dir;
  }
  else {
    return;
  }
  pos = pos + (delta*changeMax);

  if(pos < 0) {
    pos = 0;
  }
  if(pos > 180) {
    pos = 180;
  }
  
  servo.write(pos);              // tell servo to go to position in variable 'pos'
}

void setup() {
  pinMode(Z1, INPUT);
  pinMode(Z2, INPUT);
  
  basePivot.attach(A1);
  armForward.attach(A0);
  armRetract.attach(8);
  claw.attach(9);

  
  ANALOG_X1_REF = analogRead(X1);
  ANALOG_Y1_REF = analogRead(Y1);
  ANALOG_X2_REF = analogRead(X2);
  
  basePivot.write(basePos);             // initialize the arm to base position
  armForward.write(arm1Pos);
  armRetract.write(arm2Pos);
  claw.write(clawPos);
  delay(1000);
}

void loop() {
  int x1 = analogRead(X1);
  int y1 = analogRead(Y1);
  int y2 = analogRead(Y2);
  
  MoveServo(1, ANGLE_CHANGE_MAX, x1, basePivot, basePos, ANALOG_X1_REF);
  MoveServo(1, ANGLE_CHANGE_MAX, y1, armForward, arm1Pos,  ANALOG_Y1_REF);
  MoveServo(-1, ANGLE_CHANGE_MAX, y1, armRetract, arm2Pos, ANALOG_Y1_REF);
  MoveServo(1, ANGLE_CHANGE_MAX, y2, claw, clawPos, ANALOG_X2_REF);

  delay(20);
}
