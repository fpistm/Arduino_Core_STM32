#include "RobotTest.h"

char readChar[10] = {0};         // a String to hold incoming data

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  while(!Serial){};
  // Begin sync and retry 10 times.
  // Expect to receive: "__Sync:uuid"
  if(RTE.begin(Serial, 10)) {
    Serial.println("Hi STM32duino world!");
  } else {
    Serial.println("Failed to sync!");
  }
}

// the loop routine runs over and over again forever:
void loop() {

}
