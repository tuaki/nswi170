#include <funshield.h>
#include "types.h"

constexpr int TIME_TO_STOP = 6900;
Led led(LED1_PIN);

unsigned long lastTime;
Timer timer(TIME_TO_STOP, led);

void setup() {
    lastTime = millis();
    led.setup();
    led.on();
}

void loop() {
    unsigned long currentTime = millis();
    unsigned long deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    timer.update(deltaTime);
}
