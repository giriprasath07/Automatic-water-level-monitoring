// Pin definitions
const int TRIG_PIN = 5;     // Ultrasonic TRIG
const int ECHO_PIN = 18;    // Ultrasonic ECHO
const int RELAY_PIN = 16;   // Relay control pin

// Distance threshold (in centimeters)
const int RANGE = 50; // Change as per your need

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  
  digitalWrite(RELAY_PIN, HIGH); // Relay OFF initially (active LOW)
}

void loop() {
  // --- Measure distance ---
  long duration;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2; // convert to cm
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // --- Relay control logic ---
  if (distance < RANGE) {
    Serial.println("Object detected → Relay ON");
    digitalWrite(RELAY_PIN, LOW); // ON (active LOW)
  } else {
    Serial.println("No object → Relay OFF");
    digitalWrite(RELAY_PIN, HIGH); // OFF
  }
  
  delay(500); // small delay to avoid rapid switching
}

