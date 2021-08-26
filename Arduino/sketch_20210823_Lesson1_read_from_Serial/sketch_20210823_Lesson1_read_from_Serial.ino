//Button to turn ON/OFF LED

//Constants won't change. They're used here to set pin numbers:
const int buttonPin = 6; // the number of the pushbutton pin
const int ledPin = 4; // the number of the LED pin
// variables will change:

int buttonState = 0; // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  //
  Serial.begin(57600);
}

void loop() {
  char *keyword;
  long timeinfo;
  int val;
  // read the state of the pushbutton value:
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    sscanf(str.c_str, "%s %d %d", keyword, &timeinfo, &buttonState);
  } else {
    buttonState = 0;
  }

  buttonState = buttonState | digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
