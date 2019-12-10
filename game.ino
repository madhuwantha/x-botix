void game() {
  while ( 1 ) {
    lineFollow();
  }
}

void firstRound() {
  while ( 1 ) {
    leaveSquare(); // start
    ontoL(0); // to A
    centerAtJunction(); //to A
    turnAngle(90); //to A
    ontoT(1); // A
    // detect the color oneColor( tcsN );
    turnAngle(180);
    ontoT(0);
    centerAtJunction();
    turnAngle(90);
    ontoT(0);
    centerAtJunction();
    encoderMove(skipJunction);
    ontoT( 1 ); //  break point B twoColor( tcsN, tcsO );
    //detect color B 1
    setLineFollow('B');
    ontoL(0);
    setLineFollow(manner);
    centerAtJunction();
    turnAngle(-90);
    ontoL(0);
    centerAtJunction();
    turnAngle(90);
    ontoL(0);
    centerAtJunction();
    turnAngle(90);
    ontoT(1);
    //detect color B  2  twoColor( tcsN, tcsO );
    setLineFollow('B');
    ontoL(0);
    setLineFollow(manner);
    turnAngle(90);
    ontoL(0);
    centerAtJunction();
    turnAngle(-90);
    ontoT(0);
    centerAtJunction();
    turnAngle(90); // finishedd the B
    ontoT(0);
    centerAtJunction();
    turnAngle(-90);
    ontoT(1);
    enterSquare();
    IndicateinC();
    delay(1000);
    light( 'O' );
    encoderbackTurn();
    leaveSquare();
    ontoT(0); // crose line after C
    centerAtJunction();
    encoderMove(skipJunction);
    ontoT(0);  // 2nd crose line after C
    centerAtJunction();
    turnAngle(90);
    ontoL(0);
    centerAtJunction();
    turnAngle(-90); // before the dash liine
    onToDashLine();
    centerAtJunction();
    turnAngle(-90);
    encoderMove( 400 );
    turnAngle(180);
    pushButton(); // push button
    ontoL(0);
    centerAtJunction();
    ontoL(0);
    centerAtJunction();
    ontoT(0); // before the ramp
    centerAtJunction();
    ontoT(0); // after the ramp
    centerAtJunction();
    ontoL(0);
    centerAtJunction();
    turnAngle(90);
    onToMesh( );
    mesh(); // mesh
    ontoL(0);
    centerAtJunction();
    turnAngle(-90);
    ontoL(0);
    centerAtJunction();
    turnAngle(-90);
    ontoT(1); // in the room 1
    getSword();
    turnAngle(180);
    ontoT(0);
    centerAtJunction();
    turnAngle(90);
    ontoL(0);
    centerAtJunction();
    turnAngle(90);
    onToMesh( );
    goHome(); // shotest path
    ontoL(0);
    centerAtJunction();
    turnAngle(-90);
    ontoT(0);
    centerAtJunction();
    ontoT(0);
    centerAtJunction();
    ontoL(0);
    centerAtJunction();
    turnAngle(-90);
    ontoL(0);
    centerAtJunction();
    turnAngle(90); // before the J
  }
}
