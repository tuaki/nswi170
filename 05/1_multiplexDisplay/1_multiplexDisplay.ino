#include <funshield.h>

unsigned long lastTime;

constexpr int powers[] = { 1, 10, 100, 1000 };

class Counter {
public:
    Counter(int max, int value, bool isFixed) {
        this->max = max;
        this->value = value;
        this->isFixed = isFixed;
    }

    void onClick(int amount = 1) {
        value = (value + (isFixed ? 1 : amount)) % max;
    }

    int getValue() {
        return value;
    }

private:
    int max = 0;
    int value = 0;
    bool isFixed;
};

class Button {
public:
    Button(int pin, unsigned long bouncePeriod, int sign, Counter& eventHandler): pin(pin), bouncePeriod(bouncePeriod), sign(sign), eventHandler(eventHandler) {}

    void setup() {
        pinMode(pin, INPUT);
    }

    void update(unsigned long deltaTime, int amount) {
        const bool isPressedNow = digitalRead(pin) == ON;
        timeSinceLastIncrement += deltaTime;

        if (!wasPressed && isPressedNow && timeSinceLastIncrement >= bouncePeriod) {
            eventHandler.onClick(amount * sign);
            timeSinceLastIncrement = 0;
        }

        wasPressed = isPressedNow;
    }

private:
    const int pin;
    const unsigned long bouncePeriod;
    const int sign;
    unsigned long timeSinceLastIncrement = 0;
    bool wasPressed = false;
    Counter& eventHandler;
};

void displayValue(int value, int positions) {
    shiftOut(data_pin, clock_pin, MSBFIRST, value);
    shiftOut(data_pin, clock_pin, MSBFIRST, positions);
    digitalWrite(latch_pin, LOW);
    digitalWrite(latch_pin, HIGH);
}

constexpr int positionsLength = sizeof(digit_muxpos) / sizeof(digit_muxpos[0]);
void displayDigit(int number, int position) {
    displayValue(digits[number % 10], digit_muxpos[positionsLength - position - 1]);
}

int getDigit(int number, int position) {
    if (position == 0)
        return number;

    int withZeroedLesser = number - (number % powers[position]);
    int withDigitOnLast = withZeroedLesser / powers[position];

    return withDigitOnLast % 10;
}

Counter counter(10000, 1234, false);
Counter position(4, 0, true);

Button buttons[] = {
    Button(button1_pin, 20, 1, counter),
    Button(button2_pin, 20, -1, counter),
    Button(button3_pin, 20, 1, position)
};

void setup() {
    pinMode(latch_pin, OUTPUT);
    pinMode(data_pin, OUTPUT);
    pinMode(clock_pin, OUTPUT);

    lastTime = millis();

    for (Button &button : buttons)
        button.setup();

    for (int i = 0; i < 4; i++) {
        int digit = getDigit(counter.getValue(), position.getValue());
        displayDigit(digit, position.getValue());
        position.onClick();
    }
}

void loop() {
    //displayValue(248, 5);

    const unsigned long currentTime = millis();
    const unsigned long deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    for (Button &button : buttons)
        button.update(deltaTime, powers[position.getValue()]);

    for (int i = 0; i < 4; i++) {
        int digit = getDigit(counter.getValue(), i);
        displayDigit(digit, i);
    }

    delay(2);
}
