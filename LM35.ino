#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x3F, 16, 2);
#define sensor A0
int sensor_deger = 0;
float voltaj = 0.0;
float derece = 0.0;
void setup() {
  pinMode(sensor,INPUT);
  LCD.begin();
  LCD.clear();
  Serial.begin(9600);
}

void loop() {
  LCD.clear();  
  sensor_deger = analogRead(sensor);
  voltaj = sensor * (5000.0/1023.0);
  derece = voltaj/10.0;  
  LCD.setCursor(0,0);
  LCD.print(derece);
  LCD.print(" C'");
  delay(1400);
}
