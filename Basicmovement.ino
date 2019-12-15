void lineFollowMove(int count)
{
  leftCount = 0;
  rightCount = 0;

  setLineFollow('E');

  while (leftCount <= count && rightCount <= count) lineFollow();
  brake( 'B' );
}

void centerAtJunction(int val) {
  encoderMove( val );
}
void encoderbackTurn() {
  setEncoderPID('F');
  countStart();
  rightTurn();
  while ( leftCount < 650 && rightCount < 650 ) {
    encoderPID();
  }
  brake( 'L' );
  setLineFollow( manner );
}
void encoderMove(int count)
{
  leftCount = 0;
  rightCount = 0;

  if (count > 0) {
    forward();
    setEncoderPID('F');
  }
  else {
    backward();
    setEncoderPID('B');
  }
  while (leftCount <= abs(count) && rightCount <= abs(count)) encoderPID();
  if (count > 0) brake('B');
  else brake( 'F' );
  setLineFollow( manner );
}

void leaveSquare()
{
  //Leaving starting   zone --------------------------------
  setEncoderPID('F');
  forward();
  qtrRead();
  while ( dval[0] || dval[15])      //16-qtr - 1
  {
    encoderPID();
    qtrRead();
  }
  brake();
}

void enterSquare()
{
  encoderMove(350);   //change - 6    center for end squre
  brake();
}

//Coming to the T the juction
void ontoT(bool BRAKE)
{
  setLineFollow(manner);
  while (1)
  {
    qtrRead();
    if (dval[2] && dval[3] && dval[13] && dval[14])      //16-qtr - 3
    {
      if (BRAKE) brake('B');
      doubleLight();
      break;
    }
    lineFollow();
  }
}

void skipTurn()
{
  setLineFollow(manner);
  while (1)
  {
    qtrRead();
    if ( (dval[2] && dval[3]) || (dval[10] && dval[11]) )      //16-qtr - 5
    {
      break;
    }
    lineFollow();
  }

  skip(200);    //change - 2  first cell of grid

}


void turn(char input) //Explicit turnings
{
  setLineFollow(manner);
  switch (input)
  {
    case 'L': //Go forward and Turn Left
      while (1)
      {
        if (lineMode == 0 ) {
          qtrReadMesh();
        } else {
          qtrRead();
        }
        if (dval[2] && dval[3])      //16-qtr - 6
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
        if (lineMode == 0 ) {
          qtrReadMesh();
        } else {
          qtrRead();
        }
        if (dval[12] && dval[13])      //16-qtr - 2
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

void ontoBreakPoint(bool BRAKE)
{
  setLineFollow(manner);
  while (1)
  {
    qtrRead();
    if (dval[5] && dval[6] && dval[11] && dval[12])      //16-qtr - 3
    {
      if (BRAKE) brake('B');
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
    if ( (dval[2] && dval[3]) || (dval[13] && dval[14]) )      //16-qtr - 4
    {
      if (BRAKE) brake('B');
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

//Getting onto the line using PID
void ontoLine(int val)
{
  setLineFollow(manner);
  leftCount = 0;
  rightCount = 0;
  while (leftCount <= val && rightCount <= val) lineFollow();
  leftCount = 0;
  rightCount = 0;
  brake('B');
}

void skip(int val)
{
  setLineFollow(manner);
  leftCount = 0;
  rightCount = 0;
  while (leftCount <= val && rightCount <= val) lineFollow();
  leftCount = 0;
  rightCount = 0;
  //  brake('B');
}

void onToDashLine() {
  setLineFollow('U');
  while (1) {
    lineFollow();
    qtrRead();
    if ( !( dval[0] || dval[1] || dval[2]   || dval[3]   || dval[4]   || dval[5]   || dval[6]   || dval[7]  || dval[8]
            || dval[9] || dval[10] || dval[11]   || dval[12]   || dval[13]   || dval[14]   || dval[15]
          )) {
      break;
    }
  }
  setLineFollow(manner);
  brake('B');
}

void inDashLine() {

  while (1) {
    if (isLine()) {
      setLineFollow( 'D' );
      lineFollow();
    } else {
      setEncoderPID('S');
      encoderPID();
    }
    if (dval[5] && dval[6] && dval[11] && dval[12]) {
      break;
    }
  }
  setLineFollow(manner);
  brake('B');
}



void onToMesh() {
  setLineFollow(manner);
  while (1) {
    qtrRead();
    if ( dval[0] && dval[1] && dval[14] && dval[15] && !( dval[7] || dval[8]  ) ) {
      break;
    }
    lineFollow();
  }
  brake('B');
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
      while (leftCount < 300 && rightCount < 300) encoderPID();
      //      setEncoderPID('F');
      //      leftTurn();
      //      countStart();
      //      while (leftCount < 100 && rightCount <100) encoderPID();
      break;
    case 90: //clockwise 90 degree
      setEncoderPID('X');
      rightTurn();
      countStart();
      while (leftCount < 300 && rightCount < 300) encoderPID();
      //      setEncoderPID('F');
      //      rightTurn();
      //      countStart();
      //      while (leftCount < 100 && rightCount < 100) encoderPID();
      break;

    case 180: //clockwise 90 degree, total count 1420
      setEncoderPID('X');
      rightTurn();
      countStart();
      while (leftCount < 420 && rightCount < 420) encoderPID();
      setEncoderPID('F');
      break;
  }

  setEncoderPID ('E');
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
    if (lineMode == 1 ) {
      qtrReadMesh();
    }
    if (  dval[7] || dval[8]  )      //16-qtr - 7
    {
      switch (angle)
      {
        case -90:
          brake( 'R' );
          break;
        case 90:
          brake( 'L');
          break;
        case 180:
          brake( 'L' );
          break;
      }
      break;
    }
    encoderPID();
  }

  //ontoLine(200);
  setLineFollow( manner );
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
