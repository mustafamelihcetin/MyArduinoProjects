#define digitalPin 3
#define analogPin A0
void setup() {
  pinMode(digitalPin,INPUT);
  pinMode(analogPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(digitalPin)); 
    if(digitalRead(digitalPin) == 1){
    Serial.println("SES TESPİT EDİLDİ.");
    delay(1000);
  }
  Serial.println(analogRead(analogPin));
  Serial.println("----------------------");

}
