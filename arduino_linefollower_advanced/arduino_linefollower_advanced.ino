#include <AFMotor.h>

#define irsensLA A0
#define irsensLB A1
#define irsensLC A2
#define irsensLD A3

#define irsensRA A4
#define irsensRB A5
#define irsensRC 9
#define irsensRD 10

AF_DCMotor motorA(1, MOTOR12_64KHZ);
AF_DCMotor motorB(2, MOTOR12_64KHZ);

int time = 100;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
// sets the state of ir sensor values low
bool irLAstate = false;
bool irLBstate = false;
bool irLCstate = false;
bool irLDstate = false;

bool irRAstate = false;
bool irRBstate = false;
bool irRCstate = false;
bool irRDstate = false;

// reads the digital signal from line array sensor
irLAstate = digitalRead(irsensLA);
irLBstate = digitalRead(irsensLB);
irLCstate = digitalRead(irsensLC);
irLDstate = digitalRead(irsensLD);// left sensors

irRAstate = digitalRead(irsensRA);
irRBstate = digitalRead(irsensRB);
irRCstate = digitalRead(irsensRC);
irRDstate = digitalRead(irsensRD);// right sensors

//if the two middle sensors detect black line
if(irLDstate == true && irLCstate == true && irLBstate == true && irLAstate == false && irRAstate == false && irRBstate == true && irRCstate == true && irRDstate == true){
  motorA.setSpeed(200);
  motorB.setSpeed(200);
  motorA.run(FORWARD); 
  motorB.run(FORWARD); 
  delay(time);
}
//if the two first left sensors detect black line turn sightly right
else if(irLDstate == true && irLCstate == true && irLBstate == false && irLAstate == false && irRAstate == true && irRBstate == true && irRCstate == true && irRDstate == true){
  motorA.setSpeed(150);
  motorB.setSpeed(170);
  motorA.run(FORWARD); 
  motorB.run(FORWARD); 
  delay(time);
}
//if the two first right sensors detect black line turn sightly left
else if(irLDstate == true && irLCstate == true && irLBstate == true && irLAstate == true && irRAstate == false && irRBstate == false && irRCstate == true && irRDstate == true){
  motorA.setSpeed(170);
  motorB.setSpeed(150);
  motorA.run(FORWARD); 
  motorB.run(FORWARD); 
  delay(time);
}
//if the two 2nd left sensors detect black line turn sightly more right
else if(irLDstate == true && irLCstate == false && irLBstate == false && irLAstate == true && irRAstate == true && irRBstate == true && irRCstate == true && irRDstate == true){
  motorA.setSpeed(150);
  motorB.setSpeed(200);
  motorA.run(FORWARD); 
  motorB.run(FORWARD); 
  delay(time);
}
//if the two 2nd right sensors detect black line turn sightly more left
else if(irLDstate == true && irLCstate == true && irLBstate == true && irLAstate == true && irRAstate == true && irRBstate == false && irRCstate == false && irRDstate == true){
  motorA.setSpeed(200);
  motorB.setSpeed(150);
  motorA.run(FORWARD); 
  motorB.run(FORWARD); 
  delay(time);
}
//if the two 2nd left sensors detect black line turn right
else if(irLDstate == true && irLCstate == false && irLBstate == false && irLAstate == true && irRAstate == true && irRBstate == true && irRCstate == true && irRDstate == true){
  motorA.setSpeed(100);
  motorB.setSpeed(200);
  motorA.run(FORWARD); 
  motorB.run(FORWARD); 
  delay(time);
}
//if the two 2nd right sensors detect black line turn left
else if(irLDstate == true && irLCstate == true && irLBstate == true && irLAstate == true && irRAstate == true && irRBstate == false && irRCstate == false && irRDstate == true){
  motorA.setSpeed(200);
  motorB.setSpeed(100);
  motorA.run(FORWARD); 
  motorB.run(FORWARD); 
  delay(time);
}
//if the two 2nd left sensors detect black line turn more right
else if(irLDstate == false && irLCstate == false && irLBstate == true && irLAstate == true && irRAstate == true && irRBstate == true && irRCstate == true && irRDstate == true){
  motorA.setSpeed(50);
  motorB.setSpeed(200);
  motorA.run(FORWARD); 
  motorB.run(FORWARD); 
  delay(time);
}
//if the two 2nd right sensors detect black line turn more left
else if(irLDstate == true && irLCstate == true && irLBstate == true && irLAstate == true && irRAstate == true && irRBstate == true && irRCstate == false && irRDstate == false){
  motorA.setSpeed(200);
  motorB.setSpeed(50);
  motorA.run(FORWARD); 
  motorB.run(FORWARD); 
  delay(time);
}
//if the sensors don't detect black line turn right in place to search
else if(irLDstate == true && irLCstate == true && irLBstate == true && irLAstate == true && irRAstate == true && irRBstate == true && irRCstate == true && irRDstate == true){
  motorA.setSpeed(200);
  motorB.setSpeed(200);
  motorA.run(FORWARD); 
  motorB.run(BACKWARD); 
  delay(time);
}

}
