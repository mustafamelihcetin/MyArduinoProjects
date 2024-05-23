#define k_led 10
#define m_led 11
#define y_led 12
int deger = 0;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  
  //Ledler
  pinMode(k_led,OUTPUT);
  pinMode(y_led,OUTPUT);
  pinMode(m_led,OUTPUT);
}

void loop() {
  deger = analogRead(A0);

  Serial.print("Deger = ");
  Serial.println(deger);
  if(deger <=250){
    digitalWrite(k_led,1);
    digitalWrite(m_led,0);
    digitalWrite(y_led,0);
  }
  else if(deger <=500 && deger > 250){
    digitalWrite(k_led,0);
    digitalWrite(m_led,1);
    digitalWrite(y_led,0);
  }
  else if(deger <= 1024 && deger > 500){
    digitalWrite(k_led,0);
    digitalWrite(m_led,0);
    digitalWrite(y_led,1);
  }
  else if (deger == 0){
    digitalWrite(k_led,0);
    digitalWrite(m_led,0);
    digitalWrite(y_led,0);
  }
}
