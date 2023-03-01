Timer::Timer(unsigned long timeToStop, Led& led): timeToStop(timeToStop), led(led) {
    
}

void Timer::update(unsigned long deltaTime) {
    if (stopped)
        return;

    elapsedTime += deltaTime;
    if (elapsedTime < timeToStop)
        return;

    stopped = true;
    led.off();
}
