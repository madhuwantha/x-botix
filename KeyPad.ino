void keyPad () {
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
          keyPad ();
          break;
        case 'C':
          manner = 'V';
          keyPad ();
          break;
        case 'D':
          manner = 'U';
          keyPad ();
          break;
        case 'E':

          break;
        case 'F':
          qtrLoad();
          setLineFollow( manner );
          loop();
          break;
      }

      break;
    }
  }
}
