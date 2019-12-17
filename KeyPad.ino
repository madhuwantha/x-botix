void keyPad () {
  beep();
  while ( 1 ) {
    customKey = customKeypad.getKey();
    if (customKey) {
      doubleLight();
      //Serial.println(customKey);
      switch (customKey)
      {
        case 'A':
          qtrSave();
          delay(500);
          keyPad ();
          break;
        case 'B': // fast
          junctionCount = 210;
          T = 210;
          L = 210;
          manner = 'F';
          brakeTime = 20;
          keyPad();
          break;
        case 'C': // verry fast
          junctionCount = 210;
          T = 210;
          L = 210;
          manner = 'V';
          brakeTime = 30;
          keyPad ();
          break;
        case 'D': // ultra fast
          junctionCount = 210;
          T = 210;
          L = 210;
          manner = 'U';
          brakeTime = 40;
          keyPad ();
          break;
        case 'E': // normal
          junctionCount = 210;
          T = 210;
          L = 210;
          manner = 'N';
          brakeTime = 40;
          keyPad ();
          break;
        case 'F': // start
          temp  = manner;
          qtrLoad();
//          setEncoderPID('F');
          setLineFollow( manner );
          loop();
          break;
      }
      break;
    }
  }
}
