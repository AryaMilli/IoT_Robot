const int analogInPin = A0;  // ESP8266 Analog Pin 
const int ledPin = 1;

int sensorValue = 0;  // value read from the pot


void setup() {
  pinMode(analogInPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogInPin); 
  digitalWrite(ledPin, LOW);
  if (sensorValue > 80) {
    digitalWrite(ledPin, HIGH);
  }
  
  delay(500);
}
