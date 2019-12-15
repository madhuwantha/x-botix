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
        case 'B':
          manner = 'F';
          brakeTime = 20;
          keyPad ();
          break;
        case 'C':
          manner = 'V';
          brakeTime = 30;
          keyPad ();
          break;
        case 'D':
          manner = 'U';
          brakeTime = 40;
          keyPad ();
          break;
        case 'E':
          manner = 'N';
          brakeTime = 40;
          keyPad ();
          break;
        case 'F':
          temp  = manner;
          qtrLoad();
          setEncoderPID('F');
          setLineFollow( manner );
          loop();
          break;
      }
      break;
    }
  }
}
