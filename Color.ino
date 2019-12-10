

//For Area C
void twoColor(Adafruit_TCS34725softi2c sensorN, Adafruit_TCS34725softi2c sensorO) {
  uint16_t clearN, redN, greenN, blueN, calcMaxN, maxN;
  uint16_t clearO, redO, greenO, blueO, calcMaxO, maxO;
  char color[2];

  sensorN.setInterrupt(false);      // turn on LED
  sensorO.setInterrupt(false);

  delay(60);  // takes 50ms to read

  sensorN.getRawData(&redN, &greenN, &blueN, &clearN);
  sensorO.getRawData(&redO, &greenO, &blueO, &clearO);

  sensorN.setInterrupt(true);  // turn off LED
  sensorO.setInterrupt(true);

  if (redN > greenN && redN > blueN) {
    leftLight(  ); light('R');
    color[0] = "R";
    /// Serial.println("LEFT COLOR == REDn");
  }
  else if (greenN > redN && greenN > blueN) {
    leftLight(  ); light('G');
    color[0] = "G";
    //Serial.println("LEFT COLOR == GREENn");
  }
  else if (blueN > greenN && blueN > redN) {
    leftLight(  ); light('B');
    color[0] = "B";
    //Serial.println("LEFT COLOR == BLUEn");
  }

  if (redO > greenO && redO > blueO) {
    rightLight(  ); light('R');
    color[1] = "R";
    //Serial.println("\t\t\tRIGHT COLOR == REDo");
  }
  else if (greenO > redO && greenO > blueO) {
    rightLight(  ); light('G');
    color[1] = "G";
    //Serial.println("\t\t\tRIGHT COLOR == GREENo");
  }
  else if (blueO > greenO && blueO > redO) {
    rightLight(  ); light('B');
    color[1] = "B";
    //Serial.println("\t\t\tRIGHT COLOR == BLUEo");
  }

  // Figure out some basic hex code for visualization
  uint32_t sumN = clearN;
  float rN, gN, bN;
  rN = redN; rN /= sumN;
  gN = greenN; gN /= sumN;
  bN = blueN; bN /= sumN;
  rN *= 256; gN *= 256; bN *= 256;
  //Serial.print("\t");
  //Serial.println();

  uint32_t sumO = clearO;
  float rO, gO, bO;
  rO = redO; rO /= sumO;
  gO = greenO; gO /= sumO;
  bO = blueO; bO /= sumO;
  rO *= 256; gO *= 256; bO *= 256;
  //Serial.print("\t");
  //Serial.println();
  //  return(colorAreaC);

  if  (  colorArray == 0) {
    colorAreaC[0] = color[0];
    colorAreaC[1] = color[1];
    colorArray = 1;
  }
  else {
    colorAreaC[2] = color[0];
    colorAreaC[3] = color[1];
  }
  light('O');
}


//For Area A
char oneColor(Adafruit_TCS34725softi2c sensorN) {
  uint16_t clearN, redN, greenN, blueN, calcMaxN, maxN;

  sensorN.setInterrupt(false);

  delay(60);

  sensorN.getRawData(&redN, &greenN, &blueN, &clearN);

  sensorN.setInterrupt(true);

  if (redN > greenN && redN > blueN) {
    colorAreaA = "R";
    light('R');
    //Serial.println("LEFT COLOR == REDn");
  }
  else if (greenN > redN && greenN > blueN) {
    colorAreaA = "G";
    light('G');
    //Serial.println("LEFT COLOR == GREENn");
  }
  else if (blueN > greenN && blueN > redN) {
    colorAreaA = "B";
    light('B');
    //Serial.println("LEFT COLOR == BLUEn");
  }

  uint32_t sumN = clearN;
  float rN, gN, bN;
  rN = redN; rN /= sumN;
  gN = greenN; gN /= sumN;
  bN = blueN; bN /= sumN;
  rN *= 256; gN *= 256; bN *= 256;
  //Serial.print("\t");
  //Serial.println();

  //  return (colorAreaA);

}

void IndicateinC() {
  for ( int i = 0; i < 4; i++ ) {
    if ( colorAreaC[i] == colorAreaA ) {
      colorCount = colorCount + 1;
    }
  }
  switch (colorAreaA) {
    case 'R':
      light( 'R' );
      break;
    case 'G':
      light( 'G' );
      break;
    case 'B':
      light( 'B' );
      break;
  }

  switch (colorCount) {
    case 2:
      analogWrite( 42, 150 );
      break;
    case 3:
      analogWrite( 42, 150 );
      analogWrite( 40, 150 );
      break;
  }

}



void servoMake() {
  leftColorServo(120);
  rightColorServo(120);
}
