#include <ESP8266WiFi.h>;

#include <WiFiClient.h>;

#include <ThingSpeak.h>;

const char* ssid = ""; //Your Network SSID



const char* password = ""; //Your Network Password

int val;

int LDRpin = A0; //LDR Pin Connected at A0 Pin



WiFiClient client;

unsigned long myChannelNumber =  ; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = ""; //Your Write API Key

void setup()

{

Serial.begin(9600);

delay(10);

// Connect to WiFi network

WiFi.begin(ssid, password);



ThingSpeak.begin(client);

}



void loop()

{

val = analogRead(LDRpin); //Read Analog values and Store in val variable

Serial.print(val);//Print on Serial Monitor
Serial.println('\t');
if ( val < 600 )
{
Serial.print(" Sunny Weather");
Serial.println('\n');
} 
else if ( val > 600 && val < 1024)
{
Serial.print( "Cloudy Weather");
Serial.println('\n');
} 
else if ( val == 1024)
{
Serial.print( "No ambient light is detected");
Serial.println('\n');
} 

delay(1000);

ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak



delay(100);

}
