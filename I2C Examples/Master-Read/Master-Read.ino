// this is the client/master example
// here we make a request from our server/slave device and get data back

#include <Wire.h>

const int SLAVE_ADDR = 13; // the address of the slave device

void setup() {      
  Serial.begin(9600); // just for serial monitor logging
  Wire.begin(); // join the I2C bus as a master device
}

void loop() {

  Serial.println("Sending Request");
  byte buf[4];
  int n = Wire.requestFrom(SLAVE_ADDR, 4); // we request 4 bytes from device at SLAVE_ADDR
  Wire.readBytes( buf, n);
  if ( n != 4){
    Serial.println("Error, didn't receive 4 bytes");
  }

  // the four bytes we received represent an unsigned long
  // some example code below on how we might reconstruct an unsigned long from 4 bytes
  unsigned long blinkNumber = 0;
  unsigned long temp;
  temp = buf[3];
  blinkNumber += temp << (byte)24;
  temp = buf[2];
  blinkNumber += temp << (byte)16;
  temp = buf[1];
  blinkNumber += temp << (byte)8;
  blinkNumber += buf[0];
  
  Serial.println(blinkNumber);
  // act on the data we have received
  while(blinkNumber > 0) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    blinkNumber--;
  }
  delay(1000);

  for(int i = 0; i < 10; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}
