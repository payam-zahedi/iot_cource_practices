#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS); // allow multiple 
DallasTemperature sensors(&oneWire);
float temp;
int ledpin=5;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  sensors.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures();
  Serial.println("Done");
  Serial.print("Temperature is: ");
  temp = sensors.getTempCByIndex(0);
  Serial.println(temp);
  if(temp>=27)
  {
    digitalWrite(ledpin,HIGH);
  }
  else
  {
    digitalWrite(ledpin,LOW);
  }

  delay(1000);

}
