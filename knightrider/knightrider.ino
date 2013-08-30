/*
LEDs sketch
Blink three LEDs each connected to a different digital pin
*/
const int firstLedPin = 3;
const int secondLedPin = 5;
const int thirdLedPin = 6;

const int mydelay = 200;

const int ledPins[] = {0,1,2,3,4,5,6};
const int NbrLEDs = 6;

void setup()
{
//pinMode(firstLedPin, OUTPUT);
//pinMode(secondLedPin, OUTPUT);
pinMode(thirdLedPin, OUTPUT);
pinMode(13, OUTPUT);

  for(int led = 0; led <  NbrLEDs; led++)
  {
    pinMode(led, OUTPUT);
  }

}
// choose the pin for each of the LEDs
// declare LED pins as output
// declare LED pins as output
// declare LED pins as output
void loop()
{
  
  for(int led = 0; led <  NbrLEDs; led++)
  {
    blinkLED(led, mydelay);
  }
  
// flash each of the LEDs for 1000 milliseconds (1 second)
// blinkLED(13, mydelay);
}
// blink the LED on the given pin for the duration in milliseconds
void blinkLED(int pin, int duration)
{
digitalWrite(pin, LOW);
digitalWrite(13, LOW);
// turn LED on
delay(duration);
digitalWrite(pin, HIGH);
digitalWrite(13, LOW);
// turn LED off
delay(duration);
}

