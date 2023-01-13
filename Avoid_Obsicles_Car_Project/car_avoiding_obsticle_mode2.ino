//libraries
#include <Servo.h>
#include <NewPing.h>
//L298N control pins
const int leftFowrwardmotor=7;
const int leftBackwardmotor=6;
const int rightFowrwardmotor=5;
const int rightBackwardmotor=4;
//sensor pins
#define trigPin A1
#define echoPin A2
#define maxDistance 200
//distances initialization
int distance=100;
int leftDistance=0;
int rightDistance=0;
NewPing sonar(trigPin,echoPin,maxDistance);
Servo servoMotor;
//functions prototypes
int carLookright();
int carLookleft();
int readPing();
void carStop();
void carMoveforward();
void carMovebackward();
void carTurnright();
void carTurnleft();
void setup() {
  //motors setup
  pinMode(leftFowrwardmotor,OUTPUT);
  pinMode(rightFowrwardmotor,OUTPUT);
  pinMode(leftBackwardmotor,OUTPUT);
  pinMode(rightBackwardmotor,OUTPUT);
  //servo motor setup
  servoMotor.attach(10);
  servoMotor.write(115);
  delay(2000);
  //reading the distance
  distance=readPing();
  delay(100);
  distance=readPing();
  delay(100);
  distance=readPing();
  delay(100);
  distance=readPing();
  delay(100);

}

void loop() {
  //it will continue forward until it see an obsticle
  distance=readPing();
  carMoveforward();  
  if(distance<=35)
  {
    //it see an obsticles so it will stop and go backward and then look righ and left to compare the distance of them 
    carStop();
    delay(300);    
    carMovebackward();
    delay(300);
    carStop();
    delay(300);
    leftDistance=carLookleft();
    delay(1000);
    rightDistance=carLookright();
    delay(1000);
    //compare the distance right and left if right is greater and the distance is accecptiable so it will turn right 
    if(rightDistance>leftDistance && rightDistance>=35)
    {
      carTurnright();
      delay(1150);
      carStop();            
    }//else it will turn left if the distance in left is acceptiable
    else if(leftDistance>=35)
    {
      carTurnleft();
      delay(1150);
      carStop();      
    }
    else//if the distance right and left are not acceptable so it will go backward and get the opsite way 
    {
      carMovebackward();
      delay(1000);
      carTurnright();
      delay(2050);        
    }      
 }
}
//this function for looking right
int carLookright()
{
  servoMotor.write(50);
  delay(500);
  int distance=readPing();
  delay(100);
  servoMotor.write(115);
  return distance;      
}
//this function for looking left
int carLookleft()
{
  servoMotor.write(170);
  delay(500);
  int distance=readPing();
  delay(100);
  servoMotor.write(115);
  return distance;
  delay(100);      
}
//this function for reading the signal
int readPing()
{
  int cm=sonar.ping_cm();
  if(cm==0)
  {    
    cm=250;
  }
  return cm;
}
//this function to stop the car
void carStop()
{
  digitalWrite(leftFowrwardmotor,LOW);
  digitalWrite(rightFowrwardmotor,LOW);
  digitalWrite(leftBackwardmotor,LOW);
  digitalWrite(rightBackwardmotor,LOW);  
}
//this function to go forward
void carMoveforward()
{
  digitalWrite(rightBackwardmotor,LOW);
  digitalWrite(rightFowrwardmotor,HIGH);
  digitalWrite(leftFowrwardmotor,LOW);
  digitalWrite(leftBackwardmotor,HIGH);   
}
//this function to go backward
void carMovebackward()
{
  digitalWrite(leftFowrwardmotor,HIGH);
  digitalWrite(leftBackwardmotor,LOW);
  digitalWrite(rightBackwardmotor,HIGH);
  digitalWrite(rightFowrwardmotor,LOW);
    
}
//this function to turn right
void carTurnright()
{
  digitalWrite(leftFowrwardmotor,LOW);
  digitalWrite(leftBackwardmotor,HIGH);
  digitalWrite(rightBackwardmotor,HIGH);
  digitalWrite(rightFowrwardmotor,LOW); 
}
//this function to turn left
void carTurnleft()
{
  digitalWrite(leftFowrwardmotor,HIGH);
  digitalWrite(leftBackwardmotor,LOW);
  digitalWrite(rightBackwardmotor,LOW);
  digitalWrite(rightFowrwardmotor,HIGH); 
}
