#define GBKA_LED_PIN  (4)

void setup() {
  pinMode(GBKA_LED_PIN, OUTPUT);
  Serial.begin(57600); // initializes the serial port with a baud rate of 57600
}

void loop() {
  Serial.println("hello, world 2!"); // prints a string to a serial port
  delay(500); //delay of 0.5 second
  digitalWrite(GBKA_LED_PIN, HIGH);
  delay(500); //delay of 0.5 second
  digitalWrite(GBKA_LED_PIN, LOW);
}
