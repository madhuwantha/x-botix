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

}
