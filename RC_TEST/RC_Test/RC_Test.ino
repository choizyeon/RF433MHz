/*
  Simple example for receiving
  
  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (mySwitch.available()) {
    unsigned long aa = mySwitch.getReceivedValue();
    
    Serial.print("Received ");
    Serial.print(aa );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.print( mySwitch.getReceivedProtocol() );
    
    if(aa==15941585)//16337
    {
      Serial.println("----------A----------");
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(aa==15941586)//16337
    {
      Serial.println("----------B----------");
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(aa==15941588)//16337
    {
      Serial.println("----------C----------");
    }
    else if(aa==15941592)//16337
    {
      Serial.println("----------D----------");
    }
    mySwitch.resetAvailable();
  }
}
