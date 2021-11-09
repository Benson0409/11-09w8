#include "pitches.h"

int freq = 2000;
int channel = 0;
int resolution = 10;

int tonePin = 12;

int melody[] = {
   NOTE_D3, NOTE_A3, NOTE_D3, NOTE_E3, NOTE_D3, 0, NOTE_D3, NOTE_F3,NOTE_E3
};
int noteDurations[] = {
  8, 8, 8, 8,8,4,4,4,8
};

void setup() {
  Serial.begin(115200);
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(tonePin, channel);

}

void loop() {
    for (int thisNote = 0; thisNote < 42; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      ledcWriteTone(channel, melody[thisNote]);
      delay(noteDuration);
      ledcWriteTone(channel, 0);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
}
