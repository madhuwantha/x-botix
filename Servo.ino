void leftColorServo( int angle ) {  // 60 - 120
  leftServo.write(angle);
}

void rightColorServo( int angle ) {  // 60 - 120
  rightServo.write(angle);
}

void setColorServo() {
  leftColorServo( 125 );
  rightColorServo( 125 );
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
  for ( int i = 0; i < 55; i++ ) {
    rightCatchServo.write( 120 - i);
    leftCatchServo.write( 60 + i );
    delay(20);
  }
}
void baseToCatch() {
  baseServoRotate(05);
}
void up() {
  baseServoRotate(100);
}
