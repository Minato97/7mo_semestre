#include <Servo.h>
Servo servomecatronicos; 
void setup() {
servomecatronicos.attach(9 );   // put your setup code here, to run once:

}

void loop() {
 servomecatronicos.write(0);  // put your main code here, to run repeatedly:
 delay(2000); 
  servomecatronicos.write(90);
  delay(2000); 
   servomecatronicos.write(180);
   delay(2000); 
}
