#include <LiquidCrystal_I2C.h>
#include <IRremote.hpp>
LiquidCrystal_I2C LCD(0x3F,16,2);
#define IRpin 3
void setup() {
  pinMode(IRpin,INPUT);
  LCD.begin();
}

void loop() {
  int deger = digitalRead(IRpin);
  LCD.clear();
  LCD.setCursor(2,0);
  LCD.print(deger);
  delay(500);

}
