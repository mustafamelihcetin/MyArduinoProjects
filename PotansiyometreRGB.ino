#define greenLed 2
#define redLed 3
#define blueLed 4
#define pot A0
int deger = 0;
void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  deger = analogRead(pot);
  Serial.print("Değer = ");
  Serial.println(deger);
  Serial.println("-------------");
  if (deger > 100) {
    analogWrite(redLed,50);    
  }
  if (deger > 200) {
    analogWrite(redLed,100);    
  }
  if (deger > 400) {
    analogWrite(redLed,150);    
  }
  if (deger > 800) {
    analogWrite(redLed,200);    
  }
  if(deger >1000){
    analogWrite(redLed,255);
  }
}
