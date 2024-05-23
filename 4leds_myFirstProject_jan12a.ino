int mLed = 7;
int sLed = 6;
int kLed = 5;
int yLed = 4;

void setup() {
  pinMode(mLed,OUTPUT);
  pinMode(sLed,OUTPUT);
  pinMode(kLed,OUTPUT);
  pinMode(yLed,OUTPUT);

}

void loop() {
  digitalWrite(mLed, HIGH);
  delay(300);
  digitalWrite(sLed, HIGH);
  delay(300);
  digitalWrite(kLed, HIGH);
  delay(300);
  digitalWrite(yLed, HIGH);
  delay(300);
  digitalWrite(mLed, LOW);
  delay(300);
  digitalWrite(sLed, LOW);
  delay(300);
  digitalWrite(kLed, LOW);
  delay(300);
  digitalWrite(yLed, LOW);
  delay(300);

}