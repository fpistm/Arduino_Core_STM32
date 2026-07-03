#include <I3C.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  Serial.println("I3C Device Ready Example");

  if (!I3C.begin(1000000)) {
    Serial.println("Failed to initialize I3C bus");
    while (1) {}
  }

  for (uint8_t addr = 1; addr < 0x7F; ++addr) {

    bool i3cReady = I3C.isI3CDeviceReady(addr);
    if (i3cReady) {
      Serial.print("I3C device at DA 0x");
      Serial.print(addr, HEX);
      Serial.print(": ");
      Serial.println("READY");
    }
  }
}

void loop() {
  delay(1000);
}
