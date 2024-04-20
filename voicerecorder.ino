#include <SD.h>
#include <SPI.h>

const int chipSelect = 10; // CS pin of the SD card module

void setup() {
  Serial.begin(9600); // Start serial communication for debugging

  // Initialize SD card
  if (!SD.begin(chipSelect)) {
    Serial.println("Error initializing SD card.");
    return;
  }
  Serial.println("SD card initialized.");
}

void loop() {
  // Open a new file for recording
  File audioFile = SD.open("recording.wav", FILE_WRITE);
  if (!audioFile) {
    Serial.println("Error opening file for recording.");
    return;
  }
  Serial.println("Recording...");

  // Record audio for a fixed duration (e.g., 10 seconds)
  unsigned long startTime = millis();
  while (millis() - startTime < 10000) { // Record for 10 seconds
    int audioValue = analogRead(A0); // Read audio input from the microphone module
    audioFile.println(audioValue); // Write audio value to the file
  }

  // Close the file
  audioFile.close();
  Serial.println("Recording finished.");
  delay(1000); // Wait for 1 second before starting the next recording
}
