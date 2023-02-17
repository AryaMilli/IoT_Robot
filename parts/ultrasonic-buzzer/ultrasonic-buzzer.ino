#define trigpin 5 // ultrasonic output
#define echopin 4 //ultrasonic input 
#define buzzer_pin 2 //buzzer pin 

int duration,distance; //ultrasonic sensor calculation variables

void setup(){
  Serial.begin(9600); 
  pinMode(trigpin, OUTPUT); //initialise 
  pinMode(echopin, INPUT);
  pinMode(buzzer_pin, OUTPUT);
}

void loop(){
  // Ultrasonic taking input 
  digitalWrite(trigpin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  //ultrasonic distance calculation 
  duration = pulseIn(echopin, HIGH);
  distance= duration*0.034/2;
  Serial.println(distance);
  delay(100);
  digitalWrite(buzzer_pin, LOW);
  
  if(distance<13){ //if obstacle detected then stop the mtors 
    digitalWrite(buzzer_pin, HIGH);
   }
  
}
