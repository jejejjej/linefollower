
//Intinialising motor driver pins of L298N motor driver module
#define EnableA 9//Enable pin A to pin 9~
#define EnableB 10//Enable pin B to pin 10~

#define IN1 2//Motor 1 input pin to pin 2
#define IN2 3//Motor 1 input pin to pin 3
#define IN3 4//Motor 2 input pin to pin 4
#define IN4 5//Motor 2 input pin to pin 5

//Initialising IR sensor pins for line following 

#define IRsensorL 7//Left IR sensor to pin 7
#define IRsensorR 6//Right IR sensor to pin 6


void setup() {
  // put your setup code here, to run once:
//Setting inputs and outputs of arduino uno board

//For L298N motor driver
pinMode(EnableA,OUTPUT);
pinMode(EnableB,OUTPUT);

pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);

//For IR sensors
pinMode(IRsensorL, INPUT);
pinMode(IRsensorR, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int strspeed = 60;
  int tspeed = 100;

  if(digitalRead(IRsensorL) == LOW && digitalRead(IRsensorR) == LOW){

digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);

analogWrite(EnableA, strspeed);
analogWrite(EnableB, strspeed + 10);

  }

  else if(digitalRead(IRsensorL) == HIGH && digitalRead(IRsensorR) == LOW){

digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);

analogWrite(EnableA, tspeed + 155);
analogWrite(EnableB, tspeed - 35);

  }

  else if(digitalRead(IRsensorL) == LOW && digitalRead(IRsensorR) == HIGH){

digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);

analogWrite(EnableA, tspeed - 35);
analogWrite(EnableB, tspeed + 155);

  }

  else if(digitalRead(IRsensorL) == HIGH && digitalRead(IRsensorR) == HIGH){

digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);

analogWrite(EnableA, 0);
analogWrite(EnableB, 0);
  }

}


