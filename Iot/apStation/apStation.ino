#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#define ledpin 5
ESP8266WebServer server(80);
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
  WiFi.mode(WIFI_AP_STA);//both
  WiFi.softAP("pouyesh10","123456789");
  WiFi.begin("AndroidShare_9141","941a5577c57b");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

 Serial.println("");
 Serial.println("WiFi connected to htc");
 Serial.println("IP address is: ");
 Serial.println(WiFi.localIP());
 //http://192.168.4.1/on
 //http://192.168.4.1/off
 server.on("/",helloserver);
 server.on("/on",ledon);
 server.on("/off",ledoff);
 server.onNotFound(notFound);
 server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  delay(50);

}

void ledon()
{
  digitalWrite(ledpin,HIGH);
  server.send(200, "text/html", "<h1>LED IS ON</h1>");
}
void ledoff()
{
  digitalWrite(ledpin,LOW);
  server.send(200, "text/html", "<h1>LED IS OFF</h1>");
}
void helloserver()
{
  server.send(200, "text/html", "<h1>Hello I am esp8266</h1>");
}

void notFound()
{
  server.send(400, "text/html", "<h1>ERROR!</h1>");
}
