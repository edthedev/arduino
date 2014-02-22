/*
LEDs sketch
Blink three LEDs each connected to a different digital pin
*/
const int mydelay = 200;
const int tiny_delay = 100;

const int TRIGGER = 3;
const int ECHO = 2;

#define foreach(item, array) \
	for(int keep = 1, \
	count = 0,\
	size = sizeof (array) / sizeof *(array); \
	keep && count != size; \
	keep = !keep, count++) \
	for(item = (array) + count; keep; keep = !keep)

const int bar_pins[] = {4,5,6,7,8,9,10,11,12};
const int bar_pin_count = 9;

void setup()
{

Serial.begin(9600);

// Flash for heartbeat.
pinMode(13, OUTPUT);

pinMode(TRIGGER, OUTPUT);
pinMode(ECHO, INPUT);

// Serial.begin(9600);

// declare LED pins as output
  for(int led = bar_pins[0]; led <=  bar_pins[0] + bar_pin_count; led++)
  {
    pinMode(led, OUTPUT);
  }


}
void loop()
{

long duration, inches, cm;

// The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(ECHO, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
 
  Serial.print("duration, ");
  Serial.print(duration);
  Serial.println();
 
	// Turn em off.
	foreach(const int *pin, bar_pins)
	{
		digitalWrite(*pin, HIGH);
	}

	// Turn some back on.
	foreach(const int *pin, bar_pins)
	{
		if(duration > *pin * 100)
		{
			digitalWrite(*pin, LOW);
		}
	}


	delay(mydelay);

}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

