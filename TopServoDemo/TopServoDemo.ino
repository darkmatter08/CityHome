/*
  Top Servo Demo
    Turns a continous servo at full speed clockwise then
    counter clockwise 
    @author jains
 */

#include <Servo.h>
int servo = 9;
Servo ser;
int angle = 0;

// the setup routine runs once when you press reset:
void setup() {                
  ser.attach(servo);  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  while(true){
    ser.write(0);
    delay(1000);
    ser.write(70);
    delay(1000);
  }
}
