bool checkButton(int currentTime)
{
    if (digitalRead(pin) == ON)
    {
        if (!wasPressed)
        {
            wasPressed = true;
            lastTime = currentTime;
            isLooping = false;
            return true;
        }
        else
        {
            if (currentTime - FIRST_PERIOD > lastTime)
            {
                lastTime += FIRST_PERIOD;
                isLooping = true;
                return true;
            }
            else if (currentTime - SECOND_PERIOD >= lastTime && isLooping)
            {
                lastTime += SECOND_PERIOD;
                return true;
            }
            return false;
        }
    } 
    else
    {
        wasPressed = false;
        return false;
    }
}