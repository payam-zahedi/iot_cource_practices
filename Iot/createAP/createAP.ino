#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "pouyesh10";
const char *password = "123456789";
ESP8266WebServer server(80);
void handleRoot()
{
  server.send(200, "text/html", "<h1>You are connected</h1>");
  // yek file dorost karde va mohtaviate html ra dar un rikhte
  // sepas file ra ba pawand .h zakhire karde va be onvane ketabkhane ezafe konid
  // sepas motaghayer myweb ke mohtaviat ra be flash mibarad ra dar ghesmat sevom
  // metod send() migozarim
  // cont char myweb[] PROGMEM = R"=====(html)=====";
}

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  Serial.begin(9600);
  Serial.println();
  Serial.print("Configuring access point... ");
  WiFi.softAP(ssid,password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/",handleRoot);
  server.begin();
  Serial.println("HTTP server started");
  

}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  
}
