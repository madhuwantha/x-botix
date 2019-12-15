//void beep() {
//  digitalWrite(leftMotorForward, LOW);
//  delay(100);
//  digitalWrite(leftMotorForward, HIGH);
//}


//metal detector
// white - -
//graw   - +
//yellow - signal
void light( char mode  ) {
  analogWrite( 34, 0 );
  analogWrite( 36, 0 );
  analogWrite( 38, 0 );
  analogWrite( 42, 0 );
  analogWrite( 40, 0 );
  switch (mode) {
    case 'R':
      analogWrite( 34, 150 );
      break;
    case 'G':
      analogWrite( 36, 150 );
      break;
    case 'B':
      analogWrite( 38, 150 );
      break;
    case 'O':
      analogWrite( 34, 0 );
      analogWrite( 36, 0 );
      analogWrite( 38, 0 );
      analogWrite( 42, 0 );
      analogWrite( 40, 0 );
      break;
    default:
      break;
  }
}

//RGB 34 36 38
void doubleLight() {
  analogWrite( 42, 150 ); analogWrite( 40, 150 );
  delay( 200 );
  analogWrite( 42, 0 ); analogWrite( 40, 0 );
}
void leftLight(  ) {
  analogWrite( 42, 150 );
  delay( 200 );
  analogWrite( 42, 0 );
}

void rightLight(  ) {
  analogWrite( 40, 150 );
  delay( 200 );
  analogWrite( 40, 0 );
}
void red() {
  analogWrite( 34, 150 );
  delay( 200 );
  analogWrite( 34, 0 );
}

void green() {
  analogWrite( 36, 150 );
  delay( 200 );
  analogWrite( 36, 0 );
}

void blue() {
  analogWrite( 38, 150 );
  delay( 200 );
  analogWrite( 38, 0 );
}



void getSword() {
  
  turn('L');
  turn('L');
  setLineFollow('S');
  ontoBreakPoint(1);
  setLineFollow(manner);
  encoderMove( -160 );
  stoP();
  baseToCatch();
  delay(500);
  catchSorb();
  delay(500);
  up();
  vibrate();
}

void putSword() {
  setLineFollow('S');
  // on to break point
  while (1)
  {
    qtrRead();
    if (dval[5] && dval[6] && dval[11] && dval[12])      //16-qtr - 3
    {
      if (1) brake();
      doubleLight();
      break;
    }
    lineFollow();
  }
  setEncoderPID('S');
  while ( 1 ) {
    qtrRead();
    if ( !dval[7] && !dval[8]  ) {
      brake();
      break;
    }
    encoderPID();
  }
  setLineFollow(manner);
  brakeTime = 5;
  encoderMove( -40 );
  brakeTime = 50;
  baseToPut();
  delay(500);
  baseServoRotate( 1 );
  delay(500);
  releseSorb();

  ServoIntiate();
}

void ramp() {
  leftCount = 0;
  rightCount = 0;
  ontoBreakPoint(1);
  delay(500);
  setEncoderPID('F');

  while ( leftCount < 1100 &&  rightCount < 1100 ) {
    encoderPID();
  }
  brake('B');
  ontoLine(150);
}


void pushButton() {
  encoderMove(-190);
  turnAngle(180);
  leftCount = rightCount = 0;
  ontoLine(200);
  brake('B');
  delay(500);
  encoderMove(-650);
}



void roboVibrate() {

}



bool isMetal() {
  int count_ = 0;
  for ( int i = 0; i < 100 ; i++ ) {
    int a = digitalRead(metalPin);
    count_ = count_ + a;
  }

  if ( count_ >= 60 ) {
    return 1;
  } else {
    return 0;
  }
}
