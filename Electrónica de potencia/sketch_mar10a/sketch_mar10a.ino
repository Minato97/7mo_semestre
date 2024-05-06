#include <Servo.h>
Servo servomecatronicos; 
void setup() {
servomecatronicos.attach(2);   // put your setup code here, to run once:
servomecatronicos.write(100);
}

void loop() {
 servomecatronicos.write(20);  // put your main code here, to run repeatedly:
 delay(2000); 
  servomecatronicos.write(100);
  delay(2000); 
   servomecatronicos.write(170);
   delay(2000); 
}
