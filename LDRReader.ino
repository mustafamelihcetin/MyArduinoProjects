#define k_led 10
#define m_led 11
#define y_led 12
int ldrDeger = 0;
void setup() {
  pinMode(A5,INPUT);
  pinMode(k_led,OUTPUT);
  pinMode(m_led,OUTPUT);
  pinMode(y_led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrDeger = analogRead(A5);
  Serial.print("Deger = ");
  Serial.println(ldrDeger);

  if(ldrDeger < 185){
    digitalWrite(k_led,1);
    digitalWrite(m_led,1);
    digitalWrite(y_led,1);
  }
  
  else if(ldrDeger>186 && ldrDeger<380){
    digitalWrite(k_led,1);
    digitalWrite(m_led,1);
    digitalWrite(y_led,0);
  }
  else if(ldrDeger>381 && ldrDeger<750){
    digitalWrite(k_led,1);
    digitalWrite(m_led,0);
    digitalWrite(y_led,0);
  }
  
  else if(ldrDeger>751){
    digitalWrite(k_led,0);
    digitalWrite(m_led,0);
    digitalWrite(y_led,0);
  }



  delay(750);
}
