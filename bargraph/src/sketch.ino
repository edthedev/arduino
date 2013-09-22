
# define LED_PIN 13
# define LOW_PIN 3
# define TOP_PIN 12

# define SWITCH 2

void setup()
{
	pinMode(LED_PIN, OUTPUT);
	
	for(int pin=LOW_PIN; pin<=TOP_PIN; pin++)
	{
		pinMode(pin, OUTPUT);
	}
	pinMode(SWITCH, INPUT);

	Serial.begin(9600);

	
}

void do_work()
{
	// val = digitalRead(SWITCH);	
}

int val = 0;
int switch_val = 0;
int next_pin = 0;

void loop()
{
	switch_val = digitalRead(SWITCH);	
	Serial.println(switch_val);

	if(switch_val)
	{
		digitalWrite(next_pin, HIGH);
		next_pin++;
		if(next_pin > TOP_PIN)
		{
			next_pin = TOP_PIN;
		}
	}
	else
	{
		digitalWrite(next_pin, LOW);
		next_pin--;
		if(next_pin < LOW_PIN)
		{
			next_pin = LOW_PIN;
		}
	}
	delay(100);

	digitalWrite(LED_PIN, HIGH);
    delay(100);
	digitalWrite(LED_PIN, LOW);

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
