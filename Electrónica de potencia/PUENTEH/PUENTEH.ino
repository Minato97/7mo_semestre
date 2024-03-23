
 int pin8 = 8;
  int pin9 =9;
  int pin10 = 10;
  int pin12 = 12;
  #include <Servo.h>
Servo servomecatronicos; 
void setup() {
  // put your setup code here, to run once:
 
servomecatronicos.attach(11); 
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin12, OUTPUT);

  digitalWrite(pin8,LOW);
  digitalWrite(pin9,LOW);
  digitalWrite(pin10,LOW);
  digitalWrite(pin12,LOW);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Enciende foco
  digitalWrite(pin10,HIGH);
  delay(4000);
  //Apaga foco
  digitalWrite(pin10,LOW);
  delay(1000);

  //Enciende la alimentación del motor
  digitalWrite(pin8,HIGH);
  delay(100);

  //Manda pulso al triac
  digitalWrite(pin9,HIGH);
  delay(100);
  digitalWrite(pin9,LOW);
  delay(2000);

  //Apaga el motor
  digitalWrite(pin8,LOW);
  delay(100);

  //Enciende el servo
  digitalWrite(pin12,HIGH);
  delay(100);
  digitalWrite(pin12,LOW);
  delay(100);
  
  servomecatronicos.write(0);  // put your main code here, to run repeatedly:
 delay(2000); 
  servomecatronicos.write(180);
  delay(2000); 
   servomecatronicos.write(0);
   delay(2000); 
   servomecatronicos.write(180);
   delay(2000); 

  
}
