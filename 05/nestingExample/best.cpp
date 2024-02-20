bool checkButton(int currentTime) {
    if (digitalRead(pin) == OFF) {
        wasPressed = false;
        return false;
    }

    if (!wasPressed) {
        wasPressed = true;
        lastTime = currentTime;
        isLooping = false;
        return true;
    }

    int period = isLooping ? SECOND_PERIOD : FIRST_PERIOD;
    if (currentTime - period >= lastTime) {
        lastTime += period;
        isLooping = true;
        return true;
    }
    
    return false;
}