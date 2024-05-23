#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Initialize LCD and Servo objects
LiquidCrystal_I2C lcdPanel(0x3F, 16, 2);
Servo myServo;

// Define pin constants
const int ledPin = 5;
const int buzzerPin = 6;
const int servoPin = 7;

// Initialize variables
int voltage = 0;
int brightness = 0;

void setup() {
  // Set input and output pins
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(A3, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Attach servo to its pin
  myServo.attach(servoPin);

  // Initialize LCD panel and serial communication
  lcdPanel.begin();
  Serial.begin(9600);
}

void loop() {
  // Adjust brightness based on potentiometer value
  brightness = map(voltage, 0, 5000, 0, 255);

  // Main control structure
  if (digitalRead(3) == HIGH) {
    displayOff();  // Show screen for system OFF state
    delay(600);
  } else {
    digitalWrite(buzzerPin, LOW);
    voltage = analogRead(A3) * (5000.0 / 1023.0);

    // Call servo control function
    trigServo();

    displayOn();  // Show screen for system ON state
    analogWrite(ledPin, brightness);

    // Sound buzzer for high voltage condition
    if (voltage > 4500) {
      soundBuzzer();
    }
    delay(600);
  }
}

void displayOff() {
  // Clear LCD and display system OFF message
  lcdPanel.clear();
  lcdPanel.setCursor(1, 0);
  lcdPanel.print("SYSTEM OFF");
}

void displayOn() {
  // Clear LCD and display system ON message with voltage information
  lcdPanel.clear();
  lcdPanel.setCursor(1, 0);
  lcdPanel.print("SYSTEM ON");
  lcdPanel.setCursor(0, 1);
  lcdPanel.print("Voltage: ");
  lcdPanel.print(voltage);
  lcdPanel.setCursor(13, 1);
  lcdPanel.print(" mV");

  // Additional messages based on voltage condition
  if (voltage == 5000) {
    lcdPanel.setCursor(12, 0);
    lcdPanel.print("MAX!");
  } else if (voltage == 0) {
    lcdPanel.setCursor(12, 0);
    lcdPanel.print("MIN!");
  }
}

void soundBuzzer() {
  // Produce two short beep sounds
  for (int i = 0; i < 2; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);
  }
}

void trigServo() {
  // Read potentiometer value and map it to servo angle
  int servoVal = map(analogRead(A3), 0, 1023, 0, 180);

  // Move the servo to the specified angle
  myServo.write(servoVal);

  delay(15);
}