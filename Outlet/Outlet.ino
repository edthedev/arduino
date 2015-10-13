int v1 = 0;
int v2 = 0;
int v3 = 0;
int on = 0;

void setup() {

  // pinMode(0, OUTPUT);
  // pinMode(1, INPUT);
  pinMode(2, INPUT);
  // pinMode(3, INPUT);
  pinMode(13, OUTPUT);

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
	


  if(v2 == LOW)
  {
	  Serial.print("Pressed Button 2.\n");
	  on = 1;
	  digitalWrite(13, HIGH);
  }
  if(v2 == HIGH)
  {
	  Serial.print("Released Button 2.\n");

  }

  delay(500);
}
 
