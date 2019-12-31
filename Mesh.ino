

void goHome() {
  lineMode = 0;

  //  path[0] = 'R';
  //  path[1] = 'L';
  //  path[2] = 'S';
  //  path[3] = 'R';
  //  path[4] = 'L';
  //  pathLength = 5;
  int i = pathLength - 1;
  while (i >= 0) {
    char j = path[i];
    switch (j) {
      case 'L':
        red();
        //turn right
        turn('R');
        break;

      case 'R':
        //turn left
        turn('L');
        break;

      case 'S':
        //skip junction
        skipTurn();
        break;
    }
    i--;
  }
  lineMode = 1;
}


//=====================================Line Maze==============================

void lineMzaSolve() {
  lineMode = 0;
  setLineFollow( manner );
  while (!status) {
    checkJunctionMaze();
    light('O');
    switch (mode) {
      case NO_LINE:
        brake('B');
        centerAtJunction(T);
        turnAngle(180);
        recIntersection('B');
        //centerAtWhiteLine();
        lineFollowInMash();
        break;

      case CONT_LINE:
        brake('B');
        doubleLight();
        centerAtJunction(T);
        checkJunctionMaze();
        if (mode == END_MAZE) {
          red();
          mazeEnd();
        }
        turnAngle(90);
        recIntersection('R');
        //centerAtWhiteLine();
        lineFollowInMash();
        break;

      case RIGHT_TURN:
        brake('B');
        rightLight();
        centerAtJunction(L);
        turnAngle(90);
        recIntersection('R');
        //centerAtWhiteLine();
        lineFollowInMash();
        break;

      case LEFT_TURN:
        brake('B');
        leftLight();
        centerAtJunction(L);
        checkJunctionMaze();
        if (mode == NO_LINE) {
          turnAngle(-90);
          recIntersection('L');
          //centerAtWhiteLine();
          lineFollowInMash();
        }
        else {
          recIntersection('S');
          //centerAtWhiteLine();
          lineFollowInMash();
        }
        break;
      case FOLLOWING_LINE:
        light('B');
        lineFollowInMash();
        break;

      case END_MAZE:
        brake('B');
        
        checkJunctionMaze();
        //        if ( mode != END_MAZE ) {
        //          break;
        //        }
        light('R');
        mazeEnd();
        break;
    }

  }
  lineMode = 1;
}

//------------------------------------------------------------------------
void recIntersection(char direction)
{
  path[pathLength] = direction; // Store the intersection in the path variable.
  pathLength ++;
  simplifyPath(); // Simplify the learned path.
}

void simplifyPath()
{
  // only simplify the path if the second-to-last turn was a 'B'
  if (pathLength < 3 || path[pathLength - 2] != 'B')
    return;

  int totalAngle = 0;
  int i;
  for (i = 1; i <= 3; i++)
  {
    switch (path[pathLength - i])
    {
      case 'R':
        totalAngle += 90;
        break;
      case 'L':
        totalAngle += 270;
        break;
      case 'B':
        totalAngle += 180;
        break;
    }
  }

  // Get the angle as a number between 0 and 360 degrees.
  totalAngle = totalAngle % 360;

  // Replace all of those turns with a single one.
  switch (totalAngle)
  {
    case 0:
      path[pathLength - 3] = 'S';
      break;
    case 90:
      path[pathLength - 3] = 'R';
      break;
    case 180:
      path[pathLength - 3] = 'B';
      break;
    case 270:
      path[pathLength - 3] = 'L';
      break;
  }

  // The path is now two steps shorter.
  pathLength -= 2;

}


void mazeTurn (char dir)
{
  switch (dir)
  {
    case 'L': // Turn Left
      brake();
      delay(50);
      checkJunctionMaze();
      if (mode != LEFT_TURN ) {
        break;
      }
      centerAtJunction(L);
      delay(20);
      turnAngle(-90);
      delay(20);
      brake();

    case 'R': // Turn Right
      brake();
      delay(50);
      checkJunctionMaze();
      if (mode != RIGHT_TURN ) {
        break;
      }
      centerAtJunction(L);
      checkJunctionMaze();
      if (mode == NO_LINE) {
        turnAngle(90);
      }
      else {
        lineFollowInMash();
      }
      break;

    case 'B': // Turn Back
      brake();
      delay(50);
      checkJunctionMaze();
      if (mode != NO_LINE ) {
        break;
      }
      //centerAtJunction();
      turnAngle(180);
      delay(20);
      lineFollowInMash();
      break;

    case 'S': // Go Straight
      lineFollowInMash();
      break;
  }
}



void checkJunctionMaze() {
  qtrReadMesh();
  junctionMaze = ' ';

  bool L = dval[2] ;
  bool R = dval[13] ;
  bool M = dval[7] && dval[8] ;

  if (L && !R) { //Left junction
    junctionMaze = 'L';
    mode = LEFT_TURN;
  }
  else if (R && !L) { //Right junction
    junctionMaze = 'R';
    mode = RIGHT_TURN;
  }
  else if (L && R && M) { //T junction
    junctionMaze = 'T';
    mode = CONT_LINE;
  }
  else if (!(dval[0] || dval[1] || dval[2] || dval[3] || dval[4] || dval[5] || dval[6] || dval[7] || dval[8]
             || dval[9] || dval[10] || dval[11] || dval[12] || dval[13] || dval[14] || dval[15] )) {
    junctionMaze = 'B';
    mode = NO_LINE;
  }
  else if (L && R && !M) {
    junctionMaze = 'E';
    mode = END_MAZE;
  }
  else {
    mode = FOLLOWING_LINE;
  }
}

void mazeEnd() {
  mode = STOPPED;
  lineMode = 1;
  status = 1;
}


void qtrReadMesh()
{
  uint16_t position = qtr.readLineWhite(sensorValues);
  //  uint16_t position = qtr.readLineBlack(sensorValues);

  for (int i = 0; i < SensorCount ; i++ )
  {
    if (sensorValues[i] > 750) dval[i] = 0;
    else dval[i] = 1;
  }
}
