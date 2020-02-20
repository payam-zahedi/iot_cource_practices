#define LED 5 //D1(gpio5)
#define BUTTON 4 //D2(gpio4)
int switchState = 0;
int oldSwitchState = 0;
int lightOn = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON,INPUT);
  pinMode(LED,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(BUTTON);
  if(switchState != oldSwitchState)
  {
    oldSwitchState = switchState;
    if(switchState==HIGH)
    {
      lightOn = !lightOn;
    }
  }
  if(lightOn)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }

}
