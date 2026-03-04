#include <funshield.h>

constexpr int PERIOD = 200; // In milliseconds

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

void setup() {
    for (int led : LEDS)
        pinMode(led, OUTPUT);

    setConfiguration(5);
}

void loop() {

}