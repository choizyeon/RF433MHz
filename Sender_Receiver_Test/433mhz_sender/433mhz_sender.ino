//송신기
#include <VirtualWire.h>
 
const int TX_DIO_Pin = 12; // default 12
 
int cnt = 0;
char buf[255];
void setup()
{
  vw_set_tx_pin(TX_DIO_Pin); // Initialize TX pin
  vw_setup(2000); // Transfer speed : 2000 bits per sec
  Serial.begin(9600);
}
 
void loop()
{
  
  sprintf(buf, ">%d", cnt);
  //send("TEST");
  send(buf);
  Serial.println(buf);
  
  delay(1000);

  cnt++;
}
 
void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}


