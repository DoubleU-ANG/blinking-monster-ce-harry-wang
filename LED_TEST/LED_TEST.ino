void setup() {
  // put your setup code here, to run once:
      pinMode(LED_BUILTIN, OUTPUT);  //turn the pin for LED into OUTPUT Mode
}

void loop() {
  // put your main code here, to run repeatedly:
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(500);                       // wait for half second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(500);                       // wait for half second
}
