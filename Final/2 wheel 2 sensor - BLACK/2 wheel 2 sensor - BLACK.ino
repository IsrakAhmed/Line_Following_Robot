
/*
 *             XEUX BRAVO
*/

//Including the libraries Adafruit
#include <AFMotor.h>

//Defining pins for IR sensors and variables
#define leftSensorPin A0
#define rightSensorPin A1

int leftSensor, rightSensor;
int speedF = 100;
int speedB = 100;

//Defining motors
AF_DCMotor leftMotor(4, MOTOR12_1KHZ);
AF_DCMotor rightMotor(1, MOTOR12_1KHZ);

void setup() {
  //Declaring pin types
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
}

void loop() {
  scanSensors();
  /***  For Black line White surface  ***/

  //Line detected by both
  if (leftSensor == 0 && rightSensor == 0) {
    //Forward
    forward();
  }

  //Line detected by right sensor
  if (leftSensor == 0 && rightSensor == 1) {
    //Turn right
    right();
  }

  //Line detected by left sensor
  if (leftSensor == 1 && rightSensor == 0) {
    //Turn left
    left();
  }

  //line detected by none
  if (leftSensor == 1 && rightSensor == 1) {
    //Stop
    /*****/
    forward();
  }
}

void scanSensors() {
  leftSensor = digitalRead(leftSensorPin);
  rightSensor = digitalRead(rightSensorPin);
}

void left() {
  // Turn Left
  leftMotor.run(BACKWARD);
  leftMotor.setSpeed(speedB);
  rightMotor.run(FORWARD);
  rightMotor.setSpeed(speedF);
}

void right() {
  // Turn Right
  leftMotor.run(FORWARD);
  leftMotor.setSpeed(speedF);
  rightMotor.run(BACKWARD);
  rightMotor.setSpeed(speedB);
}

void forward() {
  // Go Straight
  leftMotor.run(FORWARD);
  leftMotor.setSpeed(speedF);
  rightMotor.run(FORWARD);
  rightMotor.setSpeed(speedF);
}

void back() {
  // Go Reverse
  leftMotor.run(BACKWARD);
  leftMotor.setSpeed(speedB);
  rightMotor.run(BACKWARD);
  rightMotor.setSpeed(speedB);
}

void stop() {
  // Stop
  leftMotor.run(RELEASE);
  leftMotor.setSpeed(0);
  rightMotor.run(RELEASE);
  rightMotor.setSpeed(0);
}