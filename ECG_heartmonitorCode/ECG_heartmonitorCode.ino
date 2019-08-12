#include <Servo.h>

Servo thumb, fingers;
/******************************************************************************
Heart_Rate_Display.ino
Demo Program for AD8232 Heart Rate sensor.
Casey Kuhns @ SparkFun Electronics
6/27/2014
https://github.com/sparkfun/AD8232_Heart_Rate_Monitor
The AD8232 Heart Rate sensor is a low cost EKG/ECG sensor.  This example shows
how to create an ECG with real time display.  The display is using Processing.
This sketch is based heavily on the Graphing Tutorial provided in the Arduino
IDE. http://www.arduino.cc/en/Tutorial/Graph
Resources:
This program requires a Processing sketch to view the data in real time.
Development environment specifics:
  IDE: Arduino 1.0.5
  Hardware Platform: Arduino Pro 3.3V/8MHz
  AD8232 Heart Monitor Version: 1.0
This code is beerware. If you see me (or any other SparkFun employee) at the
local pub, and you've found our code helpful, please buy us a round!
Distributed as-is; no warranty is given.
******************************************************************************/

int analogpin = A1;
int val = 0;
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -
  fingers.attach(9);  //Attach the servo for the four fingers to pin9
  thumb.attach(8);   // Attach the servo for the thumb to pin 8
}

void loop() {
  
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
    Serial.println('---------');
   
  }
  else{
    val = analogRead(analogpin); //muscle sensor connected to pin A1 being stated as val
  Serial.println(val);
  if( val > 550) //if you flex and the sensor value is greater than 550 then close servos--adjust this value to your muscle sensor value
  {
    thumb.write(180);
    fingers.write(180);
    delay(10);
  }
   if( val > 550){
    thumb.write(-180);
    fingers.write(-180);
  delay(10);
    }
  }
}
