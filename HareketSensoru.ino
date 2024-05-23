int led_k = 3;
int led_s = 4;
int sensorPin = 7;
int hareket = 0;
void setup() {
  pinMode(led_k, OUTPUT);
  pinMode(led_s, OUTPUT);
  pinMode(A2,INPUT);
  pinMode(sensorPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  hareket = analogRead(A0);
  Serial.println(hareket);
  if(hareket >= 600){
    digitalWrite(led_k,1);
    digitalWrite(led_s,0);
  }
  else{
    digitalWrite(led_s,1);
    digitalWrite(led_k,0);
  }
  delay(1000);
}
