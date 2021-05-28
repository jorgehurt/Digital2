/*  Jorge Rafael Hurtado Garcia
 *  18052
 *  Proyecto Final Digital 2
 *  */
 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "CLARO_6EE204"
#define STAPSK  "495654EFB68s"
//#define STASSID "123456789"
//#define STAPSK  "test1234"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;

ESP8266WebServer server(80);

const int led = 13;

void handleRoot() {
  digitalWrite(led, 1);
  char temp[400];
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;
  uint8_t P[4];
  int CantParqueos = 4;
  int P1= 2;
  int P2= 3;
  int P3= 4;
  int P4= 5;
  if (Serial.available()>0)
  {
    for (int i = 0; i<=3; i++)//se lee 4 bytes y se almacenan en un array
    {
      P[i] = Serial.read(); 
    }
  }
  P1= P[0];
  P2= P[1];
  P3= P[2];
  P4= P[3];
  CantParqueos = P1 + P2 + P3 + P4;
  
  snprintf(temp, 400,

           "<html>\
  <head>\
    <meta http-equiv='refresh' content='5'/>\
    <title>Proyecto Digital 2</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>WebServer de Parqueo - Matic </h1>\
    <h2> Cantidad de Parqueos Disponibles </h2>\
    <p> %d </p>\
    <p>Estado de los Parqueos: P1: %1d P2: %1d P3: %1d P4: %1d    </p>\
    <img>\
  </body>\
</html>",

          CantParqueos, P1, P2, P3, P4
          );
  server.send(200, "text/html", temp);
  digitalWrite(led, 0);
}

void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void) {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  //Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }

  //Serial.println("");
  //Serial.print("Connected to ");
  //Serial.println(ssid);
  //Serial.print("IP address: ");
  //Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    //Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
  server.onNotFound(handleNotFound);
  server.begin();
  //Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
