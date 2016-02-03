/*
  Light on Serial Read
  
  Control the LED from a serial input
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   
  Serial.begin(9600); 
  Serial.println("Enter 0 to turn off the LED, 1 to turn on the LED");
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available() > 0){
    if (Serial.parseInt() == 0){
      digitalWrite(led, LOW);
      Serial.println("You put 0");
    } else {
      digitalWrite(led, HIGH);
      Serial.println("You put 1");
    } 
  }
}
