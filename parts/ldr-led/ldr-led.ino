#define ledpin 1 //LED pin
#define ldr A0 //LDR analog input pin 

void setup(){
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(ldr, INPUT);
}

void loop(){
  digitalWrite(ledpin, LOW);       //initially led off
  int ldrreading = analogRead(A0); //ldr analog reading 
  Serial.print (ldrreading);
  if(ldrreading>10){ //turn on led if ldr reading more than 10
   digitalWrite(ledpin, HIGH);
  }
  digitalWrite(ledpin, LOW);
}
