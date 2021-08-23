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
  Serial.begin(57600);
}

void loop() {
  static boolean prevStat = false;
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    if (prevStat == false) {
      prevStat = true;
      Serial.println("ON");
    }
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    if (prevStat == true) {
      prevStat = false;
      Serial.println("OFF");
    }
  }
}

