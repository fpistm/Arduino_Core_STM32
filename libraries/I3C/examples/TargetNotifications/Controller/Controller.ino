#include "I3C.h"

static I3CDiscoveredDevice devices[8];

void printHex2(uint8_t v) {
  if (v < 0x10) Serial.print('0');
  Serial.print(v, HEX);
}

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  delay(1000);

  Serial.println("=== Controller Trigger Target Events ===");

  if (!I3C.begin(I3C_SDA, I3C_SCL, 1000000U)) {
    Serial.println("begin() failed");
    while (1) {}
  }

  size_t found = 0;
  int rc = I3C.discover(devices, 8, &found);

  if (rc != 0 || found == 0) {
    Serial.println("No target found");
    while (1) {}
  }

  uint8_t da = devices[0].dynAddr;

  Serial.print("Target DA=0x");
  printHex2(da);
  Serial.println();

  delay(2000);

  rc = I3C.setEvents(da, false, 0x01, 1000);  // DISEC INTR
  Serial.print("DISEC(INTR) rc = ");
  Serial.println(rc);

  delay(5000);

  rc = I3C.setEvents(da, true, 0x01, 1000);  // ENEC INTR
  Serial.print("ENEC(INTR) rc = ");
  Serial.println(rc);
}

void loop() {
  delay(1000);
}
