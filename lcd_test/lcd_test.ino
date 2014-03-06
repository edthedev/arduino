#include <Wire.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


int values[4];
int pin[4];

void setup() {
	lcd.begin(16, 2);

	pinMode(A1, OUTPUT);

	pin[0] = A2;
	pin[1] = A3;
	pin[2] = A4;

    for(int i=0; i<5; i++)
	{
		pinMode(pin[i], INPUT);
	}

}

void loop() {

	digitalWrite(A1, HIGH);
	pinMode(A1, INPUT);

    for(int i=0; i<5; i++)
	{
		lcd.setCursor(i, 0);
		int my_value = digitalRead(pin[i]);
		lcd.print(my_value);
	}
	lcd.setCursor(0, 1);
	lcd.print(millis()/1000);
}
