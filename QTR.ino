void checkQTR()
{
  //  uint16_t position = qtr.readLineWhite(sensorValues);
  uint16_t position = qtr.readLineBlack(sensorValues);

  // print the sensor values as numbers from 0 to 1000, where 0 means maximum
  // reflectance and 1000 means minimum reflectance, followed by the line
  // position
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println(position);

  delay(50);
}

void qtrRead()
{
  //  uint16_t position = qtr.readLineWhite(sensorValues);
  uint16_t position = qtr.readLineBlack(sensorValues);

  for (int i = 0; i < SensorCount ; i++ )
  {
    if (sensorValues[i] < 600) dval[i] = 0;
    else dval[i] = 1;
  }
}

void qtrDigitalCheck()
{
  qtrRead();
  for (int i = 0; i < SensorCount ; i++ )
  {
    Serial.print(dval[i]);
    Serial.print("    ");
  }
  Serial.println("");
  delay(50);
}

void qtrLoad()
{
  qtr.calibrate();
  for (int i = 0; i < SensorCount; i++)
  {
    qtr.calibrationOn.minimum[i] = EEPROM.read(i);
    qtr.calibrationOn.maximum[i] = 5 * (EEPROM.read(i + 20));   //change - 14     EEFROM position should be change ===>> i+20
  }

}





//Saving Calibration Values ---------------------------------------------------------------------

void qtrSave()      //change - 15     encoder count should be changed
{
  //beep(100, 100, 100, 50);

  //  leftCount = 0;
  //  rightCount = 0;
  //
  //  for (int i = 0; i < 3; i++)
  //  {
  //    leftTurn(200, 200);
  //    while (leftCount <= 150 && rightCount <= 150) qtr.calibrate();
  //
  //    brake();
  //    leftCount = 0;
  //    rightCount = 0;
  //    delay(100);
  //
  //    rightTurn(200, 200);
  //    while (leftCount <= 350 && rightCount <= 350) qtr.calibrate();
  //
  //    brake();
  //    leftCount = 0;
  //    rightCount = 0;
  //    delay(100);
  //
  //    leftTurn(200, 200);
  //    while (leftCount <= 150 && rightCount <= 150) qtr.calibrate();
  //
  //    brake();
  //    leftCount = 0;
  //    rightCount = 0;
  //    delay(100);
  //  }
  int i;
  for (int i = 0; i < 100; i++)
    qtr.calibrate();

  brake();
  //Saving to EEPROM
  for (int i = 0; i < SensorCount; i++)
  {
    EEPROM.write(i, qtr.calibrationOn.minimum[i]);
    EEPROM.write(i + 20, (qtr.calibrationOn.maximum[i] / 5)); //change - 13     EEFROM position should be change ===>> i+20
  }
  brake();
  //   beep();

}
