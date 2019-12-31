void game() {
  while ( 1 ) {
    //    lineFollow();
  }
}

void firstRound() {
  leaveSquare(); // start

  //************************AAAAAAAAAAAAAAAAAAA*******************************
  turn('R'); //to A
  centerAtLine();
  ontoBreakPoint(1); // A
  centertoBreakPoint();
  encoderMove(50);
  setColorServo();
  delay(300);
  oneColor( tcsN ); // detect the color
  colorServoIntiate();
  turnAngle(180);
  light('O');
  centerAtLine();
  encoderMove(-200);

  //*************************BBBBBBBBBBBBBBBBBBBB******************************
  turn('R');
  skipTurn();
  skipTurn();
  ontoBreakPoint(1); //  break point B
  centertoBreakPoint();
  encoderMove(50);
  setColorServo();
  delay(300);
  twoColor( tcsN, tcsO );//detect color B  1
  colorServoIntiate();
  encoderMove(-200);
  turnAngle(180);
  light('O');
  centerAtLine();
  encoderMove(-200); ////////////////////////////////////////////////////////////////////////
  turn('R');
  turn('R');
  turn('R');
  centerAtLine();
  ontoBreakPoint(1);
  centertoBreakPoint();
  encoderMove(50);
  setColorServo();
  delay(300);
  twoColor( tcsN, tcsO );//detect color B  2
  colorServoIntiate();
  encoderMove(-200);
  turnAngle(180);
  light('O');
  centerAtLine();
  turn('L');
  turn('L');
  turn('R'); // finishedd the B

  //*************************CCCCCCCCCCCCCCCCCCCCCC******************************
  turn('L');
  ontoT(1);
  enterSquare();
  IndicateinC();
  light( 'O' );
  encoderbackTurn();
  leaveSquare();
  centerAtLine();
  skipTurn(); // crose line after C
  turn('R');
  turn('L'); // before the dash liine

  //*************************DDDDDDDDDDDDDDDDDDDDDD******************************
  onToDashLine();
  inDashLine();

  //*************************EEEEEEEEEEEEEEEEEEEEEE******************************
  centerAtJunction(T);
  turnAngle(-90);
  centerAtLine();
  ontoBreakPoint(1);
  centertoBreakPoint();
  pushButton(); // push button
  centerAtLine();
  skipTurn();
  //turn( 'R' );  ////////////////////////////////////////////////////////////////////////////////
  skipTurn();

  //*************************GGGGGGGGGGGGGGGGGGGGGG******************************
  //ramp();
  //skipTurn();
  //skipTurn();
  turn( 'R' );

  //*************************HHHHHHHHHHHHHHHHHHHHHH******************************
  onToMesh( );
  lineMzaSolve();// mesh

  //*************************IIIIIIIIIIIIIIIIIIIIII******************************
  lineMode = 1;
  getSword();
  turnAngle(180);
  encoderMove( -300 );/////////////////////////////////////////////////////////////////////////////////
  turn('R');
  turn('R');
  onToMesh();

  //*************************HHHHHHHHHHHHHHHHHHHHHH******************************
  goHome();
  onToBlack();// shotest path
  lineMode = 1;
  ontoLine(100);
  turn('L');

  //*************************GGGGGGGGGGGGGGGGGGGGGG******************************
  //ramp();
  skipTurn();
  skipTurn();
  turn('L');


  //*************************JJJJJJJJJJJJJJJJJJJJJJ******************************
  ontoL(1);
  switch (colorCount) {
    case 0:
      centerAtJunction(L);
      break;
    case 1:
      centerAtJunction(L);
      break;
    case 2:
      centerAtJunction(L);
      turnAngle(90);
      turn('L');
      break;
    case 3:
      centerAtJunction(L);
      turnAngle(90);
      skipTurn();
      turn('L');
      break;
  }
  centerAtLine();
  putSword();
}


