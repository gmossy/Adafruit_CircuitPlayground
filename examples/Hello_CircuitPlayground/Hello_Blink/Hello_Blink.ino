#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  // Blink the RedLED
  CircuitPlayground.redLED(HIGH);
  delay(500);
  CircuitPlayground.redLED(LOW);
  delay(500);
}
