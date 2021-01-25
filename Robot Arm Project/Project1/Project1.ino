// make the built in LED blink


// put your setup code here, to run once:
void setup() {
  //designates the built in LED for signal output
  pinMode(LED_BUILTIN, OUTPUT);
}

// put your main code here, to run repeatedly:
void loop() {  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for number of milisec
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
}
