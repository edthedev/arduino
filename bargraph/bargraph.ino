/*
LEDs sketch
Blink three LEDs each connected to a different digital pin
*/
const int mydelay = 200;

#define foreach(item, array) \
	for(int keep = 1, \
	count = 0,\
	size = sizeof (array) / sizeof *(array); \
	keep && count != size; \
	keep = !keep, count++) \
	for(item = (array) + count; keep; keep = !keep)

const int bar_pins[] = {3,4,5,6,7,8,9,10,11,12};
const int bar_pin_count = 10;

void setup()
{

// Flash for heartbeat.
pinMode(13, OUTPUT);

// Serial.begin(9600);

// declare LED pins as output
  for(int led = bar_pins[0]; led <=  bar_pins[0] + bar_pin_count; led++)
  {
    pinMode(led, OUTPUT);
  }

}
void loop()
{
	foreach(const int *pin, bar_pins)
	{
		digitalWrite(*pin, LOW);
		delay(mydelay);
	}

	foreach(const int *pin, bar_pins)
	{
		digitalWrite(*pin, HIGH);
		delay(mydelay);
	}

}
