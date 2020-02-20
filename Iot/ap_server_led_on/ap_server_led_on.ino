#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


#define STASSID "payam"
#define STAPSK  "12345678"

const char* ssid = STASSID;
const char* password = STAPSK;

const char* apName="Q";
const char* apPassword="12345678";

ESP8266WebServer server(80);

const int led = 4;

void handleRoot() {


  int Speed = server.arg("Speed").toInt();
  analogWrite(led,Speed);
  
  server.send(200, "text/plain", "Your speed is: " + String(Speed));

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
  Serial.begin(9600);
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP(apName,apPassword);
//  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//  Serial.println("");
//  Serial.print("Connected to ");
//  Serial.println(ssid);
//  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());


  server.on("/control", handleRoot);

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  delay(50);
}
