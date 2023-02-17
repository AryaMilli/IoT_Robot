#define BLYNK_TEMPLATE_ID "TMPLoLw1jQf8" //Blynk creds arya 
#define BLYNK_DEVICE_NAME "Bot Control"
#define BLYNK_TEMPLATE_NAME "ServoControl"
#define BLYNK_AUTH_TOKEN "_U01qp0mch2XJiFCRh15WF53EHvKuiFf"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> //libraries 
#include <BlynkSimpleEsp8266.h>
#include <Servo.h> //servo library 

#define MA1 14  //motorA pin 1
#define MA2 12  //motorA pin 2
#define MB1 13  //motorB pin 1
#define MB2 15  //motorB pin 2

char ssid[] = "AndroidAPF59A"; //network id 
char pass[] = "candles101"; //network pass 
char auth[ ] = "_U01qp0mch2XJiFCRh15WF53EHvKuiFf"; //authentication 
Servo myservo; //declaring Servo pin 

int servoPin = 0; //servo pin definition 

void setup() {
  pinMode(MA1, OUTPUT); //motors pins initialise 
  pinMode(MA2,OUTPUT);
  pinMode(MB1,OUTPUT);
  pinMode(MB2,OUTPUT);
  
  Serial.begin(9600); //baud rate for esp8266
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); //blynk start function initialization 

  myservo.attach(servoPin, 500, 2400);
}

void loop(){
  Blynk.run();
}

BLYNK_WRITE(V1){ //moving forward
 int pinValue = param.asInt();
 if(pinValue==1)
 {
   // Stop
   digitalWrite(MA1,HIGH);
   digitalWrite(MB1,HIGH);
   digitalWrite(MA2,LOW);
   digitalWrite(MB2,LOW);
   Serial.println("Forward");
 }
 else
 {
   // Forward
   digitalWrite(MA1,LOW);
   digitalWrite(MB1,LOW);
   digitalWrite(MA2,LOW);
   digitalWrite(MB2,LOW);
   Serial.println("Stopping ");
 }
}

BLYNK_WRITE(V2){ //moving backward
 int pinValue = param.asInt();
 if(pinValue==1)
 {
  
   digitalWrite(MA1,LOW);
   digitalWrite(MA2,HIGH);
   digitalWrite(MB1,LOW);
   digitalWrite(MB2,HIGH);
   Serial.println("Moving Backwards");

 }
 else
 {
   // Stop
   digitalWrite(MA1,LOW);
   digitalWrite(MA2,LOW);
   digitalWrite(MB1,LOW);
   digitalWrite(MB2,LOW);
   Serial.println("Stopping");
 }
}

BLYNK_WRITE(V3){ //moving left
 int pinValue = param.asInt();
 if(pinValue==1)
 {
  
   // Left
   digitalWrite(MA1,HIGH);
   digitalWrite(MA2,LOW);
   digitalWrite(MB1,LOW);
   digitalWrite(MB2,LOW);
   Serial.println("Moving Left");
  
 }
 else
 {
   // Stop
   digitalWrite(MA1,LOW);
   digitalWrite(MA2,LOW);
   digitalWrite(MB1,LOW);
   digitalWrite(MB2,LOW);
   Serial.println("Stopping");
 }
}

BLYNK_WRITE(V4){ //moving right
 int pinValue = param.asInt();
 if(pinValue==1)
 {
     // Right
   digitalWrite(MA1,LOW);
   digitalWrite(MA2,LOW);
   digitalWrite(MB1,HIGH);
   digitalWrite(MB2,LOW);
   Serial.println("Moving Right");
   
 }
 else
 {
// Stop
   digitalWrite(MA1,LOW);
   digitalWrite(MA2,LOW);
   digitalWrite(MB1,LOW);
   digitalWrite(MB2,LOW);
   Serial.println("Stopping");
 }
}
