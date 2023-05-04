
#include <LoRa_E22.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 8); 
LoRa_E22 e22ttl(&mySerial);

#define M0 7
#define M1 6


struct Message{
  float Hiz[10];
  float bat[10];
  float bat_ger[10];
  float enerji[10];
}message;

//data myData;

void setup()
{
  Serial.begin(9600);
  pinMode(M0,OUTPUT);
  pinMode(M1,OUTPUT);
  digitalWrite(M0,LOW);
  digitalWrite(M1,LOW);

  e22ttl.begin();
  //delay(500);
}

void loop()
{
  *(float*)(message.Hiz)=6;
  *(float*)(message.bat)=3.3;
  *(float*)(message.bat_ger)=8.0;
  *(float*)(message.enerji)=1.0;

  //delay(100);
  mySerial.listen();
  ResponseStatus rs = e22ttl.sendFixedMessage(0 , 56 , 22 , &message , sizeof(message));
}







