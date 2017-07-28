#include <SoftwareSerial.h>

#define ledPin 7
int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(38400); //Default communication rate
}

void loop() {
  if(Serial.available() > 0) { //Checks whether data is 
    state = Serial.read(); //Reads data from serial
  }
  if (state == '0') {
    digitalWrite(ledPin, LOW); //Turn LED OFF
    Serial.println("LED: OFF"); //Send back, to the phone
    state = 0;
  }
  else if (state == '1') {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");;
    state = 0;
  }
}
