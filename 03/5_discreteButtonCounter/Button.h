#include <funshield.h>

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

class Function {
public:
    virtual void onClick();
};

class Button {
public:
    Button(int pin, unsigned long bouncePeriod, Function& eventHandler): pin(pin), bouncePeriod(bouncePeriod), eventHandler(eventHandler) {}

    void setup() {
        pinMode(pin, INPUT);
    }

    void update(unsigned long deltaTime) {
        const bool isPressedNow = digitalRead(pin) == ON;
        timeSinceLastIncrement += deltaTime;

        if (!wasPressed && isPressedNow && timeSinceLastIncrement >= bouncePeriod) {
            eventHandler.onClick();
            timeSinceLastIncrement = 0;
        }

        wasPressed = isPressedNow;
    }

private:
    const int pin;
    const unsigned long bouncePeriod;
    unsigned long timeSinceLastIncrement = 0;
    bool wasPressed = false;
    Function& eventHandler;
};

class Counter : public Function {
public:
    void onClick() {
        value++;
        setConfiguration(value);
    }

private:
    int value = 0;
};