void secondRound() {
  leaveSquare(); // start

  //************************AAAAAAAAAAAAAAAAAAA*******************************
  turn('R'); //to A
  centerAtLine();
  ontoBreakPoint(1); // A
  centertoBreakPoint();
  setColorServo();
  delay(300);
  oneColor( tcsN ); // detect the color
  colorServoIntiate();
  encoderMove(-200);
  turnAngle(180);
  light('O');
  centerAtLine();

  //*************************BBBBBBBBBBBBBBBBBBBB******************************
  turn('R');
  skipTurn();
  skipTurn();
  ontoBreakPoint(1); //  break point B
  centertoBreakPoint();
  setColorServo();
  delay(300);
  twoColor( tcsN, tcsO );//detect color B  1
  colorServoIntiate();
  encoderMove(-200);
  turnAngle(180);
  light('O');
  centerAtLine();
  encoderMove(-200); ////////////////////////////////////////////////////////////////////////
  turn('R');
  turn('R');
  turn('R');
  centerAtLine();
  ontoBreakPoint(1);
  centertoBreakPoint();
  setColorServo();
  delay(300);
  twoColor( tcsN, tcsO );//detect color B  2
  colorServoIntiate();
  encoderMove(-200);
  turnAngle(180);
  encoderMove(-200);
  light('O');
  centerAtLine();
  turn('L');
  turn('L');
  turn('R'); // finishedd the B

  //*************************CCCCCCCCCCCCCCCCCCCCCC******************************
  turn('L');
  ontoT(1);
  enterSquare();
  IndicateinC();
  delay(3000);
  light( 'O' );
  encoderbackTurn();
  leaveSquare();
  centerAtLine();
  skipTurn(); // crose line after C
  turn('R');
  turn('L'); // before the dash liine

  //*************************DDDDDDDDDDDDDDDDDDDDDD******************************
  onToDashLine();
  inDashLine();

  //*************************EEEEEEEEEEEEEEEEEEEEEE******************************
  centerAtJunction(T);
  turnAngle(-90);
  centerAtLine();
  ontoBreakPoint(1);
  centertoBreakPoint();
  pushButton(); // push button
  centerAtLine();
  skipTurn();

  //turn( 'R' );  ////////////////////////////////////////////////////////////////////////////////

  skipTurn();

  //*************************GGGGGGGGGGGGGGGGGGGGGG******************************
  ramp();
  //skipTurn();
  //skipTurn();
  turn( 'R' );

  //*************************HHHHHHHHHHHHHHHHHHHHHH******************************
  onToMesh( );
  encoderMove(100);
  centerAtWhiteLine();
  lineMzaSolve() ;// mesh

  //*************************IIIIIIIIIIIIIIIIIIIIII******************************
  lineMode = 1;
  getMetalSword();
  onToMesh();

  //*************************HHHHHHHHHHHHHHHHHHHHHH******************************
  goHome();

  onToBlack();// shotest path
  lineMode = 1;
  centerAtLine();
  turn('L');

  //*************************GGGGGGGGGGGGGGGGGGGGGG******************************
  ramp();
  //skipTurn();
  //skipTurn();
  turn('L');
  //colorCount = 2;

  //*************************JJJJJJJJJJJJJJJJJJJJJJ******************************
  ontoL(1);
  switch (colorCount) {
    case 0:
      centerAtJunction(L);
      break;
    case 1:
      centerAtJunction(L);
      break;
    case 2:
      centerAtJunction(L);
      turnAngle(90);
      turn('L');
      break;
    case 3:
      centerAtJunction(L);
      turnAngle(90);
      skipTurn();
      turn('L');
      break;
  }
  centerAtLine();
  putSword();
}



void second() {
  while ( 1 ) {

    leaveSquare(); // start
    turn('R'); //to A
    ontoBreakPoint(1); // A
    encoderMove(30);
    setColorServo();
    delay(200);
    oneColor( tcsN ); // detect the color
    colorServoIntiate();
    encoderMove(-200);
    turnAngle(180);
    light('O');

    turn('R');
    skipTurn();
    skipTurn();
    ontoBreakPoint(1); //  break point B twoColor( tcsN, tcsO );
    setColorServo();
    delay(200);
    twoColor( tcsN, tcsO );//detect color B 1
    colorServoIntiate();
    encoderMove(-200);
    turnAngle(180);
    encoderMove(-150);

    turn('R');

    turn('R');

    turn('R');

    ontoBreakPoint(1);
    setColorServo();
    delay(200);
    twoColor( tcsN, tcsO );//detect color B  2  twoColor( tcsN, tcsO );
    colorServoIntiate();
    encoderMove(-200);
    turnAngle(180);
    encoderMove(-200);

    turn('L');

    turn('L');

    turn('R'); // finishedd the B

    turn('L');

    ontoT(1);

    enterSquare();

    IndicateinC();

    light( 'O' );

    //turnAngle(180);
    encoderbackTurn();

    leaveSquare();

    ontoLine(100);

    skipTurn(); // crose line after C

    turn('R');

    turn('L'); // before the dash liine

    onToDashLine();

    inDashLine();

    centerAtJunction(T);

    turnAngle(-90);

    ontoBreakPoint(1);

    pushButton(); // push button

    skipTurn();

    turn( 'R' );  // should be removed

    skipTurn(); // before the ramp

    ramp();

    turn('R');// after the ramp

    onToMesh( );

    lineMzaSolve() ;// mesh

    lineMode = 1;
    getSword();
    turnAngle(180);
    encoderMove( -300 );
    turn('R');
    turn('R');
    onToMesh();
    goHome();
    onToBlack();// shotest path

    lineMode = 1;
    turn('L');

    ramp();

    turn('L');
    skipTurn();


    //    centerAtJunction(L);
    //    switch (colorCount) {
    //      case 1:
    //        break;
    //      case 2:
    //        turnAngle(90);
    //        turn('L');
    //        break;
    //      case 3:
    //        turnAngle(90);
    //        skipTurn();
    //        turn( 'L' );
    //        break;
    //    }
    putSword();
  }
}
