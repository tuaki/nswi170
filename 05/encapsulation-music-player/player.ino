#include "funshield.h"

/**
 * Simple music player that uses vibration patterns to play music. The first
 * number in the pattern is the duration of the first sound. Then the each odd
 * value is the duration of the silence and each even value is the duration of
 * the sound. The pattern is repeated until the player is stopped.
 */
class MusicPlayer {
public:
  MusicPlayer(int pattern[], int patternSize, int pin = beep_pin): pattern(pattern), patternSize(patternSize), pin(pin) { }

  /**
   * Use in setup() to initialize the player
   */    
  void setup() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, OFF);
    
    patternTotalTime = 0;
    for (int i = 0; i < patternSize; ++i) {
      patternTotalTime += pattern[i];
    }
  }

  /**
   * Use in loop() to handle the player and play song
   */
  void handle() {
    if (isPlaying) {
      auto phase = millis() % patternTotalTime;
      bool shouldPlay = false;
      int time = 0, i = 0;
      while (time < phase) {
        time += pattern[i];
        shouldPlay = !shouldPlay;    
        i++; 
      }
      digitalWrite(pin, shouldPlay ? ON : OFF);
    }   
  }

  /**
   * Set the player to play or not. When created, the player is not playing.
   */
  void setPlaying(bool shouldPlay) {
    if (!shouldPlay && isPlaying) {
      digitalWrite(pin, OFF);      
    }
    isPlaying = shouldPlay;
  }

private:
  int* pattern;
  int patternSize;
  int patternTotalTime = 0;
  bool isPlaying = false;
  int pin;
};




int sosPattern[] = {100, 100, 100, 100, 100, 300, 300, 300, 300, 300, 300, 300};
struct MusicPlayer sosSignal(sosPattern, sizeof(sosPattern)/sizeof(sosPattern[0]));

int NocturnePattern[] = {660, 60, 180, 60, 60, 180, 60, 180, 60, 180, 420, 60, 180, 60, 60, 180, 60, 180, 60, 180, 420, 60, 180, 60, 60, 180, 60, 180, 60, 180, 420, 60, 180, 60, 60, 180, 60, 180, 420, 60, 420, 60};
struct MusicPlayer NoctrunePlayer(NocturnePattern, sizeof(NocturnePattern)/sizeof(NocturnePattern[0]));

int BlinkLedPattern[] = {100, 100};
struct MusicPlayer blinker(BlinkLedPattern, 2, led2_pin);

void setup() {
  // Setup players
  sosSignal.setup();
  NoctrunePlayer.setup();
  blinker.setup();

  // Init buttons
  pinMode(button1_pin, INPUT);
  pinMode(button2_pin, INPUT);
  pinMode(button3_pin, INPUT);
}

void loop() {
  // Play songs if active
  sosSignal.handle();
  NoctrunePlayer.handle();
  blinker.handle();

  // Handle buttons 
  sosSignal.setPlaying(!digitalRead(button1_pin));
  NoctrunePlayer.setPlaying(!digitalRead(button2_pin));
  blinker.setPlaying(!digitalRead(button3_pin));
}
