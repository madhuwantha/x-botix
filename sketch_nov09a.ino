#include <EEPROM.h>
#include <QTRSensors.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Keypad.h>
#include <Wire.h>
#include "Adafruit_TCS34725softi2c.h"

#include "define.h"
void leftISR() //ISR for left motor count
{
  leftCount++;
}

void rightISR() //ISR for right motor count
{
  rightCount++;
}

void  countStart() {
  rightCount = 0;
  leftCount = 0;
}

void setup() {
  Serial.begin(9600);                     //Begin serial communication at 9600 baud rate
  interrupts();                           //turn on interrupts explicitly

  //QTR Sensor ----------------------------------------------------------------------------------------------------
  qtr.setTypeAnalog();                    // configure the QTR sensors
  qtr.setSensorPins((const uint8_t[]) {
    A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15
  }, SensorCount);

  //motor controlling pins---------------
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  //  pinMode(49, OUTPUT);
  //  digitalWrite(49, HIGH);

  pinMode(2, INPUT_PULLUP);    //interrupts 0          //Interrupts assigning for Encoders
  pinMode(19, INPUT_PULLUP);    //interrupts 1
  attachInterrupt(0, leftISR, CHANGE);
  attachInterrupt(4, rightISR, CHANGE);

  //LED pin
  for ( int i = 34; i < 43; i = i + 2 ) {
    pinMode(i, OUTPUT);
  }

  // servo
  leftServo.attach(12);
  rightServo.attach(11);
  baseServo.attach(7);
  leftCatchServo.attach(8);
  rightCatchServo.attach(9);

  // ******************************Color Detection***********************************
  // use these three pins to drive an LED
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);

  if (tcsN.begin()) {
    Serial.println("Found New sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }

  if (tcsO.begin()) {
    Serial.println("Found Old sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }

  // thanks PhilB for this gamma table!
  // it helps convert RGB colors to what humans see
  for (int i = 0; i < 256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;

    if (commonAnode) {
      gammatable[i] = 255 - x;
    } else {
      gammatable[i] = x;
    }
  }


  ServoIntiate();
  keyPad ();
} //end setup

void loop() {
  //for white line
  //lineMode = 0;
//
//  skipTurn();
//
//  turn( 'R' );



  //onToMesh( );
  //encoderMove(100);
  //lineMzaSolve() ;// mesh
  //getSword();

  //  getSword();
  //  turnAngle(180);
  //  skipTurn();
  //  ontoT(1);
  //  putSword();


  //  checkJunctionMaze();
  //  Serial.println( mode );

  //  onToDashLine();
  //  checkQTR();
  //  ontoBreakPoint(1);
  //  encoderMove(200);
  //
  //  setEncoderPID('F');
  //  leftCount = 0;
  //  rightCount = 0;
  //  while (leftCount <= 300 && rightCount <= 300) {
  //    encoderPID();
  //  }
  //  brake('B');

  //turnAngle(180);
  //  onToDashLine();
  //  inDashLine();
  firstRound();

  //lineMzaSolve();






  //  onToDashLine();
  //  inDashLine();
  //  centerAtJunction(T);
  //  turnAngle(-90);
  delay(1000000000000000000);
}
