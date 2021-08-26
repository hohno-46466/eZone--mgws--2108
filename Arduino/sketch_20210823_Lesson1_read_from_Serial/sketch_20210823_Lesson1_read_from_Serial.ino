//Button to turn ON/OFF LED

//Constants won't change. They're used here to set pin numbers:
const int buttonPin = 6; // the number of the pushbutton pin
const int ledPin = 4; // the number of the LED pin
const int dummyPin = 5;
// variables will change:

#define MY_KEYWORD  "Hiro765-L1"

int buttonState = 0; // variable for reading the pushbutton status
int prevState = -1;
int cnt = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  // Prepare for dummy PIN to make it GND.
  pinMode(dummyPin, OUTPUT); digitalWrite(dummyPin, LOW);
  //
  Serial.begin(57600);
  delay(1000);
  Serial.println("# Hello!");
  delay(1000);
}

void loop() {
  char keyword[32] = { 0 };
  long timeinfo;
  int val;

  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    char buff[80];
    str.toCharArray(buff, 80);
    Serial.print("# ["); Serial.print(buff); Serial.println("]");
    sscanf(buff, "%s %ld %d", keyword, &timeinfo, &buttonState);
    Serial.print(" ("); Serial.print(keyword); Serial.print(")");
    Serial.print(" ("); Serial.print(timeinfo); Serial.print(")");
    Serial.print(" ("); Serial.print(buttonState); Serial.println(")");
  }
  
  // read the state of the pushbutton value:
  buttonState = buttonState; // | digitalRead(buttonPin);
  // buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (prevState != buttonState) {
    cnt++;
    Serial.print(keyword);    Serial.print("\t");
    Serial.print(timeinfo);   Serial.print("\t");
    if (buttonState == HIGH) {
      // turn LED on:
      Serial.print("HIGH");
      digitalWrite(ledPin, HIGH);
    } else {
      // turn LED off:
      Serial.print("LOW");
      digitalWrite(ledPin, LOW);
    }
    Serial.print("\t");
    Serial.print(millis());
    Serial.print("\t");
    Serial.println(cnt);
    prevState = buttonState;
  }
}
