#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.

// this constant won't change. It's the pin number of the sensor's output:
const int trigPin = 9;        //assign pin 9 to trigger
const int echoPin = 10;       //assign pin 10 to echo
const int LED = 13;           //keep the LED on pin 13
const boolean debug = true;  //variable to show hide debug info

// establish variables for duration of the ping, and the distance result in centimeters and one for LED blink rate:
long duration, cm;
int blinkrate = 0;

void setup() {
  // initialize serial communication:
  if(debug){
    Serial.begin(9600);
    Serial.println("Starting blinker");
  }
  pinMode(LED, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input     
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);     
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // the time that the pin changes state from low to high
  cm = microsecondsToCentimeters(duration); //transfer the time into distance
  
  if(cm < 100){

  if(cm < 30){
    blinkrate = map(cm, 1, 30, 10, 300);
  }
  else if(cm < 90){
    blinkrate = map(cm, 30, 90, 300, 1000);
  }
  else{
    blinkrate = 0;
  }

  if(debug){
    Serial.print(" cm: ");//print the information of distance on the serial monitor
    Serial.print(cm);
    Serial.print("   blinkrate: ");  
    Serial.println(blinkrate);    
  }
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(blinkrate);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(blinkrate);
  }
  delay(20);
}

long microsecondsToCentimeters(long microseconds) //transfer the time into distance
{
  return microseconds / 29 / 2;
}
