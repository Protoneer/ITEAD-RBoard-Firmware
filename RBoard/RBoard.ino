#include "SerialCommand.h"
#include <EEPROM.h>

int relay1 = 4;
int relay2 = 5;
int relay3 = 6;
int relay4 = 7;

SerialCommand SCmd;

void setup() {                
  // Setup Pins
  pinMode(relay1, OUTPUT);     
  pinMode(relay2, OUTPUT);     
  pinMode(relay3, OUTPUT);     
  pinMode(relay4, OUTPUT);

  // Switch all off by default
  switchRelay(1,EEPROM.read(0));
  switchRelay(2,EEPROM.read(1));
  switchRelay(3,EEPROM.read(2));
  switchRelay(4,EEPROM.read(3));

  Serial.begin(9600);

  //setup commands
  SCmd.addCommand("R1=0",R1_0);
  SCmd.addCommand("R1=1",R1_1);
  SCmd.addCommand("R2=0",R2_0);
  SCmd.addCommand("R2=1",R2_1);
  SCmd.addCommand("R3=0",R3_0);
  SCmd.addCommand("R3=1",R3_1);
  SCmd.addCommand("R4=0",R4_0);
  SCmd.addCommand("R4=1",R4_1);
  SCmd.addCommand("CLEARALL",ClearAll);
  SCmd.addCommand("SETALL",SetAll);
    
}

void R1_0(){switchRelay(1,false);Serial.println("OK");}
void R1_1(){switchRelay(1,true);Serial.println("OK");}
void R2_0(){switchRelay(2,false);Serial.println("OK");}
void R2_1(){switchRelay(2,true);Serial.println("OK");}
void R3_0(){switchRelay(3,false);Serial.println("OK");}
void R3_1(){switchRelay(3,true);Serial.println("OK");}
void R4_0(){switchRelay(4,false);Serial.println("OK");}
void R4_1(){switchRelay(4,true);Serial.println("OK");}
void ClearAll()
{
  switchRelay(1,false);
  switchRelay(2,false);
  switchRelay(3,false);
  switchRelay(4,false);
  Serial.println("OK");
}

void SetAll()
{
  switchRelay(1,true);
  switchRelay(2,true);
  switchRelay(3,true);
  switchRelay(4,true);
  Serial.println("OK");
}

void loop() {
  SCmd.readSerial();
}

void switchRelay(int relayNumber, boolean state)
{
  switch(relayNumber)
  {
    case 1 : 
      digitalWrite(relay1, state);
      EEPROM.write(0,state);
      break;
    case 2 : 
      digitalWrite(relay2, state);
      EEPROM.write(1,state);
      break;
    case 3 : 
      digitalWrite(relay3, state);
      EEPROM.write(2,state);
      break;
    case 4 : 
      digitalWrite(relay4, state);
      EEPROM.write(3,state);
      break;
    
  }
}

void ProcessCommand()
{
}
