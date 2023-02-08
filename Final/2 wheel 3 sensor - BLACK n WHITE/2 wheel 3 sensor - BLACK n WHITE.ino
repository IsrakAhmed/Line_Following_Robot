
/*
 *             XEUX BRAVO
*/

//Including the libraries Adafruit
#include <AFMotor.h>

//Defining pins for IR sensors and variables
#define leftSensorPin A1
#define middleSensorPin A4 
#define rightSensorPin A2

int leftSensor, middleSensor, rightSensor;
int speedF = 120;
int speedB = 120;

//Defining motors
AF_DCMotor leftMotor(2, MOTOR12_1KHZ);
AF_DCMotor rightMotor(3, MOTOR12_1KHZ);

void setup() {

  //Declaring pin types
  pinMode(leftSensorPin, INPUT);
  pinMode(middleSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
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
    if (leftSensor == 0 && middleSensor == 0 && rightSensor == 1) {
      //Turn right
      right();
    }

    //Line detected by left sensor
    if (leftSensor == 1 && middleSensor == 0 && rightSensor == 0) {
      //Turn left
      left();
    }

    //line detected by none
    if (leftSensor == 1 && rightSensor == 1) {
      //Stop
      /*****/
      forward();
    }

    /***  For White line Black surface  ***/

    //Line detected by right sensor
    if (leftSensor == 1 && middleSensor == 1 && rightSensor == 0) {
      //Turn right
      right();
    }

    //Line detected by left sensor
    if (leftSensor == 0 && middleSensor == 1 && rightSensor == 1) {
      //Turn left
      left();
    }
}

void scanSensors() {
  leftSensor = digitalRead(leftSensorPin);
  middleSensor = digitalRead(middleSensorPin);
  rightSensor = digitalRead(rightSensorPin);
}

void forward() {
  leftMotor.run(FORWARD);
  leftMotor.setSpeed(speedF);
  rightMotor.run(FORWARD);
  rightMotor.setSpeed(speedF);
}

void left() {
  leftMotor.run(BACKWARD);
  leftMotor.setSpeed(speedB);
  rightMotor.run(FORWARD);
  rightMotor.setSpeed(speedF);
}

void right() {
  leftMotor.run(FORWARD);
  leftMotor.setSpeed(speedF);
  rightMotor.run(BACKWARD);
  rightMotor.setSpeed(speedB);
}

void stop() {
  leftMotor.run(FORWARD);
  leftMotor.setSpeed(0);
  rightMotor.run(BACKWARD);
  rightMotor.setSpeed(0);
}

void back() {
  // Go Reverse
  leftMotor.run(BACKWARD);
  leftMotor.setSpeed(speedB);
  rightMotor.run(BACKWARD);
  rightMotor.setSpeed(speedB);
}
