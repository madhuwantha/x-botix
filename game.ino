void game() {
  while ( 1 ) {
    //    lineFollow();
  }
}

void firstRound() {
  while ( 1 ) {
    leaveSquare(); // start
    ontoL(1); // to A
    centerAtJunction(L); //to A
    turnAngle(90); //to A
    ontoBreakPoint(1); // A
    encoderMove(30);
    setColorServo();
    delay(100);
    oneColor( tcsN ); // detect the color
    colorServoIntiate();
    encoderMove(-200);
    turnAngle(180);
    light('O');
    ontoT(1);
    centerAtJunction(T);
    turnAngle(90);
    ontoT(1);
    centerAtJunction(T - 100);
    ontoBreakPoint(1); //  break point B twoColor( tcsN, tcsO );
    setColorServo();
    delay(100);
    twoColor( tcsN, tcsO );//detect color B 1
    colorServoIntiate();
    encoderMove(-200);
    turnAngle(180);
    encoderMove(-200);
    ontoL(1);
    centerAtJunction(L);
    turnAngle(90);
    ontoL(1);
    centerAtJunction(L);
    turnAngle(90);
    ontoL(1);
    centerAtJunction(L);
    turnAngle(90);
    ontoBreakPoint(1);
    setColorServo();
    delay(100);
    twoColor( tcsN, tcsO );//detect color B  2  twoColor( tcsN, tcsO );
    colorServoIntiate();
    encoderMove(-200);
    turnAngle(180);
    encoderMove(-200);
    ontoL(1);
    centerAtJunction(L);
    turnAngle(-90);
    ontoL(1);
    centerAtJunction(L);
    turnAngle(-90);
    ontoT(1);
    centerAtJunction(T);
    turnAngle(90); // finishedd the B
    ontoT(1);
    centerAtJunction(T);
    turnAngle(-90);
    ontoT(1);
    enterSquare();
    IndicateinC();
    delay(10000);
    light( 'O' );
    encoderbackTurn();
    //leaveSquare();

    ontoT(1); // crose line after C
    centerAtJunction(T);
    ontoT(1);  // 2nd crose line after C
    centerAtJunction(T);
    turnAngle(90);
    ontoL(1);
    centerAtJunction(L);
    turnAngle(-90); // before the dash liine
    onToDashLine();
    inDashLine();
    centerAtJunction(T);
    turnAngle(-90);
    ontoBreakPoint(1);
    pushButton(); // push button
    ontoL(1);
    centerAtJunction(L);
    ontoL(1);
    centerAtJunction(L);
    ontoT(1); // before the ramp
    centerAtJunction(T);
    ontoT(1); // after the ramp
    centerAtJunction(T);
    ontoL(1);
    centerAtJunction(L);
    turnAngle(90);
    onToMesh( );

    while(1) {}
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
