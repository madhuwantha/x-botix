void brake(char input) //sharp brakes
{
  setLineFollow( manner );
  switch (input)
  {
    case 'B': //backward brake
      backward(255, 255);
      delay(brakeTime);
      brake();
      break;

    case 'R': //right brake
      rightTurn(255, 255);
      delay(brakeTime);
      brake();
      break;

    case 'L': //left brake
      leftTurn(255, 255);
      delay(brakeTime);
      brake();
      break;

    case 'F': //forward brake
      forward(255, 255);
      delay(brakeTime);
      brake();
      break;

    default: //active brake
      brake();
      break;
  }
}
