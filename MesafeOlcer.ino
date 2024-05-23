#include <LiquidCrystal_I2C.h>
#define trigPin 8
#define echoPin 7
LiquidCrystal_I2C lcdpanel(0x3F, 16, 2);
int butonDurum = 0;
#define sensor A0

int sure = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(sensor,INPUT);

  lcdpanel.begin();
  Serial.begin(9600);
}

void loop() {
  //Temizle
  //digitalWrite(trigPin, 0);
  //delayMicroseconds(2);

  // if (digitalRead(3) == true) {
  lcdpanel.clear();
  //Temizle
  digitalWrite(trigPin, 0);
  delayMicroseconds(2);
  //Dalgayı gönder
  digitalWrite(trigPin, 1);
  delayMicroseconds(10);
  digitalWrite(trigPin, 0);
  delayMicroseconds(10);

  sure = pulseIn(echoPin, 1);
  float mesafe = (sure / 2) * 0.0343;
  if (mesafe < 15) {
    digitalWrite(10, 1);
    delay(100);
    digitalWrite(10, 0);
  }
  if (mesafe < 10) {
    digitalWrite(10, 1);
    delay(50);
    digitalWrite(10, 0);
    delay(50);
    digitalWrite(10, 1);
    delay(50);
    digitalWrite(10, 0);
  }
  if (mesafe < 5) {
    digitalWrite(10, 1);
    delay(20);
    digitalWrite(10, 0);
    delay(20);
    digitalWrite(10, 1);
    delay(20);
    digitalWrite(10, 0);
    delay(20);
    digitalWrite(10, 1);
    delay(20);
    digitalWrite(10, 0);
    delay(20);
    digitalWrite(10, 1);
    delay(20);
    digitalWrite(10, 0);
  }
  lcdpanel.setCursor(0, 0);
  lcdpanel.print("Mesafe: ");
  lcdpanel.print(mesafe, 1);
  lcdpanel.print(" cm");

  int sensor_deger = analogRead(A3) ;
  int voltaj = sensor_deger * (5000.0 / 1023.0);
  float derece = voltaj / 10.0;
  Serial.println(voltaj);
  lcdpanel.setCursor(0, 1);
  lcdpanel.print(derece, 1);
  lcdpanel.print(" C'");

  // }
  // if (digitalRead(4) == true) {
  //   lcdpanel.clear();
  //  lcdpanel.setCursor(5, 0);
  //   lcdpanel.print("Kapali");
  //}

  delay(1000);
}
