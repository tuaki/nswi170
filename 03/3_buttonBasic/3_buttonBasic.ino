#include <funshield.h>

constexpr int LEDS[] = { LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN };
constexpr int LEDS_SIZE = sizeof(LEDS) / sizeof(LEDS[0]);

void setup() {
    for (int led : LEDS)
        pinMode(led, OUTPUT);

    pinMode(BUTTON1_PIN, INPUT);
    pinMode(BUTTON2_PIN, INPUT);
}

int activeLedIndex = 0;
bool wasButtonPressed = false;

void loop() {
    for (int led : LEDS)
        digitalWrite(led, OFF);

    digitalWrite(LEDS[activeLedIndex], digitalRead(BUTTON1_PIN));

    bool isButtonPressed = digitalRead(BUTTON2_PIN) == ON;
    if (isButtonPressed && !wasButtonPressed)
        activeLedIndex = (activeLedIndex + 1) % LEDS_SIZE;

    wasButtonPressed = isButtonPressed;
}