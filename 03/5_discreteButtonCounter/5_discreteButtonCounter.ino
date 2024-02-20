#include "Button.h"

unsigned long lastTime;

Counter counter;
Button buttons[] = {
    Button(button1_pin, 20, counter),
    Button(button2_pin, 200, counter),
    Button(button3_pin, 2000, counter)
};

void setup() {
    lastTime = millis();

    for (int led : leds)
        pinMode(led, OUTPUT);

    for (Button &button : buttons)
        button.setup();

    counter.onClick();
}

void loop() {
    const unsigned long currentTime = millis();
    const unsigned long deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    for (Button &button : buttons)
        button.update(deltaTime);
}