#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <FS.h>
#ifndef STASSID
#define STASSID "Hotspotty"
#define STAPSK "SuperSecret"
#endif
const char* ssid = STASSID;
const char* password = STAPSK;
ESP8266WebServer server(80); //80 refers to http port (less secure, 443 = https port
const int red = 5;  //D1
const int yellow = 2;  //D4
const int green = 16; //D0
/*
void handleRoot() {
  digitalWrite(red, 0);  //all off at first
  digitalWrite(yellow, 0);
  digitalWrite(green, 0);
  server.send(200, "text/plain", "ok\r\n");
}
*/
void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) { message += " " + server.argName(i) + ": " + server.arg(i) + "\n"; }
  server.send(404, "text/plain", message);
   
}

bool loadFromSPIFFS(String path) {
  String dataType = "text/html";
 
  Serial.print("Requested page -> ");
  Serial.println(path);
  if (SPIFFS.exists(path)){
      File dataFile = SPIFFS.open(path, "r");
      if (!dataFile) {
          handleNotFound();
          return false;
      }
 
      if (server.streamFile(dataFile, dataType) != dataFile.size()) {
        Serial.println("Sent less data than expected!");
      }else{
          Serial.println("Page served!");
      }
 
      dataFile.close();
  }else{
      handleNotFound();
      return false;
  }
  return true;
}
 
 
void handleRoot() {
    loadFromSPIFFS("/Ruth_traffic-light.html");
}
    
void setup(void) {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  digitalWrite(red, 0);
  digitalWrite(yellow, 0);
  digitalWrite(green, 0);

  Serial.begin(115200); //microcontroller sending and computer reading 11520 bits per sec (not simultaneously)
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print(F("Inizializing FS..."));
  if (SPIFFS.begin()){
    Serial.println(F("done."));
  }else{
    Serial.println(F("fail."));
  }
 
  if (MDNS.begin("esp8266")) { Serial.println("MDNS responder started"); } //instead of IP address, can use 'http://esp8266'
  
  server.on("/", handleRoot);  //store URL in the server
  server.on("/green", []() {
  digitalWrite(green, HIGH); //green on
     server.send(200, "text/plain", "green should be on now");
    digitalWrite(red, 0);
    digitalWrite(yellow, 0);
    digitalWrite(green, 1);
  });
 
  server.on("/red", []() {
  //digitalWrite(red, HIGH); //red on
  server.send(200, "text/plain", "red should be on now");
    digitalWrite(red, 1);
    digitalWrite(yellow, 0);
    digitalWrite(green, 0);

  });

    server.on("/yellowON", []() {
  server.send(200, "text/plain", "yellow should be on now");
    digitalWrite(red, 0);
    digitalWrite(yellow, 1);
    digitalWrite(green, 0);

  });
  
      server.on("/yellowOFF", []() {
  server.send(200, "text/plain", "yellow should be off now");
    digitalWrite(red, 0);
    digitalWrite(yellow, 0);
    digitalWrite(green, 0);

  });

  
  

  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
 
}
void loop(void) {
  server.handleClient();  //execute URL 
  MDNS.update();
}
