




void setEncoderPID(char manner)
{
  forward();
  leftCount = 0;
  rightCount = 0;

  lastError = 0;
  integral = 0;

  switch (manner)
  {
    case 'E':
      Kp = 1;
      Kd = 10;
      //Ki = ;
      minSpeed = 150;
      baseSpeed = 180;
      maxSpeed = 210;
      break;

    case 'S'://Slow
      Kp = 10;
      Kd = 50;
      //Ki = ;
      minSpeed = 70;
      baseSpeed = 140;
      maxSpeed = 170;
      break;

    case 'M'://Moderate
    default:
      Kp = 10;
      Kd = 50;
      //Ki = ;
      minSpeed = 100;
      baseSpeed = 150;
      maxSpeed = 200;
      break;

    case 'F'://Fast
      Kp = 10;
      Kd = 100;
      //Ki = ;
      minSpeed = 150;
      baseSpeed = 200;
      maxSpeed = 255;
      break;
    case 'R'://Fast
      Kp = 10;
      Kd = 100;
      //Ki = ;
      minSpeed = 140;
      baseSpeed = 170;
      maxSpeed = 290;
      break;

    case 'X'://Xtremely Fast
      Kp = 10;
      Kd = 50;
      //Ki = ;
      minSpeed = 200;
      baseSpeed = 255;
      maxSpeed = 255;
    case 'B':
      backward();
      Kp = 10;
      Kd = 50;
      //Ki = ;
      minSpeed = 100;
      baseSpeed = 185;
      maxSpeed = 220;
  }

}

void encoderPID()
{
  int error = leftCount - rightCount;

  int controlSpeed = Kp * error + Kd * (error - lastError); // + Ki*integral;
  lastError = error;

  int rightMotorSpeed = constrain((baseSpeed + controlSpeed), minSpeed, maxSpeed);
  int leftMotorSpeed = constrain((baseSpeed - 65 - controlSpeed), minSpeed, maxSpeed);

  motorSpeed(leftMotorSpeed, rightMotorSpeed);
}

void encoderPIDA()
{
  int error = leftCount - rightCount;

  int controlSpeed = Kp * error + Kd * (error - lastError); // + Ki*integral;
  lastError = error;

  int rightMotorSpeed = constrain((baseSpeed + controlSpeed), minSpeed, maxSpeed);
  int leftMotorSpeed = constrain((baseSpeed  - controlSpeed), minSpeed, maxSpeed);

  motorSpeed(leftMotorSpeed, rightMotorSpeed);
}

void encoderPID(int dash)
{
  int error = leftCount - rightCount - dash;

  int controlSpeed = Kp * error + Kd * (error - lastError); // + Ki*integral;
  lastError = error;

  int rightMotorSpeed = constrain((baseSpeed + controlSpeed), minSpeed, maxSpeed);
  int leftMotorSpeed = constrain((baseSpeed - controlSpeed), minSpeed, maxSpeed);

  motorSpeed(leftMotorSpeed, rightMotorSpeed);
}
