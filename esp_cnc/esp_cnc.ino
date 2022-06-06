#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include<SoftwareSerial.h>
//#include <SPI.h>
//SoftwareSerial s(3, 1);

#define pin1 5
#define pin2 4

//const char* ssid = "STUDBME2";
//const char* password = "BME2Stud";

const char* ssid = "Dalia_iphone";
const char* password = "12345678";

//const char* ssid = "Nada";
//const char* password = "mariam_123";

void setup () {

  pinMode (pin1, OUTPUT);
  pinMode (pin2, OUTPUT);
  
//  s.begin(9600);
  Serial.begin(9600);
//  SPI.begin();
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);
    Serial.println("Connecting..");

  }
  Serial.println("Connected to WiFi Network");

}

void loop() {

  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    HTTPClient http;  //Declare an object of class HTTPClient
    WiFiClient client;
    http.begin(client, "http://172.20.10.7:8090/draw_shape"); //Specify request destination
    int httpCode = http.GET(); //Send the request
    //Serial.println(httpCode);

    if (httpCode > 0) { //Check the returning code
      String payload = http.getString(); //Get the request response payload
//      Serial.println(payload);
      Serial.print(payload[1]); //connection bet esp & arduino
//      Serial.println(payload[1]);
      //       char data='f';

      //       //Serial.println(1);
      //Serial.println(payload);
      //Serial.println(1);
      delay(100);
     
    }
    
    delay(100);
    http.end();


  }

  delay(10000);
}
