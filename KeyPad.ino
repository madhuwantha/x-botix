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
          keyPad ();
          break;
        case 'B': // medium
          junctionCount = 210;
          T = 190;
          L = 190;
          manner = 'F';
          brakeTime = 30;
          keyPad();
          break;
        case 'C': // fast
          junctionCount = 210;
          T = 240;
          L = 240;
          manner = 'V';
          brakeTime = 30;
          keyPad ();
          break;
        case 'D': // verry fast
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
