#include "I3C.h"

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  delay(1000);

  Serial.println("=== Target IBI Example ===");

  I3CTargetConfig cfg{};
  cfg.identifier = 0x62;
  cfg.mipiIdentifier = 0x1;
  cfg.ibiRequest = true;
  cfg.ibiPayload = false;

  if (!I3C.beginTarget(I3C_SDA, I3C_SCL, cfg)) {
    Serial.println("beginTarget failed");
    while (1) {}
  }

  while (!I3C.hasAddress()) {
    delay(10);
  }

  Serial.print("DA = 0x");
  Serial.println(I3C.address(), HEX);

  delay(2000);

  int rc = I3C.sendIbi(nullptr, 0, 1000);
  Serial.print("sendIbi rc = ");
  Serial.println(rc);
}

void loop() {
  delay(1000);
}
