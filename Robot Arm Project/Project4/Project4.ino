// print analog stick movement to screen

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

int pos = 0;// variable to store the servo position
int x;

const int X = A3; //x axis analog data
const int Y = A4; //y axis analog data
const int Z = 6; // pressing down the analog stick is a digital signal

const float ANALOG_MIDDLE = 371;
const float ANGLE_CHANGE_MAX = 10;

void Logger() {
  Serial.print("X = ");
  Serial.print(x,DEC);
  Serial.println("");
  Serial.print("POS = ");
  Serial.print(pos,DEC);
  Serial.println("");
  Serial.println("");
}

void MoveServo(const float& deadBand, const int& changeMax, int& analogPos, Servo& servo, int& pos) {

  // the analog values seem to range from 0 to 747 with neutral position being 371
  // we can center and normalize the values accordingly and map it a costum angle rate change in the servo

  float delta = ((float)analogPos - ANALOG_MIDDLE)/ANALOG_MIDDLE;
  Serial.print("delta = ");
  Serial.print(delta,DEC);
  Serial.println("");
  if(abs(delta) < deadBand) {
    Serial.print("control treshold");
    return;
  }
  
  pos = pos + (changeMax*delta);

  if(pos < 0) {
    pos = 0;
  }
  if(pos > 180) {
    pos = 180;
  }
  
  servo.write(pos);              // tell servo to go to position in variable 'pos'
  //delay(15);                       // waits 15ms for the servo to reach the position
}

void setup() {
  pinMode(Z, INPUT);
  Serial.begin(9600); // for serial output to log the analog movement
  myservo.attach(A0);  // attaches the servo on pin 7 to the servo object
}

void loop() {

  x = analogRead(X);

  MoveServo(0.1, 5, x, myservo,pos);
  //Logger();
  delay(10);
}
