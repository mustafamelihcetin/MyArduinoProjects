#include <LiquidCrystal_I2C.h>

#define trigPin 8
#define echoPin 7
#define buzzerPin 9
LiquidCrystal_I2C lcdpanel(0x3F, 16, 2);

int butonDurum = 0;
int sure = 0;
float mesafe = 0.0;

const char uyariMesaji[] = "Dikkat: Mesafe kisa! ";

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcdpanel.begin();
  Serial.begin(9600);
}

void loop() {
  lcdTemizle();
  if (digitalRead(3)) {
    mesafe = okuMesafe();
    yazdirMesafe();

    if (mesafe < 20.0) {
      uyarMesafe();
    }
  }
  if (digitalRead(4)) {
    lcdTemizle();
    lcdpanel.setCursor(5, 0);
    lcdpanel.print("Kapali");
  }

  delay(500);
}

float okuMesafe() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(echoPin, HIGH);
  return (sure / 2.0) * 0.0343;
}

void yazdirMesafe() {
  Serial.print("Mesafe: ");
  Serial.println(mesafe);

  lcdpanel.setCursor(0, 0);
  lcdpanel.print("Mesafe: ");
  lcdpanel.print(mesafe);
  lcdpanel.print("cm");
}

void lcdTemizle() {
  lcdpanel.clear();
}

void uyarMesafe() {
  lcdpanel.setCursor(0, 1);

  // Buzzer'ı çalıştır
  buzzerTrig();

  if (strlen(uyariMesaji) > 16) {
    for (int i = 0; i < strlen(uyariMesaji) - 15; i++) {
      lcdpanel.clear();
      yazdirMesafe();
      lcdpanel.setCursor(0, 1);
      lcdpanel.print(uyariMesaji + i);
      delay(200);
    }
  } else {
    lcdpanel.print(uyariMesaji);
  }
}

void buzzerTrig() {
  // Buzzer'ı 1000 ms boyunca çalıştır
  digitalWrite(buzzerPin, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, LOW);
}
