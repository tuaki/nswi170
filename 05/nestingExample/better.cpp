bool checkButton(int currentTime)
{
    if (digitalRead(pin) == OFF)
    {
        wasPressed = false;
        return false;
    }

    if (!wasPressed)
    {
        wasPressed = true;
        lastTime = currentTime;
        isLooping = false;
        return true;
    }

    if (currentTime - FIRST_PERIOD > lastTime)
    {
        lastTime += FIRST_PERIOD;
        isLooping = true;
        return true;
    }

    if (currentTime - SECOND_PERIOD >= lastTime && isLooping)
    {
        lastTime += SECOND_PERIOD;
        return true;
    }

    return false;
}