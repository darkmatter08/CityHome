/*
  H-Bridge, left side
    Basic demo of H-Bridge capabilities
  @author jains
 */
 
// Pin 13 has an LED connected on most Arduino boards.
int enable = 8;
int h1 = 9;
int h2 = 10;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(enable, OUTPUT);     
  pinMode(h1, OUTPUT);
  pinMode(h2, OUTPUT);
  digitalWrite(enable, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  //digitalWrite(enable, LOW); // disables motor
  digitalWrite(h1, HIGH);
  digitalWrite(h2, LOW);
  delay(1000); 
  digitalWrite(h1, LOW);
  digitalWrite(h2, HIGH);
  delay(1000);
}
