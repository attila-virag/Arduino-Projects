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

const int X = A3; //x axis analog data
const int Y = A4; //y axis analog data
const int Z = 6; // pressing down the analog stick is a digital signal

void setup() {
  pinMode(Z, INPUT);
  Serial.begin(9600); // for serial output to log the analog movement
}

void loop() {
  int x,y,z;

  x = analogRead(X);
  y = analogRead(Y);
  z = digitalRead(Z);

  Serial.print("X = ");
  Serial.print(x,DEC);
  Serial.println("");
  Serial.print("Y = ");
  Serial.print(y,DEC);
  Serial.println("");
  Serial.print("Z = ");
  if(z == 1){
    Serial.print("1");
  }
  else {
    Serial.print("0");
  }
  Serial.println("");
  delay(1000);
}
