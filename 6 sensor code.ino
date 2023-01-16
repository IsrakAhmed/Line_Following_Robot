
/*
 *             XEUX BRAVO
*/

//Including the libraries Adafruit
#include <AFMotor.h>

//Defining pins for IR sensors and variables
#define leftOne A0
#define leftTwo A1
#define rightThree A2
#define rightFour A3
#define rearFive A4
#define frontSix A5

//Defining motors
AF_DCMotor leftMotor(4, MOTOR12_1KHZ);
AF_DCMotor rightMotor(1, MOTOR12_1KHZ);

int irSensors = B000000;

void setup() {

  //Declaring pin types
  pinMode(leftOne, INPUT);
  pinMode(leftTwo, INPUT);
  pinMode(rightThree, INPUT);
  pinMode(rightFour, INPUT);
  pinMode(rearFive, INPUT);
  pinMode(frontSix, INPUT);

  //begin serial communication
  Serial.begin(9600);
}

void loop() {

  scanSensors();      // Scan the sensor values
  checkConditions();  // Check conditions
}

void checkConditions() {

  switch (irSensors) {

    case B000000:
      //  1
      goSTRAIGHT();
      break;

    case B000001:
      //  2
      stop();
      break;

    case B000010:
      //  3
      stop();
      break;

    case B000011:
      //  4
      stop();
      break;

    case B000100:
      //  5
      stop();
      break;

    case B000101:
      //  6
      stop();
      break;

    case B000110:
      //  7
      stop();
      break;

    case B000111:
      //  8
      stop();
      break;

    case B001000:
      //  9
      stop();
      break;

    case B001001:
      //  10
      stop();
      break;

    case B001010:
      //  11
      stop();
      break;

    case B001011:
      //  12
      stop();
      break;

    case B001100:
      //  13
      stop();
      break;

    case B001101:
      //  14
      stop();
      break;

    case B001110:
      //  15
      stop();
      break;

    case B001111:
      //  16
      stop();
      break;

    case B010000:
      //  17
      stop();
      break;

    case B010001:
      //  18
      stop();
      break;

    case B010010:
      //  19
      stop();
      break;

    case B010011:
      //  20
      stop();
      break;

    case B010100:
      //  21
      stop();
      break;

    case B010101:
      //  22
      stop();
      break;

    case B010110:
      //  23
      stop();
      break;

    case B010111:
      //  24
      stop();
      break;

    case B011000:
      //  25
      stop();
      break;

    case B011001:
      //  26
      stop();
      break;

    case B011010:
      //  27
      stop();
      break;

    case B011011:
      //  28
      stop();
      break;

    case B011100:
      //  29
      stop();
      break;

    case B011101:
      //  30
      stop();
      break;

    case B011110:
      //  31
      stop();
      break;

    case B011111:
      //  32
      stop();
      break;

    case B100000:
      //  33
      stop();
      break;

    case B100001:
      //  34
      stop();
      break;

    case B100010:
      //  35
      stop();
      break;

    case B100011:
      //  36
      stop();
      break;

    case B100100:
      //  37
      stop();
      break;

    case B100101:
      //  38
      stop();
      break;

    case B100110:
      //  39
      stop();
      break;

    case B100111:
      //  40
      stop();
      break;

    case B101000:
      //  41
      stop();
      break;

    case B101001:
      //  42
      stop();
      break;

    case B101010:
      //  43
      stop();
      break;

    case B101011:
      //  44
      stop();
      break;

    case B101100:
      //  45
      stop();
      break;

    case B101101:
      //  46
      stop();
      break;

    case B101110:
      //  47
      stop();
      break;

    case B101111:
      //  48
      stop();
      break;

    case B110000:
      //  49
      stop();
      break;

    case B110001:
      //  50
      stop();
      break;

    case B110010:
      //  51
      stop();
      break;

    case B110011:
      //  52
      stop();
      break;

    case B110100:
      //  53
      stop();
      break;

    case B110101:
      //  54
      stop();
      break;

    case B110110:
      //  55
      stop();
      break;

    case B110111:
      //  56
      stop();
      break;

    case B111000:
      //  57
      stop();
      break;

    case B111001:
      //  58
      stop();
      break;

    case B111010:
      //  59
      stop();
      break;

    case B111011:
      //  60
      stop();
      break;

    case B111100:
      //  61
      stop();
      break;

    case B111101:
      //  62
      stop();
      break;

    case B111110:
      //  63
      stop();
      break;

    case B111111:
      //  64
      goSTRAIGHT();
      break;

    default:
      stop();
  }
}

void scanSensors() {
  // Scan Sensor Values (0 or 1)
  // White = 0 and Black = 1
  bitWrite(irSensors, 0, digitalRead(leftOne));
  bitWrite(irSensors, 1, digitalRead(leftTwo));
  bitWrite(irSensors, 2, digitalRead(rightThree));
  bitWrite(irSensors, 3, digitalRead(rightFour));
  bitWrite(irSensors, 4, digitalRead(rearFive));
  bitWrite(irSensors, 5, digitalRead(frontSix));

  //Printing values of the sensors to the serial monitor
  //Serial.println(irSensors,BIN);

  Serial.print(digitalRead(frontSix));
  Serial.print(digitalRead(rearFive));
  Serial.print(digitalRead(rightFour));
  Serial.print(digitalRead(rightThree));
  Serial.print(digitalRead(leftTwo));
  Serial.println(digitalRead(leftOne));
}

void turnLEFT() {
  // Turn Left
  Serial.print("Turning Left : ");
  leftMotor.run(BACKWARD);
  leftMotor.setSpeed(250);
  rightMotor.run(FORWARD);
  rightMotor.setSpeed(250);
}

void turnRIGHT() {
  // Turn Right
  Serial.print("Turning Right : ");
  leftMotor.run(FORWARD);
  leftMotor.setSpeed(250);
  rightMotor.run(BACKWARD);
  rightMotor.setSpeed(250);
}

void goSTRAIGHT() {
  // Go Straight
  Serial.print("Going Straight : ");
  leftMotor.run(FORWARD);
  leftMotor.setSpeed(250);
  rightMotor.run(FORWARD);
  rightMotor.setSpeed(250);
}

void goREVERSE() {
  // Go Reverse
  Serial.print("Going Reverse : ");
  leftMotor.run(BACKWARD);
  leftMotor.setSpeed(250);
  rightMotor.run(BACKWARD);
  rightMotor.setSpeed(250);
}

void stop() {
  // Go Reverse
  Serial.print("Stopped : ");
  leftMotor.run(RELEASE);
  leftMotor.setSpeed(0);
  rightMotor.run(RELEASE);
  rightMotor.setSpeed(0);
}
