#define MA1 14  //motorA pin 1
#define MA2 12  //motorA pin 2
#define MB1 13  //motorB pin 1
#define MB2 15  //motorB pin 2

#include <Servo.h> //servo library 
#include <ESP8266WiFi.h> //libraries 

Servo myservo; //declaring Servo pin 

int servoPin = 0; //servo pin definition 

void setup() {
  pinMode(MA1, OUTPUT); //motors pins initialise 
  pinMode(MA2,OUTPUT);
  pinMode(MB1,OUTPUT);
  pinMode(MB2,OUTPUT);
  myservo.attach(servoPin); 
}

void loop(){
  
   digitalWrite(MA1,HIGH);
   digitalWrite(MB1,HIGH);
   digitalWrite(MA2,LOW);
   digitalWrite(MB2,LOW);
   Serial.println("Forward");

   delay(2000);
   
   digitalWrite(MA1,LOW);
   digitalWrite(MA2,HIGH);
   digitalWrite(MB1,LOW);
   digitalWrite(MB2,HIGH);
   Serial.println("Moving Backwards");

   delay(2000);
   
   digitalWrite(MA1,HIGH);
   digitalWrite(MA2,LOW);
   digitalWrite(MB1,LOW);
   digitalWrite(MB2,LOW);
   Serial.println("Moving Left");

   delay(2000);
   
   digitalWrite(MA1,LOW);
   digitalWrite(MA2,LOW);
   digitalWrite(MB1,HIGH);
   digitalWrite(MB2,LOW);
   Serial.println("Moving Right");

   delay(2000);

   myservo.write(90);
   delay(1000);
   myservo.write(0);
   delay(2000);
}
