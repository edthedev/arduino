
# define LED_PIN 13
# define LOW_PIN 3
# define TOP_PIN 12

# define LONG 1000
# define BRIEF 100

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

void all_bar(int high_or_low)
{
	// Change all bar graph LEDs
	for(int pin=LOW_PIN; pin<=TOP_PIN; pin++)
	{
		digitalWrite(pin, high_or_low);
	}
}

void flash_bar()
{
	delay(BRIEF);
	all_bar(LOW);
	delay(BRIEF);
	all_bar(HIGH);
}

void strobe_bar()
{
	// Change all bar graph LEDs
	for(int pin=LOW_PIN; pin<=TOP_PIN; pin++)
	{
		delay(BRIEF);
		digitalWrite(pin, HIGH);
		digitalWrite(pin-1, LOW);
	}
	digitalWrite(TOP_PIN, LOW);
}

void loop()
{
	switch_val = digitalRead(SWITCH);	
	Serial.println(switch_val);

	if(switch_val)
	{

		if(next_pin == TOP_PIN)
		{
			flash_bar();
			flash_bar();
			flash_bar();
			flash_bar();
			strobe_bar();
			next_pin = LOW_PIN;
		}
		
		// Going up...
		digitalWrite(next_pin, HIGH);
		next_pin++;
		if(next_pin > TOP_PIN)
		{
			next_pin = TOP_PIN;
		}
	}
	else
	{
		// Going down...
		digitalWrite(next_pin, LOW);
		next_pin--;
		if(next_pin < LOW_PIN)
		{
			next_pin = LOW_PIN;
		}
	}

	delay(BRIEF);
	digitalWrite(LED_PIN, HIGH);
	delay(BRIEF);
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
