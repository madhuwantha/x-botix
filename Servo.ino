void leftColorServo( int angle ) {  // 60 - 120
  leftServo.write(angle);
}

void rightColorServo( int angle ) {  // 60 - 120
  rightServo.write(angle);
}

void setColorServo() {
  leftColorServo( 135 );
  rightColorServo( 135 );
}

void colorServoIntiate() {
  rightColorServo( 60 );
  leftColorServo( 60 );
}

void ServoIntiate() {
  colorServoIntiate();
  baseServo.write(140);
  leftCatchServo.write(60);   //100
  rightCatchServo.write(120); //80
}

void baseServoRotate(int angle) {
  baseServo.write(angle);
}
void leftCatchServoRotate(int angle) {
  for ( int i = 60; i < angle; i++ ) {
    leftCatchServo.write(i);
    delay(15);
  }
}
void rightCatchServoRotate(int angle) {
  for ( int i = 120; i > angle; i-- ) {
    rightCatchServo.write(i);
    delay(15);
  }
}
void catchSorb() {
  for ( int i = 0; i < 60; i++ ) {
    rightCatchServo.write( 110  - i);
    leftCatchServo.write( 60 + i );
    delay(20);
  }
}

void releseSorb() {
  for ( int i = 0; i < 55; i++ ) {
    rightCatchServo.write( 60  + i);
    leftCatchServo.write( 115 - i );
    delay(20);
  }
}

void vibrate() {
  rightCatchServo.write( 62);
  leftCatchServo.write( 115 );
}
void baseToCatch() {
  baseServoRotate(07);
}
void  baseToPut() {
  for ( int i = 101; i > 35; i-- ) {
    baseServoRotate(i);
    delay(20);
  }
  delay(1000);
  for ( int i = 35; i > 5; i-- ) {
    baseServoRotate(i);
    delay(20);
  }
}
void up() {
  for ( int i = 10; i < 101; i++ ) {
    baseServoRotate(i);
    delay(20);
  }

}
