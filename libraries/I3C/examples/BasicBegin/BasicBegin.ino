#include <I3C.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  Serial.println("I3C Basic Begin");

  if (!I3C.begin(1000000)) {
    Serial.println("Failed to initialize I3C bus");
    while (1) {}
  }

  Serial.println("I3C bus initialized at 1 MHz");
}

void loop() {
  delay(1000);
}
