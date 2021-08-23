void setup() {
  Serial.begin(57600); // initializes the serial port with a baud rate of 57600
}

void loop() {
  Serial.println("hello, world"); // prints a string to a serial port
  delay(1000); //delay of 1 second
}
