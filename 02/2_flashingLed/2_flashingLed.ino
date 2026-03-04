#include <funshield.h>

constexpr int PERIOD = 100; // In milliseconds

void setup() {
    pinMode(LED1_PIN, OUTPUT);
}

void loop() {
    digitalWrite(LED1_PIN, ON);
    delay(PERIOD);
    digitalWrite(LED1_PIN, OFF);
    delay(PERIOD);
}