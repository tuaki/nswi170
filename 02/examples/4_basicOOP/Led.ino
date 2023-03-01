Led::Led(int pin): pin(pin) {
    
}

void Led::setup() {
    pinMode(pin, OUTPUT);
    off();
}

void Led::on() {
    digitalWrite(pin, ON);
}

void Led::off() {
    digitalWrite(pin, OFF);
}
