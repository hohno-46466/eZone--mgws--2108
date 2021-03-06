//Rotary controls LED
int rotaryPin = A0; // select the input pin for the rotary
int ledPin = 4; // select the pin for the LED
int rotaryValue = 0; // variable to store the value coming from the rota

void setup() {
 // declare the ledPin as an OUTPUT:
 pinMode(ledPin, OUTPUT);
}

void loop() {
 // read the value from the sensor:
 rotaryValue = analogRead(rotaryPin);
 rotaryValue = map(rotaryValue, 0, 1023, 2000, 0);
 // turn the ledPin on
 digitalWrite(ledPin, HIGH);
 // stop the program for <sensorValue> milliseconds:
 delay(rotaryValue + 100);
 // turn the ledPin off:
 digitalWrite(ledPin, LOW);
 // stop the program for for <sensorValue> milliseconds:
 delay(rotaryValue + 100);
}
