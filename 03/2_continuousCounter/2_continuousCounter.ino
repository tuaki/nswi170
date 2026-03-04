#include <funshield.h>

constexpr int PERIOD = 800; // In milliseconds

constexpr int LEDS[] = { LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN };
constexpr int LEDS_SIZE = sizeof(LEDS) / sizeof(LEDS[0]);

void setConfiguration(const int* values) {
    for (int i = 0; i < LEDS_SIZE; i++)
        digitalWrite(LEDS[i], values[i] ? ON : OFF);
}

const int* toBinary(int number) {
    static int output[LEDS_SIZE];
    for (int i = 0; i < LEDS_SIZE; i++) {
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
    for (int led : LEDS)
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