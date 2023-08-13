//define note frequencies
const float d1 = 36.71;
const float dS1 = 38.89;
const float f1 = 43.65;
const float fS1 = 46.25;
const float g1 = 49.00;
const float aS1 = 58.27;
const float b1 = 61.74;
const float c2 = 65.41;
const float cS2 = 69.30;
const float d2 = 73.42;
const float dS2 = 77.78;
const float e2 = 82.41;
const float f2 = 87.31;
const float fS2 = 92.50;
const float g2 = 98.00;
const float gS2 = 103.82;
const float a2 = 110.00;
const float aS2 = 116.54;
const float b2 = 123.47;
const float c3 = 130.81;
const float cS3 = 138.59;
const float d3 = 146.83;
const float dS3 = 155.56;
const float e3 = 164.81;
const float f3 = 174.61;
const float fS3 = 185.00;
const float g3 = 196.00;
const float gS3 = 207.65;
const float a3 = 220.00;
const float aS3 = 233.08;
const float b3 = 246.94;
const float c4 = 261.63;
const float cS4 = 277.18;
const float d4 = 293.66;
const float dS4 = 311.13;
const float e4 = 329.63;
const float f4 = 349.23;
const float fS4 = 369.99;
const float g4 = 392.00;
const float gS4 = 415.30;
const float a4 = 440.00;
const float aS4 = 466.16;
const float b4 = 493.88;
const float c5 = 523.25;
const float cS5 = 554.37;
const float d5 = 587.33;
const float dS5 = 622.25;
const float e5 = 659.25;
const float f5 = 698.46;
const float fS5 = 739.99;
const float g5 = 783.99;
const float gS5 = 830.61;
const float a5 = 880.00;
const float aS5 = 932.33;
// define notes and durations in arrays
// define notes and durations in arrays
const float notes1[] = { d4, cS4, d4, aS3, dS4, d4, c4, aS3, gS3, dS3, g3, fS3, d4, cS4, d4, aS3, dS4, e4, f4, d4, d4, c4, aS3 };
const float notes2[] = { aS3, a3, aS3, g3, c4, aS3, fS3, g3, c3, c3, aS2, a2, aS3, a3, aS3, g3, aS3, aS3, aS3, f3, dS3, c4, d3 };
// const float notes3[] = { g1, aS2, g3, d4, g3, aS2, g1, a2, g3, cS4, g3, aS2, g1, aS2, g3, d4, g3, aS2, g1, g2, d3, aS3, d3, g2, g1, c3, g3, dS4, g3, c3, g1, aS2, g3, d4, g3, aS2, d1, a2, fS3, c4, fS3, a2, dS1, g2, c3, aS3, dS3, g2, dS1, dS2, c3, aS3, c3, dS2, dS1, c2, a2, dS3, a2, c2, d1, d2, aS2, g3, aS2, d2, d1, d2, a2, fS3, a2, d2, g1, aS2, g3, d4, g3, aS2, g1, a2, g3, cS4, g3, a2, g1, aS2, g3, d4, g3, aS2, g1, g2, d3, aS3, d3, g2, fS1, aS2, fS3, dS4, fS3, aS2, fS1, cS2, aS3, e4, aS3, cS2, f1, d3, aS3, f4, aS4, d3, f1, aS2, d3, d4, d3, aS2, f1, a2, dS3, c4, dS3, a2, aS1, f2, aS2, f3, aS3, f3, aS2, f2, aS1 };
const int durations[] = { 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 1500, 500, 2000 };

// const float duration2[] = { 16667, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 166.67, 111.11, 111.11, 111.11, 111.11, 111.11, 111.11, 111.11, 111.11, 111.11 };

const int numNotes = sizeof(notes1) / sizeof(notes1[0]);

// Define the buzzer pins
const int buzzerPin1 = 10;
const int buzzerPin2 = 9;
const int buzzerPin3 = 8;

void playNote1(float frequency, int duration) {
  tone(buzzerPin1, frequency, duration);
}

void playNote2(float frequency, int duration) {
  int period = 1000000 / frequency;
  int pulseDuration = period / 2;
  int numPulses = frequency * duration / 1000;
  for (int i = 0; i < numPulses; i++) {
    digitalWrite(buzzerPin2, HIGH);
    delayMicroseconds(pulseDuration);
    digitalWrite(buzzerPin2, LOW);
    delayMicroseconds(pulseDuration);
  }
}


void setup() {
  Serial.begin(9600);
  Serial.println(numNotes);
  pinMode(buzzerPin1, OUTPUT);
  pinMode(buzzerPin2, OUTPUT);
  // pinMode(buzzerPin3, OUTPUT);
}

void loop() {
  for (int i = 0; i < numNotes; i++) {
    playNote1(notes1[i], durations[i]);
    playNote2(notes2[i], durations[i]);
    // playNote3(notes3[i], duration2[i]);
  }
}