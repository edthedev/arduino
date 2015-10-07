int v1 = 0;
int v2 = 0;
int v3 = 0;

void setup() {

  pinMode(0, OUTPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);

  digitalWrite(0, HIGH);
  Serial.begin(9600);
}

void loop() {
  
  //while (digitalRead(11) == LOW) {
    // do nothing until pin 2 goes low
  //  delay(500);
  //}
  // v1 = digitalRead(1);
  v2 = digitalRead(2);
  // v3 = digitalRead(3);
	
  if(v2 == HIGH)
  {
	  Serial.print("Pressed Button 2.\n");
  }
  if(v2 == LOW)
  {
	  Serial.print("Released Button 2.\n");

  }

 /* 
  Serial.print("Button 1:");
  Serial.print(b1);
  Serial.print("\n");

  Serial.print("Button 2:");
  Serial.print(b2);

  Serial.print("\n");
  Serial.print("Button 3:");

  Serial.print(b3);
  Serial.print("\n");
  */

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
 
