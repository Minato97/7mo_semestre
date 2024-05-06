#include <NewPing.h> 
#define trig 3
#define echo 4  
#define MAX_DISTANCE 200            
NewPing sonar(trig, echo, MAX_DISTANCE); 
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {

   delay(70);
  int cm = sonar.ping_cm();
  /*delay(70);
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;*/
  if(cm==0)
  {
    cm = 250;
  }
  Serial.println(cm);
  

}
