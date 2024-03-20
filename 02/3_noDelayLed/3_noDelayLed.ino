#include <funshield.h>

constexpr int PERIOD = 100; // In milliseconds

unsigned long lastTime;

void setup() {
    pinMode(led1_pin, OUTPUT);
    lastTime = millis();
}

unsigned long timer = 0;

int currentState = ON;

void loop() {
    unsigned long currentTime = millis();
    timer += currentTime - lastTime;
    lastTime = currentTime;

    if (timer < PERIOD)
        return;

    timer -= PERIOD;
    
    currentState = currentState == ON ? OFF : ON;
    digitalWrite(led1_pin, currentState);
}