#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4); //Addr: 0x3F, 20 chars & 4 lines

void setup()
{
	lcd.init();
	lcd.backlight();
	lcd.setCursor(0, 0);
	lcd.print("Hello");
}
void loop()
{
}

