#include <LiquidCrystal_I2C.h>
#define analogPin A0
#define digitalPin 3
LiquidCrystal_I2C LCD(0x3F, 16, 2);
void setup() {
  pinMode(analogPin, INPUT);
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
  LCD.begin();
}

void loop() {
  int analogDeger = analogRead(analogPin);
  int digitalDeger = digitalRead(digitalPin);
  if (digitalDeger == LOW) {
    Serial.println("Yagmur yagiyor!");
    LCD.clear();
    LCD.setCursor(2, 0);
    LCD.print("Yagmur yagiyor!");
    LCD.setCursor(2, 1);
    LCD.print("DEGER = ");
    LCD.print(analogDeger);
    delay(2000);
  } else {
    LCD.clear();
    LCD.setCursor(2, 0);
    LCD.print("Yagmur yok.");
    delay(500);
  }
  delay(100);


  Serial.println(analogDeger);
  Serial.println(digitalDeger);
}
