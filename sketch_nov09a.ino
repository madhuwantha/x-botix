#include <EEPROM.h>
#include <QTRSensors.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

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
  pinMode(3, INPUT_PULLUP);    //interrupts 1
  attachInterrupt(0, leftISR, CHANGE);
  attachInterrupt(1, rightISR, CHANGE);




  //delay(200);
  //qtrSave();


  // delay(500) ;

  qtrLoad();

  //setEncoderPID('F');
  setLineFollow( 'V' );

} //end setup

void loop() {
  //checkQTR();
  lineFollow();
  //encoderPID();
  //lineFollow();
  //    ontoT(1);
  //    centerAtJunction();
  //    turnAngle(90);
  //  ontoL(1);





  //digitalWrite(leftMotorForward, HIGH);
  //forward();

  //checkQTR();
  //lineFollow();
 // delay( 1000000000000 );


}
