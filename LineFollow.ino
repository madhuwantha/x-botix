void setLineFollow(char manner)
{
  forward();

  lastError = 0;
  integral = 0;

  switch (manner)
  {
    case 'E'://Extremly Slow
      Kp = 0.1;
      Kd = 1;
      Ki = 0.001;
      minSpeed = 0;
      baseSpeed = 50;
      maxSpeed = 50;
      break;

    case 'S'://Slow
      Kp = 0.1;
      Kd = 1;
      Ki = 0.001;
      minSpeed = 0;
      baseSpeed = 80;
      maxSpeed = 100;
      break;

    case 'M'://Moderate
    default:
      Kp = 0.05;
      Kd = 2;
      Ki = 0.001;
      minSpeed = 0;
      baseSpeed = 100;
      maxSpeed = 150;
      break;

    case 'F'://Fast
      Kp = 0.05;
      Kd = 5;
      Ki = 0.001;
      minSpeed = 0;
      baseSpeed = 150;
      maxSpeed = 200;
      break;

    case 'V'://Very fast
      Kp = 0.07;
      Kd = 15;
      Ki = 0.001;
      minSpeed = 0;
      baseSpeed = 200;
      maxSpeed = 255;
      break;

    case 'U'://Ultra fast
      Kp = 0.07;
      Kd = 15;
      Ki = 0.001;
      minSpeed = 0;
      baseSpeed = 255;
      maxSpeed = 255;
      break;
  }
}


//Line Following : PID Algorithm -------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lineFollow()
{
  //  uint16_t position = qtr.readLineWhite(sensorValues); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
  uint16_t position = qtr.readLineBlack(sensorValues);
  int error = position - 7000;

  integral = integral + error;

  int controlSpeed = Kp * error + Kd * (error - lastError) + Ki * integral;

  lastError = error;

  byte rightMotorSpeed = constrain((baseSpeed - controlSpeed), minSpeed, maxSpeed);
  byte leftMotorSpeed = constrain((baseSpeed +   controlSpeed), minSpeed, maxSpeed);

  Serial.print(  rightMotorSpeed );
  Serial.print(  "   " );
  Serial.println(  leftMotorSpeed );

  motorSpeed(leftMotorSpeed, rightMotorSpeed);
}

//=====================================================================================================================================================================================

void lineFollowInMash()
{
  uint16_t position = qtr.readLineWhite(sensorValues);
  int error = position - 7000;

  integral = integral + error;

  int controlSpeed = Kp * error + Kd * (error - lastError) + Ki * integral;

  lastError = error;

  byte rightMotorSpeed = constrain((baseSpeed + controlSpeed), minSpeed, maxSpeed);
  byte leftMotorSpeed = constrain((baseSpeed -   controlSpeed), minSpeed, maxSpeed);

  Serial.print(  rightMotorSpeed );
  Serial.print(  "   " );
  Serial.println(  leftMotorSpeed );

  motorSpeed(leftMotorSpeed, rightMotorSpeed);
}
