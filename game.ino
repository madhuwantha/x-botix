void game() {
  while ( 1 ) {
    //    lineFollow();
  }
}

void firstRound() {
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

    delay(3000);

    light( 'O' );

    turnAngle(180);

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

    skipTurn(); // before the ramp

    ramp();

    turn('R');// after the ramp

    onToMesh( );
    
    while(1){}  
    mesh(); // mesh
    ontoL(0);
    centerAtJunction(L);
    turnAngle(-90);
    ontoL(0);
    centerAtJunction(L);
    turnAngle(-90);
    ontoT(1); // in the room 1
    getSword();
    turnAngle(180);
    ontoT(0);
    centerAtJunction(T);
    turnAngle(90);
    ontoL(0);
    centerAtJunction(L);
    turnAngle(90);
    onToMesh( );

    goHome(); // shotest path
    ontoL(0);
    centerAtJunction(L);
    turnAngle(-90);
    ontoT(0);
    centerAtJunction(T);
    ontoT(0);
    centerAtJunction(T);
    ontoL(0);
    centerAtJunction(L);
    turnAngle(-90);
    ontoL(0);
    centerAtJunction(L);
    switch (colorCount) {
      case 1:
        ontoT(1);
        break;
      case 2:
        turnAngle(90);
        ontoL(0);
        centerAtJunction(L);
        turnAngle(-90);
        break;
      case 3:
        turnAngle(90);
        ontoL(0);
        centerAtJunction(L);
        ontoL(0);
        centerAtJunction(L);
        turnAngle(-90);
        break;
    }
    ontoT(1);
    putSword();
  }
}
