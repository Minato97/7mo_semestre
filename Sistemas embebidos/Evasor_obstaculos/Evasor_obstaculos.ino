#include <NewPing.h>                // SE DEFINE AL SENSOR ULTRASONICO 
#include <Servo.h>                  // SE DEFINE AL SERVOMOTOR. 

#define trig 3
#define echo 4                   // SE DEFINE EL SENSOR ULTRASONICO, ECHO VA AL PIN A1 ARDUINO UNO.
#define MAX_DISTANCE 200            
NewPing sonar(trig, echo, MAX_DISTANCE); 
Servo myservo;   

int VelocidadMotor1 = 6; 
int VelocidadMotor2 = 5;

int Motor1A = 13; //ADELANTE
int Motor1B = 12;  
int Motor2C = 11; //adelante
int Motor2D = 10; 


boolean goesForward=false;         
int referencia = 100;               
int speedSet = 0;               

void setup() {
  Serial.begin(9600);
  myservo.attach(2);
  /*myservo.write(20);  // put your main code here, to run repeatedly:
  delay(500); */
  myservo.write(100);
  delay(500); 
   /*myservo.write(170);
   delay(500); 
   myservo.write(100);*/


   pinMode(Motor1A,OUTPUT);
  pinMode(Motor1B,OUTPUT);
  pinMode(Motor2C,OUTPUT);
  pinMode(Motor2D,OUTPUT);
  pinMode(VelocidadMotor1, OUTPUT);
  pinMode(VelocidadMotor2, OUTPUT);

   analogWrite(VelocidadMotor1, 150); 
  analogWrite(VelocidadMotor2, 150);


    digitalWrite(Motor1A, LOW);
  digitalWrite(Motor1B, LOW);
  digitalWrite(Motor2C, LOW);
  digitalWrite(Motor2D, LOW);


  referencia = distance();
  delay(100);
  Serial.println(referencia);
 /* referencia = distance();
  delay(100);
  referencia = distance();
  delay(100);
  referencia = distance();
  delay(100);*/
  
}

void loop() {


 int distanceR = 0;
 int distanceL =  0;
 delay(40);
 //Serial.println(referencia);
 //delay(100);
 if(referencia<=25)                //SE ACTIVA EL SENSOR ULTRASONICO CUANDO DETECTA OBSTACULOS A MENOS DE 15CM.
 {
  moveStop();                   
  delay(200);                   
  moveBackward();              //EL CARRITO SE DETIENE Y SE VA HACIA ATRAS POR 800 MILISEGUNDOS.
  delay(800);                      
  
  moveStop();
  delay(200);
  distanceR = lookRight();       
  delay(200);
  distanceL = lookLeft();         
  delay(200);

  if(distanceR>=distanceL)
  {
    turnRight();
    delay(500);
    moveForward();           
    moveStop();
  }
  
      else
      
  {
    turnLeft();
    delay(500);
     moveForward();            
    moveStop();
  }
  
 }else   
                        
 {
  moveForward();         
 }
 referencia = distance();
 //Serial.println(referencia);
}

int lookRight()          
{
    myservo.write(0);    
    delay(500);
    int referencia = distance();
    delay(100);
    myservo.write(100);        
    return referencia;
}

int lookLeft()
{
    myservo.write(180); 
    delay(500);
    int referencia = distance();
    delay(100);
    myservo.write(100); 
    return referencia;
    delay(100);
}


long distance () {
 /*  delay(70);
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  return cm;*/
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
   digitalWrite(Motor1A, LOW);
    digitalWrite(Motor1B, LOW);
    digitalWrite(Motor2C, LOW);
    digitalWrite(Motor2D, LOW);
  } 
  
void moveForward() {        //CARRITO AVANZA

  
    digitalWrite(Motor1A, HIGH);
  digitalWrite(Motor1B, LOW);
  digitalWrite(Motor2C, HIGH);
  digitalWrite(Motor2D, LOW);

  
 /*digitalWrite(Motor1A, HIGH);
    digitalWrite(Motor2C, HIGH);
    delay(20);                      
    digitalWrite(Motor1A, LOW);
    digitalWrite(Motor2C,LOW);
    delay(20); */
  
}

void moveBackward() {        //HACIA ATRAS

    digitalWrite(Motor1A, LOW);
  digitalWrite(Motor1B, HIGH);
  digitalWrite(Motor2C, LOW);
  digitalWrite(Motor2D, HIGH);
    /*
   digitalWrite(Motor1B, HIGH);
    digitalWrite(Motor2D, HIGH);
    delay(20);                      
    digitalWrite(Motor1B, LOW);
    digitalWrite(Motor2D,LOW);
    delay(20);  */    
  
}  

void turnRight() {     //GIRA A LA DERECHA Y AVANZA
  /*
 digitalWrite(Motor1A,HIGH);
    digitalWrite(Motor2D, HIGH);
    delay(200);
    /*digitalWrite(Motor1A,LOW);
    digitalWrite(Motor2D, LOW );
    delay(20);*/
  digitalWrite(Motor1A, HIGH);
  digitalWrite(Motor1B, LOW);
  digitalWrite(Motor2C, LOW);
  digitalWrite(Motor2D, HIGH);
 /* delay(300);
  moveForward(); */     
  
} 
 
void turnLeft() {           //GIRA A LA IZQUIERDA Y AVANZA

    digitalWrite(Motor1A, LOW);
  digitalWrite(Motor1B, HIGH);
  digitalWrite(Motor2C, HIGH);
  digitalWrite(Motor2D, LOW);
   /* digitalWrite(Motor1B, HIGH);
    digitalWrite(Motor2C,HIGH);
    delay(25);
    digitalWrite(Motor1B, LOW);
    digitalWrite(Motor2C,LOW);
    delay(20);*/
   delay(300);
  moveForward();  
  
}  

/*int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}*/
