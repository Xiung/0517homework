const int analogPin = A0;   // the pin that the potentiometer is attached to
const int ledCount = 10;    // the number of LEDs in the bar graph
int ledPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};   // an array of pin numbers to which LEDs are attached
void setup() {
  // loop over the pin array and set them all to output:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {
  // read the potentiometer:
  int sensorValue = analogRead(A0);
  int sensorReading = analogRead(analogPin); 
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);

  while(ledLevel >= 0 && ledLevel < 5)
  {
    for (int thisLed = 0; thisLed < ledCount; thisLed++)
    {
      int sensorReading = analogRead(analogPin);
      int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);
      int AA = map(ledLevel, 0, 10, 10, 100);
      digitalWrite(ledPins[thisLed], HIGH);
      digitalWrite(ledPins[thisLed+2], LOW);
      delay(AA);
      }
  }

}

