/*
  Control direction of the car via Serial-bluetooth
  @author jains
 */
 
// Pin 13 has an LED connected on most Arduino boards.
int enable = 2;
int h1 = 3;
int h2 = 4;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(enable, OUTPUT);     
  pinMode(h1, OUTPUT);
  pinMode(h2, OUTPUT);
  digitalWrite(enable, HIGH);
  Serial.begin(9600); 
  Serial.println("Enter -1 to move the car backwards, 1 to move the car forwards, 0 to stop it");
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available() > 0) {
    int input = Serial.parseInt();
    if (input == 0) { // stop
      stop();
    } else if (input == 1) { // forwards
      setDir(true);
    } else {
      setDir(false);
    }
  }
}

// Sets the motor direction to be forward if forward is true, 
// backwards otherwise
void setDir(boolean forward) {
  digitalWrite(h1, !forward);
  digitalWrite(h2, forward);
}

void stop(){
  digitalWrite(h1, true);
  digitalWrite(h2, true);
}
