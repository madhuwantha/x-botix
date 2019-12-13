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
      Kp = 0.089;
      Kd = 0.9;
      Ki = 0.0009;
      minSpeed = 0;
      baseSpeed = 130;
      maxSpeed = 150;
      break;
    case 'D'://Moderate
      Kp = 0.895555;
      Kd = 2.025555;
      Ki = 0.00991111;
      minSpeed = 0;
      baseSpeed = 130;
      maxSpeed = 140;
      break;

    case 'M'://Moderate
      Kp = 0.089;
      Kd = 1.2;
      Ki = 0.009;
      minSpeed = 0;
      baseSpeed = 150;
      maxSpeed = 200;
      break;
    default:
      Kp = 0.05;
      Kd = 2;
      Ki = 0.001;
      minSpeed = 0;
      baseSpeed = 100;
      maxSpeed = 150;
      break;

    case 'F'://Fast
      Kp = 0.1555;
      Kd = 0.8555599;
      Ki = 0.0000000015555;
      minSpeed = 0;
      baseSpeed = 200;
      maxSpeed = 230;
      break;

    case 'V'://Very fast
      Kp = 0.1;
      Kd = 100;
      Ki = 0.001;
      minSpeed = 0;
      baseSpeed = 200;
      maxSpeed = 245;
      break;

    case 'U'://Ultra fast
      Kp = 0.089;
      Kd = 1.2;
      Ki = 0.009;
      minSpeed = 0;
      baseSpeed = 245;
      maxSpeed = 255;
      break;
    case 'B'://backword
      backward();
      Kp = 0.089;
      Kd = 1.2;
      Ki = 0.009;
      minSpeed = 0;
      baseSpeed = 140;
      maxSpeed = 170;
      break;
  }
}

bool isLine() {
  qtrRead();
  if ( dval[0] || dval[1] || dval[2] || dval[3] || dval[4] || dval[5] || dval[6] || 
  dval[7] || dval[8] || dval[9] || dval[10] || dval[11] || dval[12] || dval[13] || dval[14] || dval[15] )
  {
    return 1;
  } else {
    return 0;
  }
}


//Line Following : PID Algorithm -------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lineFollow()
{
  uint16_t position = qtr.readLineBlack(sensorValues);
  int error = position - 7500;
  Serial.print(  error );
  Serial.print(  "     " );

  integral = integral + error;

  int controlSpeed = Kp * error + Kd * (error - lastError) + Ki * integral;
  //Serial.print(  controlSpeed );
  Serial.print(  "     " );
  lastError = error;

  byte rightMotorSpeed = constrain((baseSpeed - controlSpeed), minSpeed, maxSpeed);
  byte leftMotorSpeed = constrain((baseSpeed +   controlSpeed), minSpeed, maxSpeed);

  Serial.print(  leftMotorSpeed );
  Serial.print(  "   " );
  Serial.println(rightMotorSpeed   );
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
