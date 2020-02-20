
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "JM4B72CjVdpKu0yibwG19igNGTcYr2jC";

// Change below parameters with Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "AndroidShare_9141";
char pass[] = "941a5577c57b";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
