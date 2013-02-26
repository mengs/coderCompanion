//Program by Jeremy Blum
//www.jeremyblum.com
//Controls a Servo Motor using the info from an IR Distance Sensor

//Include Servo Library
#include <Servo.h>

//Define Pins
int servoPin = 9;
int distPin = 0;



//Create Servo Object
Servo Buddy;

void setup()
{
 
  //Attaches the Servo to our object
  Buddy.attach(servoPin);
  Serial.begin(9600);
}

void loop()
{
  int pos = 0; 
  //Read the Distance Sensor and adjust values
  int dist = analogRead(distPin);
  Serial.println(dist);
  
  if (dist>1023)
  {
    Buddy.write(pos); 
  }
  
  else if (dist>400 && dist<1023)
  { 
    for( pos = 0; pos < 180; pos += 5)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      Buddy.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);
      // waits 15ms for the servo to reach the position 
    }
    for( pos = 180; pos >= 140; pos -= 8)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      Buddy.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    }
    delay(150); 
    for( pos = 140; pos <= 180; pos += 8)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      Buddy.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    }
    delay(150); 
    for( pos = 180; pos >= 0; pos -= 8)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      Buddy.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    }
  }
  Buddy.write(0); 
  Serial.println(dist);
  //Turn the servo
  delay(10);
  
}
