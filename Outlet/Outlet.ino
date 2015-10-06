int b1 = 0;
int b2 = 0;
int b3 = 0;

void setup() {

  // Source for buttons
  digitalWrite(4, HIGH);
  Serial.begin(9600);
}

void loop() {
  
  //while (digitalRead(11) == LOW) {
    // do nothing until pin 2 goes low
  //  delay(500);
  //}
  b1 = digitalRead(0);
  b2 = digitalRead(2);
  b3 = digitalRead(3);
  
  Serial.print("Button 1:");
  Serial.print(b1);
  Serial.print("\n");

  Serial.print("Button 2:");
  Serial.print(b2);

  Serial.print("\n");
  Serial.print("Button 3:");

  Serial.print(b3);
  Serial.print("\n");

  /*
  if(prime)
  {
	  // pass
    Serial.print("Triggered!");
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
  */
  delay(1900);
}
 
