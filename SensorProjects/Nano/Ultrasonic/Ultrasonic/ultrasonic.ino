// make the built in LED blink
#include <Ultrasonic.h>

int distance;
// Trig, Echo
Ultrasonic ultrasonic(7, 6);

// put your setup code here, to run once:
void setup() {
  //designates the built in LED for signal output
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // for serial output to log the analog movement
  // trig, echo
}

// put your main code here, to run repeatedly:
void loop() {  
  distance = ultrasonic.read();
  //ultrasonic.write();
  Serial.print("distance = ");
  Serial.print(distance,DEC);
  Serial.println("");
  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(600);                       // wait for number of milisec
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
}
