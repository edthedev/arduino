
# define LED_PIN 13
# define LOW_PIN 3
# define TOP_PIN 12
void setup()
{
	pinMode(LED_PIN, OUTPUT);
	
	for(int pin=LOW_PIN; pin<=TOP_PIN; pin++)
	{
		pinMode(pin, OUTPUT);
	}
}

void loop()
{
	digitalWrite(LED_PIN, HIGH);
    delay(100);
	digitalWrite(LED_PIN, LOW);

	for(int pin=LOW_PIN; pin<=TOP_PIN; pin++)
	{
		digitalWrite(pin, HIGH);
		delay(900);
	}

	for(int pin=TOP_PIN; pin>=LOW_PIN; pin--)
	{
		digitalWrite(pin, LOW);
		delay(100);
	}
}
/*
##	for(int i=9; i<13; i++)
##	{
##		digitalWrite(i, HIGH);
##	}
##    delay(100);
##	for(int i=9; i<13; i++)
##	{
##		digitalWrite(i, LOW);
##	}
##    delay(900);
#*/
