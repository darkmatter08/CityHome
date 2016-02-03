/*
  Servo Demo
    Turns a continous servo at full speed clockwise then
    counter clockwise 
    @author jains
 */

#include <Servo.h>
int servo = 8;
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
    ser.write(90);
    delay(500);
    ser.write(0);
    delay(500);
    ser.write(90);
    delay(500);
    ser.write(180);
    delay(500);
  }
}
