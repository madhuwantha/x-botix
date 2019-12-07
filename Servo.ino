void leftColorServo( int angle ) {  // 60 - 120
  leftServo.write(angle);
}

void rightColorServo( int angle ) {  // 60 - 120
  rightServo.write(angle);
}

void colorServoIntiate(){
  rightColorServo( 60 );
  leftColorServo( 60 );
}
