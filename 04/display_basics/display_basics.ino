#include "funshield.h"

constexpr int displayDigits = 4;

void displayDigit(byte digit, byte pos)
{
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, digits[digit % sizeof(digits)]);
  shiftOut(data_pin, clock_pin, MSBFIRST, 1 << (displayDigits - 1 - pos));
  digitalWrite(latch_pin, HIGH);
}

void setup() {
  pinMode(latch_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);
}

void loop() {
  displayDigit(1, 0);
  delay(1000);
  displayDigit(2, 1);
  delay(1000);
  displayDigit(3, 2);
  delay(1000);
  displayDigit(4, 3);
  delay(1000);
}
