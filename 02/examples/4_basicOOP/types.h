class Led;
class Timer;

class Led {
public:
    Led(int pin);
    void setup();
    void on();
    void off();

private:
    int pin;
};

/**
 * This class represents a timer that automatically turns the led off after a given time has elapsed.
 */
class Timer {
public:
    Timer(unsigned long timeToStop, Led& led);
    void update(unsigned long deltaTime);

private:
    unsigned long timeToStop;
    Led& led;
    unsigned long elapsedTime = 0;
    bool stopped = false;
};
