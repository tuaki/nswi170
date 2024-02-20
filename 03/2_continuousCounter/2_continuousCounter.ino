#include <funshield.h>

constexpr int PERIOD = 800; // In milliseconds

constexpr int leds[] = { led1_pin, led2_pin, led3_pin, led4_pin };
constexpr int ledsSize = sizeof(leds) / sizeof(leds[0]);

void setConfiguration(const int* values) {
    for (int i = 0; i < ledsSize; i++)
        digitalWrite(leds[i], values[i] ? ON : OFF);
}

const int* toBinary(int number) {
    static int output[ledsSize];
    for (int i = 0; i < ledsSize; i++) {
        output[i] = number & 1;
        number = number >> 1;
    }
    
    return output;
}

void setConfiguration(int number) {
    setConfiguration(toBinary(number));
}

unsigned long lastTime;
int counter = 1;

void setup() {
    for (int led : leds)
        pinMode(led, OUTPUT);

    lastTime = millis();
    setConfiguration(counter);
}

unsigned long timer = 0;

void loop() {
    unsigned long currentTime = millis();
    timer += currentTime - lastTime;
    lastTime = currentTime;

    if (timer < PERIOD)
        return;

    timer -= PERIOD;

    setConfiguration(counter);
    counter++;
}