const int buttonPin = D5;  // Pin connected to the push button
const int relayPin = D6;   // Pin connected to the relay
#define TRIGGER_PIN D2 // GPIO4

void print(const char c[]) {
  Serial.print("D1 Serial: ");
  Serial.println(c);
  
  Serial1.print("D1 Serial 1: ");
  Serial1.println(c);
}


void sendSignalToCam(){
  // Trigger the ESP32-CAM to capture an image
  digitalWrite(TRIGGER_PIN, HIGH);
  delay(500); // wait for the ESP32-CAM to process the image
  digitalWrite(TRIGGER_PIN, LOW);
  print("Signal was sent!");
}


void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);

  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
}

void loop() {
  // Read the state of the push button
  int buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState == HIGH) {
    // If the button is pressed, print "Button Pressed" to the serial output
    print("Button Pressed");

    sendSignalToCam();

    // Activate the relay
    digitalWrite(relayPin, HIGH);
  } else {
    // If the button is not pressed, print "Button Released" to the serial output
    //print("Button Released");

    // Deactivate the relay
    digitalWrite(relayPin, LOW);
  }

  delay(50);
}
