void centertoBreakPoint() {
  qtrRead();
  setEncoderPID('B');
  if ( !(dval[7] && dval[8]) ) {
    while (!(dval[7] && dval[8]))
    {
      qtrRead();
      encoderPID();
    }
    int tempB = brakeTime;
    brakeTime = 2;
    brake( 'B' );
    brakeTime = tempB;
  }
  setLineFollow( manner );
  stoP();
}

void centerAtWhiteLine() {
  lineMode = 0;
  forward();
  uint16_t position = qtr.readLineWhite(sensorValues);
  for (int i = 0; i < SensorCount ; i++ )
  {
    if (sensorValues[i] < 600) dval[i] = 1;
    else dval[i] = 0;
  }
  int b = 0;
  while (!(dval[7] && dval[8]))
  {
    if (position > 7500) {
      rightTurn(180, 180);
      b = 1;
    }
    else if (position < 7500) {
      leftTurn(180, 180);
      b = 0;
    }
    qtrReadMesh();
  }
  int tempB = brakeTime;
  brakeTime = 0.1;
  if ( b == 1 ) {
    brake( 'L' );
  } else {
    brake( 'R' );
  }
  brakeTime = tempB;
  setLineFollow( manner );
  stoP();
}


void centerAtLine() {
  forward();
  uint16_t position = qtr.readLineBlack(sensorValues);
  for (int i = 0; i < SensorCount ; i++ )
  {
    if (sensorValues[i] < 600) dval[i] = 0;
    else dval[i] = 1;
  }
  int b = 0;
  while (!(dval[7] && dval[8]))
  {
    if (position > 7500) {
      rightTurn(200, 200);
      b = 1;
    }
    else if (position < 7500) {
      leftTurn(200, 200);
      b = 0;
    }
    qtrRead();
  }
  int tempB = brakeTime;
  brakeTime = 5;
  if ( b == 1 ) {
    brake( 'L' );
  } else {
    brake( 'R' );
  }
  brakeTime = tempB;
}


void lineFollowMove(int count)
{
  leftCount = 0;
  rightCount = 0;

  setLineFollow('B');
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
  setLineFollow( manner );
  stoP();
  brake( 'L' );
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
  stoP();
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
    if (dval[2] && dval[3] && dval[12] && dval[13])      //16-qtr - 3
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
    if (lineMode == 0 ) {
      qtrReadMesh();
    } else {
      qtrRead();
    }
    if ( (dval[0] && dval[1]) || (dval[13] && dval[14]) )      //16-qtr - 5
    {
      break;
    }
    if (lineMode == 0 ) {
      lineFollowInMash();
    } else {
      lineFollow();
    }
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
        if (lineMode == 1 ) {
          qtrRead();
        } else {
          qtrReadMesh();
        }
        if (dval[2] && dval[3])      //16-qtr - 6
        {
          encoderMove(junctionCount);
          turnAngle(-90);
          break;
        }
        else {
          if (lineMode == 1 ) {
            lineFollow();
          } else {
            lineFollowInMash();
          }
        }
      }
      break;

    case 'R': //Go forward and turn right
      while (1)
      {
        if (lineMode == 1 ) {
          qtrRead();
        } else {
          qtrReadMesh();
        }
        if (dval[12] && dval[13])      //16-qtr - 2
        {
          encoderMove(junctionCount);
          turnAngle(90);
          break;
        }
        else {
          if (lineMode == 1 ) {
            lineFollow();
          } else {
            lineFollowInMash();
          }
        }
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
    if ( (dval[2] && dval[3]) || (dval[12] && dval[13]) )      //16-qtr - 4
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
  while (leftCount <= val && rightCount <= val) {
    if (lineMode == 0 ) {
      lineFollowInMash();
    } else {
      lineFollow();
    }
  }
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
  int i = 0;
  while (1) {
    if (isLine()) {
      //      if ( i == 0 ) {
      //        centerAtLine();
      //      }
      i = 1;;
      setLineFollow( 'D' );
      lineFollow();
    } else {
      i = 0;
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

void onToBlack() {
  setLineFollow(manner);
  while (1) {
    qtrReadMesh();
    if ( dval[0] && dval[1] && dval[14] && dval[15] && !( dval[7] || dval[8]  ) ) {
      break;
    }
    lineFollowInMash();
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
      while (leftCount < 150 && rightCount < 150) {
        encoderPIDA();
      }
      setEncoderPID('E');
      leftTurn();
      while (1)
      {
        if (lineMode == 1 ) {
          qtrRead();
        } else {
          qtrReadMesh();
        }
        if ( dval[5] || dval[6] )     //16-qtr - 7
        {  brake(  );
          brake( 'R' );
          break;
        }
        encoderPID();
      }
      break;
    case 90: //clockwise 90 degree
      setEncoderPID('X');
      rightTurn();
      countStart();
      while (leftCount < 150 && rightCount < 150) {
        encoderPIDA();
      }
      setEncoderPID ('E');
      rightTurn();
      while (1)
      {
        if (lineMode == 1 ) {
          qtrRead();
        } else {
          qtrReadMesh();
        }
        if ( dval[9] || dval[10]  )     //16-qtr - 7
        {
          brake( 'L' );
          break;
        }
        encoderPID();
      }
      break;

    case 180: //clockwise 90 degree, total count 1420
      setEncoderPID('X');
      rightTurn();
      countStart();
      while (leftCount < 220 && rightCount < 220) {
        encoderPIDA();
      }
      setEncoderPID ('E');
      rightTurn();
      int temp = brakeTime;
      brakeTime = 60;
      while (1)
      {
        if (lineMode == 1 ) {
          qtrRead();
        } else {
          qtrReadMesh();
        }
        if (  dval[12] && dval[13] )     //16-qtr - 7
        {
          brake( 'L' );
          break;
        }
        encoderPID();
      }
      brakeTime = temp;
      break;
  }
  //ontoLine(200);
  setLineFollow( manner );
  stoP();
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

void stoP() {
  motorSpeed(0, 0);
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
