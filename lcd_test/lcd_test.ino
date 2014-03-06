#include <Wire.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int values[4];
int pin[] = {1,2,3,4,5,6,7,8,9};
int pin_size = sizeof(pin) / sizeof(pin[0]);

void setup() {
	lcd.begin(16, 2);
	// lcd.print('.');
	lcd.print(pin_size);

    // for(int i=0; i < pin_size; i++)
	// {
 	//	pinMode(pin[i], INPUT);
 	//}
	lcd.print('..');
}

void loop() {

	digitalWrite(A1, HIGH);
	pinMode(A1, INPUT);

    for(int i=0; i < pin_size; i++)
	{
		lcd.setCursor(i, 0);
		int my_value = digitalRead(pin[i]);
		lcd.print(my_value);
		lcd.print("A");
	}
	lcd.setCursor(0, 1);
	lcd.print(millis()/1000);
}
