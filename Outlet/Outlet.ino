// use this option for OSX:
// use this option for Windows and Linux:
//  char ctrlKey = KEY_LEFT_CTRL;  
//  You must select Keyboard from the Arduino "Tools > USB Type" menu
//
char EnterKey = KEY_ENTER;
int button = 0;
int key = 0;
int signal = 0;
int prime = 0;

int hotPin = 14;
int keyPin = 9;
int buttonPin = 10;
int ledPin = 12; // the on board Teensy LED is on pin 12.

int b1 = 0;
int b2 = 0;
int b3 = 0;

void setup() {

  digitalWrite(4, HIGH);
  Serial.begin(9600);
}

void loop() {
  
  //while (digitalRead(11) == LOW) {
    // do nothing until pin 2 goes low
  //  delay(500);
  //}
  button = digitalRead(1);
  key = digitalRead(keyPin);
  signal =  !key && !button;
  prime =  key && !button;
  digitalWrite(ledPin, !key);
  // digitalWrite(ledPin, signal);
  
  Serial.print("Button: ");
  Serial.print(button);
  Serial.print(" Key: ");
  Serial.print(key);
  Serial.println("");
  if(prime)
  {
    Serial.print("Primed!");
    Keyboard.print("z");
    Keyboard.print("/");
    delay(900);
  }

  if(signal)
  {
    Serial.print("RedButton!");
    Keyboard.print("\n");
	// Keyboard.press(EnterKey);
    delay(900);
  }
  delay(100);
  // new document:
  //delay(100);
  // Keyboard.releaseAll();
  // wait for new window to open:
  //delay(1000);
}
 
