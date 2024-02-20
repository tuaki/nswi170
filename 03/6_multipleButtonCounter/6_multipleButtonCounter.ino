#include <funshield.h>

constexpr int leds[] = { led1_pin, led2_pin, led3_pin, led4_pin };
constexpr int ledsSize = sizeof(leds) / sizeof(leds[0]);
constexpr int modulo = 1 << ledsSize;

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

constexpr int buttons[] = { button1_pin, button2_pin, button3_pin };
constexpr int buttonsSize = sizeof(buttons) / sizeof(buttons[0]);
constexpr int buttonsIncrements[] = { 1, 15, 5 };
bool wereButtonsPressed[] = { false, false, false };
int counter = 1;

void processButtonOnIndex(int index) {
    if (digitalRead(buttons[index]) == OFF) {
        wereButtonsPressed[index] = false;
        return;
    }

    if (!wereButtonsPressed[index])
        counter = (counter + buttonsIncrements[index]) % modulo;

    wereButtonsPressed[index] = true;
}


void setup() {
    for (int led : leds)
        pinMode(led, OUTPUT);

    for (int button : buttons)
        pinMode(button, INPUT);
}

void loop() {
    for (int i = 0; i < buttonsSize; i++)
        processButtonOnIndex(i);

    setConfiguration(counter);
}