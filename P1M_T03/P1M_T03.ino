#include "p1m_02.hpp"

bool Ena=true; 
int Cnt=0;

void setup() {
  initialize_p1m_02();
  EnableGapsCnt(ENC_L);
  EnableGapsCnt(ENC_R);
  Serial.begin(115200);
}

void loop() {

  /*Gap count test*/
  Serial.print("LGC ");
  Serial.print(GetGapCnt(ENC_L));
  Serial.print(",");

  Serial.print("RGC ");
  Serial.print(GetGapCnt(ENC_R));
  Serial.print(",");
  
  /*Speed Test*/
  Serial.print("speedL ");
  Serial.print(GetSpeed(ENC_L));
  Serial.print(",");

  Serial.print("speedR ");
  Serial.print(GetSpeed(ENC_R));
  Serial.print("\r\n");
  
//  /* Disable test*/
//  if(Ena){
//  Serial.print("Disabled \n\r");  
//    DisableGapsCnt(ENC_L);
//    DisableGapsCnt(ENC_R);
//    Cnt++;
//    if(Cnt == 10){
//      Ena = false;
//      Cnt = 0;
//    }
//  }
//  /* Enable test*/
//  if(!Ena){
  Serial.print("Enabled \n\r");
  EnableGapsCnt(ENC_L);
  EnableGapsCnt(ENC_R);
//  Cnt++;
//  if(Cnt == 10){
//    Ena = true;
//    Cnt = 0;
//  }
//  }
//  delay(500);
}
