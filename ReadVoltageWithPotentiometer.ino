int deger = 0;
float voltaj = 0.0;
float voltaj2 = 0.0;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);

}

void loop() {
  deger = analogRead(A0);
  voltaj = deger * (5000/1023);
  voltaj2 = voltaj /1000;

  Serial.print("Deger = ");
  Serial.println(deger);

  Serial.print("Voltaj(mv) = ");
  Serial.println(voltaj);
  Serial.println("Voltaj(V) = ");
  Serial.println(voltaj2);
  Serial.println("-------------------");

  delay(500);

}
