#include "funshield.h"

constexpr int DISPLAY_SIZE = 4;

void displayDigit(byte digit, byte pos)
{
  digitalWrite(SEG7_LATCH_PIN, LOW);
  shiftOut(SEG7_DATA_PIN, SEG7_CLOCK_PIN, MSBFIRST, SEG7_DIGIT_GLYPHS[digit % sizeof(SEG7_DIGIT_GLYPHS)]);
  shiftOut(SEG7_DATA_PIN, SEG7_CLOCK_PIN, MSBFIRST, 1 << (DISPLAY_SIZE - 1 - pos));
  digitalWrite(SEG7_LATCH_PIN, HIGH);
}

void setup() {
  pinMode(SEG7_LATCH_PIN, OUTPUT);
  pinMode(SEG7_CLOCK_PIN, OUTPUT);
  pinMode(SEG7_DATA_PIN, OUTPUT);
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
