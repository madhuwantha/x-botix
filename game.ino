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
    // detect the color
    turnAngle(180);
    ontoT(0);
    centerAtJunction();
    turnAngle(90);
    ontoT(0);
    centerAtJunction();
    encoderMove(100);
    ontoT( 1 ); //  break point B
    //detect color B
    setLineFollow('B');
    ontoL(0);
    setLineFollow(manner);
    turnAngle(180); //B
    encoderMove(250); //B
    turnAngle(180); 
    
    ontoL(0); // L in B
    centerAtJunction();
    turnAngle(-90);
    ontoL(0);
    centerAtJunction();
    turnAngle(90);
    ontoL(0);
    centerAtJunction();
    turnAngle(90);
    ontoT(1);
    //detect color // B
    
  }
}
