
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float temp;
int ledPin=5;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("Dallas Temp ic Created");
  sensors.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.print("Req for Temp");
  sensors.requestTemperatures();
//  Serial.println("Done");
  Serial.print("Temp is:");
  temp=sensors.getTempCByIndex(0);
 
  Serial.println(temp);

  if(temp>=27){
    digitalWrite(ledPin,HIGH);
  }else{
    digitalWrite(ledPin,LOW);
  }
}
