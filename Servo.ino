void leftColorServo( int angle ) {  // 60 - 120
  leftServo.write(angle);
}

void rightColorServo( int angle ) {  // 60 - 120
  rightServo.write(angle);
}

void colorServoIntiate() {
  rightColorServo( 60 );
  leftColorServo( 60 );
}

void ServoIntiate() {
  colorServoIntiate();
  baseServo.write(140);
  leftCatchServo.write(60);
  rightCatchServo.write(130);
}
