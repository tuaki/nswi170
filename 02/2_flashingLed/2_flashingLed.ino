#include <funshield.h>

constexpr int PERIOD = 100; // In milliseconds

void setup() {
    pinMode(led1_pin, OUTPUT);
}

void loop() {
    digitalWrite(led1_pin, ON);
    delay(PERIOD);
    digitalWrite(led1_pin, OFF);
    delay(PERIOD);
}