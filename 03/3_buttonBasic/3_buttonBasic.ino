#include <funshield.h>

constexpr int leds[] = { led1_pin, led2_pin, led3_pin, led4_pin };
constexpr int ledsSize = sizeof(leds) / sizeof(leds[0]);

void setup() {
    for (int led : leds)
        pinMode(led, OUTPUT);

    pinMode(button1_pin, INPUT);
    pinMode(button2_pin, INPUT);
}

int activeLedIndex = 0;
bool wasButtonPressed = false;

void loop() {
    for (int led : leds)
        digitalWrite(led, OFF);

    digitalWrite(leds[activeLedIndex], digitalRead(button1_pin));

    bool isButtonPressed = digitalRead(button2_pin) == ON;
    if (isButtonPressed && !wasButtonPressed)
        activeLedIndex = (activeLedIndex + 1) % ledsSize;

    wasButtonPressed = isButtonPressed;
}