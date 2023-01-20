
/*
 *             XEUX BRAVO
*/
 
//Including the libraries Adafruit
#include <AFMotor.h>

//Defining pins for IR sensors and variables
#define middleSensor A1
#define leftSensor A0
#define rightSensor A2

//Defining motors
AF_DCMotor leftMotor(4, MOTOR12_1KHZ); 
AF_DCMotor rightMotor(1, MOTOR12_1KHZ);

void setup() {
  
  //Declaring pin types
  pinMode(middleSensor,INPUT);  
  pinMode(leftSensor,INPUT);
  pinMode(rightSensor,INPUT);
  
  //begin serial communication
  Serial.begin(9600);
  
}

void loop(){
  
  //Printing values of the sensors to the serial monitor
  Serial.println(digitalRead(middleSensor));
  
  Serial.println(digitalRead(leftSensor));
  
  Serial.println(digitalRead(rightSensor));


  /***  For Black line White surface  ***/    
  //Line detected by both
  if(digitalRead(leftSensor) == 0 && digitalRead(rightSensor) == 0 && !digitalRead(middleSensor) == 0){
    //Forward
    leftMotor.run(FORWARD);
    leftMotor.setSpeed(100);
    rightMotor.run(FORWARD);
    rightMotor.setSpeed(100);
  }
  
  //Line detected by right sensor
  else if(digitalRead(leftSensor) == 0 && !digitalRead(rightSensor) == 0 && !digitalRead(middleSensor) == 0){
    //Turn right
    leftMotor.run(FORWARD);
    leftMotor.setSpeed(100);
    rightMotor.run(BACKWARD);
    rightMotor.setSpeed(130);
  }
  
  //Line detected by left sensor
  else if(!digitalRead(leftSensor) == 0 && digitalRead(rightSensor) == 0 && !digitalRead(middleSensor) == 0){
    //Turn left
    leftMotor.run(BACKWARD);
    leftMotor.setSpeed(130);
    rightMotor.run(FORWARD);
    rightMotor.setSpeed(100);
  }
  
  //line detected by none
  else if(!digitalRead(leftSensor) == 0 && !digitalRead(rightSensor) == 0 && !digitalRead(middleSensor) == 0){
    //Stop
    leftMotor.run(FORWARD);
    leftMotor.setSpeed(100);
    rightMotor.run(FORWARD);
    rightMotor.setSpeed(100);
  }

  /***  For White line Black surface  ***/
  //Line detected by both
  else if(!digitalRead(leftSensor) == 0 && !digitalRead(rightSensor) == 0 && digitalRead(middleSensor) == 0){
    //Forward
    leftMotor.run(FORWARD);
    leftMotor.setSpeed(100);
    rightMotor.run(FORWARD);
    rightMotor.setSpeed(100);
  }
  
  //Line detected by right sensor
  else if(!digitalRead(leftSensor) == 0 && digitalRead(rightSensor) == 0 && digitalRead(middleSensor) == 0){
    //Turn right
    leftMotor.run(FORWARD);
    leftMotor.setSpeed(100);
    rightMotor.run(BACKWARD);
    rightMotor.setSpeed(130);
  }
  
  //Line detected by left sensor
  else if(digitalRead(leftSensor) == 0 && !digitalRead(rightSensor) == 0 && digitalRead(middleSensor) == 0){
    //Turn left
    leftMotor.run(BACKWARD);
    leftMotor.setSpeed(130);
    rightMotor.run(FORWARD);
    rightMotor.setSpeed(100);
  }
  
  //line detected by none
  else if(digitalRead(leftSensor) == 0 && digitalRead(rightSensor) == 0 && digitalRead(middleSensor) == 0){
    //Stop
    leftMotor.run(FORWARD);
    leftMotor.setSpeed(100);
    rightMotor.run(FORWARD);
    rightMotor.setSpeed(100);
  }
}
