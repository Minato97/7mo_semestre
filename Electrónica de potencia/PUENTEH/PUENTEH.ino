
 int pin8 = 8;
  int pin9 =9;
void setup() {
  // put your setup code here, to run once:
 

  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);


  digitalWrite(pin8,LOW);
  digitalWrite(pin9,LOW);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:


  digitalWrite(pin8,HIGH);
  digitalWrite(pin9,LOW);

  delay(2000);

  digitalWrite(pin8,LOW);
  digitalWrite(pin9,LOW);

  delay(2000);

  digitalWrite(pin8,LOW);
  digitalWrite(pin9,HIGH);

  delay(2000);

  digitalWrite(pin8,LOW);
  digitalWrite(pin9,LOW);

  delay(2000);
  
}
