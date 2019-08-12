
#include <Servo.h>

Servo thumb, fingers;

int analogpin = A1;
int val = 0;
  void setup()
  {
    pinMode(10,INPUT); // Assign Pin As Input
    pinMode(11,INPUT); // Assign Pin As Input
    fingers.attach(9);  //Attach the servo for the four fingers to pin9
    thumb.attach(8);   // Attach the servo for the thumb to pin 8
    Serial.begin(9600);  // this is for serial moniter to see the muscle sensor value you're getting
  }
  void loop()
{
  val = analogRead(analogpin); //muscle sensor connected to pin A1 being stated as val
  Serial.println(val);
  if( val < 550) //if you flex and the sensor value is greater than 550 then close servos--adjust this value to your muscle sensor value
  {
    thumb.write(180);
    fingers.write(180);
    delay(100);
  }
else{
    thumb.write(-180);
    fingers.write(-180);
    delay(100);
  }
}

