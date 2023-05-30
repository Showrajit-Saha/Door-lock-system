#include <Servo.h>

const int trigPin = 13;
const int echoPin = 10;

long duration;  
long distinCM;

Servo radarServo,myservo;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  radarServo.attach(9);
  myservo.attach(11);
}
void loop() 
{
  long duration,distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;

  
  for(int i=0;i<=180;i++)
  {
    radarServo.write(i);
    delay(2);
    
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distinCM = duration*0.034/2;
    
    Serial.print(i);
    Serial.print("*");
    Serial.print(distinCM);
    Serial.print("#");
    
  }
  
  for(int i=180;i>0;i--)
  {
    radarServo.write(i);
    delay(2);
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distinCM = duration*0.034/2;
   
    Serial.print(i);
    Serial.print("*");
    Serial.print(distinCM);
    Serial.print("#");
   
  }

  if(distance <= 40)
{
   myservo.write(90);
    delay(10);
 
  }
 else
  {
   myservo.write(1);
  }
   
   Serial.print("Distance:");
   Serial.println(distance);
   delay(100);

}
