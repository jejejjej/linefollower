#include <AFMotor.h>

#define irsensL A1
#define irsensR A2

AF_DCMotor motorA(1, MOTOR12_64KHZ);
AF_DCMotor motorB(2, MOTOR12_64KHZ);

void setup() {
  // put your setup code here, to run once:

motorA.setSpeed(200);
motorB.setSpeed(200);

}

void loop() {
  // put your main code here, to run repeatedly:
bool irLstate = false;
bool irRstate = false;

irLstate = digitalRead(irsensL);
irRstate = digitalRead(irsensR);
// if both sensors detect floor FORWARD
if(irLstate == false && irRstate == false){
motorA.run(FORWARD); 
motorB.run(FORWARD); 
delay(100);
}
// if Left sensor senses black line turn right
else if(irLstate == false && irRstate == true){
motorA.run(FORWARD); 
motorB.run(RELEASE); 
delay(100);
}
// if Right sensor senses black line turn left
else if(irLstate == true && irRstate == false){
motorA.run(RELEASE); 
motorB.run(FORWARD); 
delay(100);
}

else if(irLstate == true && irRstate == true){
motorA.run(FORWARD); 
motorB.run(BACKWARD); 
delay(100);
}


}
