
void(* resetFunc)(void) = 00;

void reset()//ISR for reset
{
  Start(); //turning off all the functions
  //beep(0);
  //light(' ');
  resetFunc();
}

void menu()     //change - 11
{
menu:
  lcd.clear();
  delay(50);
  lcd.print("** DOMINATOR **");
  lcd.setCursor(0, 1);
  lcd.print("Main  Cal.  Set.");

  checkButtonPress();

  if (customKey == 'A') loop(); //run main code

  else if (customKey == 'B') qtrSave(); //run calibration

  else if (customKey == 'C') manner = 'M';  //speed medium

  else if (customKey == 'D') manner = 'F';  //speed Fast

  else if (customKey == 'E') manner = 'V';  //speed Very Fast

  else lcd.print("Hello");
}

void settings()
{
  lcd.clear();
  lcd.print("Settings");
  lcd.setCursor(0, 1);
}

void refresh(float var)
{
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(var);
}

void checkButtonPress()
{
  //debouncing check is required
  while (1)
  {
    customKey = customKeypad.getKey();
    if (customKey) break;
  }
  delay(250);
}
