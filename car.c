#define  BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[]="QmfJQCdmPoZzaqoKqz__Z5L6Lndgozfn";
char ssid[]="TNA";
char pass[]="hwwn7hudfh";
#define m11 5
#define m12 4
#define m21 0
#define m22 2
void forward()
{
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);
}
void backward()
{
  digitalWrite(m11,LOW);
  digitalWrite(m12,HIGH);
  digitalWrite(m21,LOW);
  digitalWrite(m22,HIGH);
}
void left()
{
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);
  digitalWrite(m21,LOW);
  digitalWrite(m22,HIGH);
}
void right()
{
  digitalWrite(m11,LOW);
  digitalWrite(m12,HIGH);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);
}

  void stop()
  {
      digitalWrite(m11,LOW);
  digitalWrite(m12,LOW);
  digitalWrite(m21,LOW);
  digitalWrite(m22,LOW);
  }
  void setup()
  {
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
    pinMode(m11, OUTPUT);
    pinMode(m12, OUTPUT);
    pinMode(m21, OUTPUT);
    pinMode(m22, OUTPUT);
  }
  BLYNK_WRITE(V1)
  {
    int x = param[0].asInt();
    int y = param[1].asInt();
     Serial.print("x= ");
     Serial.print(x);
     if(y>220)
     left();
     else if(y<35)
     right();
     else if(x>220)
     forward();
     else if(x<35)
     backward();
     else
     stop();
  }
  void loop()
  {
    Blynk.run();
  }
