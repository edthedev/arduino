
# define LED_PIN 13
# define LOW_PIN 3
# define TOP_PIN 12

# define LONG 1000
# define BRIEF 500
# define QUICK 100

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
	delay(QUICK);
	all_bar(LOW);
	delay(BRIEF);
	all_bar(HIGH);
}

void strobe_bar()
{
	// Change all bar graph LEDs
	for(int pin=LOW_PIN; pin<=TOP_PIN; pin++)
	{
		delay(QUICK);
		digitalWrite(pin, HIGH);
		digitalWrite(pin-1, LOW);
	}
	digitalWrite(TOP_PIN, LOW);
}

void show_score_bar(int my_score)
{
	// Display score as a binary gradient...
	for(int pin=LOW_PIN; pin<=TOP_PIN; pin++)
	{
		if(my_score > 0)
		{
			digitalWrite(pin, HIGH);
		}
		my_score--;
	}
	delay(BRIEF);
	all_bar(LOW);
}

int score = 0;

void loop()
{
	switch_val = digitalRead(SWITCH);	
	Serial.println(switch_val);

	if(switch_val)
	{

		// Going up...
		digitalWrite(next_pin, HIGH);

		// Celebrate!!
		if(next_pin == TOP_PIN)
		{
			flash_bar();
			flash_bar();
			flash_bar();
			strobe_bar();
			next_pin = LOW_PIN - 1;
			score++;
			show_score_bar(score);
//TODO: Add some major fireworks when score == max, and then reset score.
		}
		
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

	delay(QUICK);
	digitalWrite(LED_PIN, HIGH);
	delay(QUICK);
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
