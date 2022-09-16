 
 ​#define echopin 2 
 ​#define trigpin 3 
  
 ​long duration; 
 ​int distance; 
  
 ​void setup() {       
 ​  pinMode(trigpin, OUTPUT); 
 ​  pinMode(echopin, INPUT); 
 ​  Serial.begin(9600); 
 ​  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
 ​  Serial.println("with Adruino UNO R3"); 
 ​  } 
  
 ​void loop() { 
 ​  digitalWrite(trigpin, LOW); 
 ​  delayMicroseconds(2); 
  
 ​  digitalWrite(trigpin, HIGH); 
 ​  delayMicroseconds(10); 
  
 ​  digitalWrite(trigpin, LOW); 
 ​  duration=duration*0.034/2; 
  
 ​  Serial.print("Distance: "); 
 ​  Serial.print(distance); 
 ​  Serial.print(" cm"); 
 ​}
