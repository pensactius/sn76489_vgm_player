/*

*/
#include "sn76489.h"
#include "VGMPlayer.h"

void setup() {
  Serial.begin(9600);
  SetClock();  
  SetBUS();
  
  SN76489_Off();
  Play();
  SN76489_Off();
}

void loop() {
  
}

