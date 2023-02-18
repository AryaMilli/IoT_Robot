#define BLYNK_TEMPLATE_ID "TMPLoLw1jQf8" //Blynk creds arya 
#define BLYNK_DEVICE_NAME "Bot Control"
#define BLYNK_TEMPLATE_NAME "ServoControl"
#define BLYNK_AUTH_TOKEN "_U01qp0mch2XJiFCRh15WF53EHvKuiFf"

//#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> //libraries 
#include <BlynkSimpleEsp8266.h>
#include <Servo.h> //servo library 

#define MA1 14  //motorA pin 1 i2
#define MA2 12  //motorA pin 2 i1
#define MB1 13  //motorB pin 1 i3
#define MB2 15  //motorB pin 2 i4
#define trigpin 5 // ultrasonic output
#define echopin 4 //ultrasonic input 
#define buzzer_pin 2 //buzzer pin 
#define ledpin 1 //LED pin
#define ldr A0 //LDR analog input pin 

int duration,distance; //ultrasonic sensor calculation variables

char ssid[] = "AndroidAPF59A"; //network id 
char pass[] = "candles101"; //network pass 
char auth[ ] = "_U01qp0mch2XJiFCRh15WF53EHvKuiFf"; //authentication 
 
Servo myservo; //declaring Servo pin 
BlynkTimer timer;

int servoPin = 0; //servo pin definition 

void setup() {
  pinMode(MA1, OUTPUT); //motors pins initialise 
  pinMode(MA2,OUTPUT);
  pinMode(MB1,OUTPUT);
  pinMode(MB2,OUTPUT);
  
 // Serial.begin(9600); //baud rate for esp8266
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); //blynk start function initialization 

  myservo.attach(servoPin, 500, 2400); //servo (pin, min, max )
  pinMode(trigpin, OUTPUT); //initialise 
  pinMode(echopin, INPUT);
  
  pinMode(buzzer_pin, OUTPUT);
  pinMode(ledpin, OUTPUT);
  pinMode(ldr, INPUT);

  pinMode(LED_BUILTIN, OUTPUT); //builtin led for code upload 
}

 void loop() {
  
  Blynk.run(); //blynk inbuilt function run 
 // timer.run();

  // Ultrasonic taking input 
  digitalWrite(trigpin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  //ultrasonic distance calculation 
  duration = pulseIn(echopin, HIGH);
  distance= duration*0.034/2;
   myservo.write(0);
  
  if(distance<13){ //if obstacle detected then stop the mtors 
    digitalWrite(MB1,LOW);
    digitalWrite(MA1,LOW);
    digitalWrite(MA2,LOW);
    digitalWrite(MB1,LOW);
    myservo.write(150);
    digitalWrite(buzzer_pin, HIGH);
   }    
  delay(100);
  digitalWrite(buzzer_pin, LOW);
  
  digitalWrite(ledpin, LOW);       //initially LED is OFF
  int ldrreading = analogRead(A0); //ldr analog reading 
  if(ldrreading>80){ //turn on led if ldr reading more than 10
   digitalWrite(ledpin, HIGH);
  }
  digitalWrite(ledpin, LOW);
//  Blynk.virtualWrite(V5, ldrreading);
//  digitalWrite(LED_BUILTIN, LOW);  
//  delay(1000);                      
//  digitalWrite(LED_BUILTIN, HIGH);  
//  delay(2000);
  
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
 }
 else
 {
   // Forward
   digitalWrite(MA1,LOW);
   digitalWrite(MB1,LOW);
   digitalWrite(MA2,LOW);
   digitalWrite(MB2,LOW);
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

 }
 else
 {
   // Stop
   digitalWrite(MA1,LOW);
   digitalWrite(MA2,LOW);
   digitalWrite(MB1,LOW);
   digitalWrite(MB2,LOW);
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
  
 }
 else
 {
   // Stop
   digitalWrite(MA1,LOW);
   digitalWrite(MA2,LOW);
   digitalWrite(MB1,LOW);
   digitalWrite(MB2,LOW);
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
   
 }
 else
 {
// Stop
   digitalWrite(MA1,LOW);
   digitalWrite(MA2,LOW);
   digitalWrite(MB1,LOW);
   digitalWrite(MB2,LOW);
 }
}
