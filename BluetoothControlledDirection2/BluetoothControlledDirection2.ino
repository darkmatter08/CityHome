/*
  Control direction of the car via Serial
  @author jains
 */
 
#include <SoftwareSerial.h>  

int bluetoothTx = 10;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 9;  // RX-I pin of bluetooth mate, Arduino D3

// Pins for H-bridge
int enable = 2;
int h1 = 3;
int h2 = 4;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {                
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  
  // initialize the digital pin as an output.
  pinMode(enable, OUTPUT);     
  pinMode(h1, OUTPUT);
  pinMode(h2, OUTPUT);
  digitalWrite(enable, HIGH);
  bluetooth.begin(9600); 
  bluetooth.println("Enter -1 to move the car backwards, 1 to move the car forwards, 0 to stop it");
}

// the loop routine runs over and over again forever:
void loop() {
  if (bluetooth.available() > 0) {
    int input = bluetooth.parseInt();
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
