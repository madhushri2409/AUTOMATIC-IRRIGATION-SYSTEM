#define BLYNK_TEMPLATE_ID "TMPL3jhdlap2p"
#define BLYNK_TEMPLATE_NAME "IRRIGATION SYSTEM"
#define BLYNK_AUTH_TOKEN "A5fljdB2NKz3SPFyG5RG4loghdhiHx_J"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "A5fljdB2NKz3SPFyG5RG4loghdhiHx_J"; // the auth code that you got on your gmail
char ssid[] = "XXXXXX"; // username or ssid of your WI-FI
char pass[] = "YYYYYYYY"; // password of your Wi-Fi
int water ;
int prevState = 0;


void setup()
{
  Serial.begin(9600);
  pinMode (D3,OUTPUT);
  pinMode (D5,INPUT);
  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{ 
  Blynk.run();

 water=digitalRead(D5);
 Serial.println(water);
  if (water == HIGH && prevState == 0) 
  {
  Serial.println("Pump Started, Water Flowing");    
  digitalWrite(D3,LOW);
  Blynk.logEvent(" Pump Started, Water Flowing");
  prevState = 1;
  millis();    
  }     
  
  else if (water == HIGH && prevState == 1)
  {
  Serial.println("Pump Started, Water Flowing"); 
  Blynk.logEvent("Pump Started, Water Flowing");
  millis();
  }
  else 
  { 
  Serial.println("Pump Stopped, Water Not Flowing");    
  digitalWrite(D3,HIGH);
  Blynk.logEvent("Pump Stopped, Water Not Flowing");
  prevState =0;
  }
  
  
  millis();
}
