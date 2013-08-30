// TickleBot
// by Jeff Putney <http://MakerspaceUrbana.com> 
// This example code is in the public domain.

//Lets include some some other code so we don't have to write much
#include <Servo.h>                    //This will let us use Servo object
#include <CapacitiveSensor.h>         //This will let us use the CapacitiveSensor object
 
// create an instance CapacativeSensor object called capSensor
// pin 4 sends electrical energy
// pin 2 senses senses a change
CapacitiveSensor capSensor = CapacitiveSensor(4,2);

long sensorValue = 0;;
int threshold = 2000;  //This sets how sensative our touch sensor will be
 
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;  // and another for our second servo. A maximum of eight servo objects can be created 
 
int turnLeft = 60;    // variable to store the servo position 
int center = 80;    // variable to store the servo position 
int turnRight = 100;    // variable to store the servo position 
int steps_remain = 0;
 
void setup() 
{ //Ok the programm is running, lets hook up our servos
  myservo1.attach(10);  // attaches the servo on pin 10 to the servo object 
  myservo2.attach(11);  // attaches the servo on pin 11 to the servo object 
  
  //Lets aslo set the servos so both be centered durring setup     
  myservo1.write(center);
  myservo2.write(center);
} 
 
 
void loop() 
{  //Setup is over, so now we should do things! Over and over and over again.

  //Let's first check the signal strength of out touch sensor. (The bigger the finger the higher the value we will read)
  sensorValue = capSensor.capacitiveSensor(30);
  
  
  //Now if the recieved touch strength value us strong enough lets wiggle our legs. And if it's not strong enough 
  //we just skip over the insides of this loop and don;t move anything.
  if(sensorValue > threshold)
  {
    steps_remain += 6;
  }
  if(steps_remain > 0)
  {
    //Set the first position we want the servos to move to
    myservo1.write(turnLeft);
    myservo2.write(turnRight);
    //Servos are slow and moving takes a little time, so lets wait for them to get where they are going
    delay(200);
    //Set the next servo positions
    myservo1.write(turnRight);
    myservo2.write(turnLeft);
    //wait for the servos to move
    delay(200); 
    //Set the last servo position
    myservo1.write(center);
    myservo2.write(center);
     //wait for the servos to move
    steps_remain -= 1;
    delay(200);
  }
  
  //This is the end of the loop, that's boring! Luckily the arduino we jump back to the top of the 
  //loop so we can keep doing things. 
} 



