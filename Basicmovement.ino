void lineFollowMove(int count)
{
  leftCount = 0;
  rightCount = 0;

  setLineFollow('E');

  while (leftCount <= count && rightCount <= count) lineFollow();
  brake();
}

void centerAtJunction() {
  encoderMove( 210 );
}

void encoderMove(int count)
{
  leftCount = 0;
  rightCount = 0;

  if (count > 0) forward();
  else backward();

  setEncoderPID('F');

  while (leftCount <= abs(count) && rightCount <= abs(count)) encoderPID();
  brake();
}

void leaveSquare()
{
  //Leaving starting   zone --------------------------------
  setEncoderPID('S');
  forward();
  qtrRead();
  while ( dval[0] || dval[15])      //16-qtr - 1
  {
    encoderPID();
    qtrRead();
  }
  brake();
  ontoLine(100);
}

void enterSquare()
{
  ontoT(0);
  encoderMove(500);   //change - 6    center for end squre
}

//Coming to the juction and take a turn -------------------------------------------------------------------

void turn(char input) //Explicit turnings
{
  setLineFollow(manner);
  switch (input)
  {
    case 'L': //Go forward and Turn Left
      while (1)
      {
        qtrRead();
        if (dval[15] && dval[14])      //16-qtr - 6
        {
          encoderMove(junctionCount);
          turnAngle(-90);
          break;
        }
        else lineFollow();
      }
      break;

    case 'R': //Go forward and turn right
      while (1)
      {
        qtrRead();
        if (dval[0] && dval[1])      //16-qtr - 2
        {
          encoderMove(junctionCount);
          turnAngle(90);
          break;
        }
        else lineFollow();
      }
      break;

    case 'B': //turn back
      turnAngle(180);
      //ontoLine(100);
      brake();
      break;
  }
}

//Coming to the T the juction

void ontoT(bool BRAKE)
{
  setLineFollow(manner);
  while (1)
  {
    qtrRead();
    if (dval[0] && dval[1] && dval[14] && dval[15])      //16-qtr - 3
    {
      if (BRAKE) brake();
      doubleLight();
      break;
    }
    lineFollow();
  }
}

void ontoL(bool BRAKE)
{
  setLineFollow(manner);
  while (1)
  {
    qtrRead();
    if ( (dval[0] && dval[1]) || (dval[14] && dval[15]) )      //16-qtr - 4
    {
      if (BRAKE) brake();
      if ((dval[0] && dval[1])) {
        leftLight();
      } else  if ((dval[14] && dval[15])) {
        rightLight();
      }
      break;
    }
    lineFollow();
  }
}

void skipL()
{
  setLineFollow(manner);
  while (1)
  {
    qtrRead();
    if ( (dval[0] && dval[1]) || (dval[14] && dval[15]) )      //16-qtr - 5
    {
      break;
    }
    lineFollow();
  }

  ontoLine(300);    //change - 2  first cell of grid
}

//Getting onto the line using PID

void ontoLine(int val)
{
  setLineFollow(manner);
  leftCount = 0;
  rightCount = 0;
  while (leftCount <= val && rightCount <= val) lineFollow();
  leftCount = 0;
  rightCount = 0;
}

//=======================================================================

//Turnings at Degrees ---------------------------------------------------

void turnAngle(int angle)   //change - 7    encoder counts for turns
{
  switch (angle)
  {
    case -90: //anticlockwise 90 degree,   total count 740
      leftTurn();
      setEncoderPID('X');
      leftTurn();
      countStart();
      while (leftCount < 70 && rightCount < 70) encoderPID();
      setEncoderPID('F');
      leftTurn();
      countStart();
      while (leftCount < 70 && rightCount < 70) encoderPID();
      break;
    case 90: //clockwise 90 degree
      setEncoderPID('X');
      rightTurn();
      countStart();
      while (leftCount < 70 && rightCount < 70) encoderPID();
      setEncoderPID('F');
      rightTurn();
      countStart();
      while (leftCount < 70 && rightCount < 70) encoderPID();
      break;

    case 180: //clockwise 90 degree, total count 1420
      setEncoderPID('X');
      rightTurn();
      countStart();
      while (leftCount < 120 && rightCount < 120) encoderPID();
      setEncoderPID('F');
      rightTurn();
      countStart();
      while (leftCount < 70 && rightCount < 70) encoderPID();
      break;
  }

  setEncoderPID('S');
  switch (angle)
  {
    case -90:
      leftTurn();
      break;
    case 90:
      rightTurn();
      break;
    case 180:
      rightTurn();
      break;
  }
  while (1)
  {
    qtrRead();
    if ( dval[6] && dval[7] && dval[8])      //16-qtr - 7
    {
      brake();
      break;
    }
    encoderPID();
  }

  //ontoLine(200);

  leftCount = 0;
  rightCount = 0;
}

//===================================================================

//Basic Motion Functions --------------------------------------------

void Start()
{
  digitalWrite(rightMotorPWM, LOW);
  digitalWrite(leftMotorPWM, LOW);

  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}

void brake() //active brake
{
  digitalWrite(rightMotorPWM, 255);
  digitalWrite(leftMotorPWM, 255);

  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, HIGH);

  delay(250);
}

void motorSpeed(bool state)
{
  digitalWrite(leftMotorPWM, state);
  digitalWrite(rightMotorPWM, state);
}

void motorSpeed(byte leftSpeed, byte rightSpeed)
{
  analogWrite(leftMotorPWM, leftSpeed);
  analogWrite(rightMotorPWM, rightSpeed);
}

void forward()
{
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
}

void forward(int LSpeed, int RSpeed)
{
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, HIGH);

  analogWrite(leftMotorPWM, LSpeed);
  analogWrite(rightMotorPWM, RSpeed);
}

void backward()
{
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorBackward, HIGH);
}

void backward(int LSpeed, int RSpeed)
{
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorBackward, HIGH);

  analogWrite(leftMotorPWM, LSpeed);
  analogWrite(rightMotorPWM, RSpeed);
}

void leftTurn()
{
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
}

void leftTurn(int LSpeed, int RSpeed)
{
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, HIGH);

  analogWrite(leftMotorPWM, LSpeed);
  analogWrite(rightMotorPWM, RSpeed);
}

void rightTurn()
{
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, HIGH);
  digitalWrite(leftMotorForward, HIGH);
}

void rightTurn(int LSpeed, int RSpeed)
{
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, HIGH);
  digitalWrite(leftMotorForward, HIGH);

  analogWrite(leftMotorPWM, LSpeed);
  analogWrite(rightMotorPWM, RSpeed);
}

//===========================================
