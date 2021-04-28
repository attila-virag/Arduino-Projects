// this is the server/slave example
// here we 'generate' data that we can serve to the client upon request
// the main loop will generate data continously
// When a client request comes in the main loop gets an interrupt
// and the function that we registered with Wire.onRequest gets called

#include <Wire.h>

const int SLAVE_ADDR = 13; // the address of the slave device

volatile unsigned long randomData;

void setup() {
  Wire.begin(SLAVE_ADDR); // join the I2C bus as a slave device at SLAVE_ADDR
  Wire.onRequest(requestEvent); // register event callback
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

void loop() {
  // while we 'generate' the random data we dont want to receive an interrupt
  noInterrupts();
  randomData = random(1,21);
  Serial.println(randomData);
  // we are ready to turn interrupts back on
  // any interrupt that arrived while we had them turned off was queued and will fire when we turn them back on
  interrupts();
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
}

// callback that gets executed when the master asks for data
void requestEvent() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Request for data was received");

  // unsigned long is 4 bytes
  // we need to break it into byte size chunks to send it
  byte buf[4];
  buf[0] = randomData & 255;
  buf[1] = (randomData >> 8)  & 255;
  buf[2] = (randomData >> 16) & 255;
  buf[3] = (randomData >> 24) & 255;
  
  Wire.write(buf, sizeof(buf));
}
