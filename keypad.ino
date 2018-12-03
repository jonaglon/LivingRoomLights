void doKeypad() {

 char customKey = customKeypad.getKey();

  if (customKey != NO_KEY)
  {
    keypadPressed(customKey);
  }
}

void keypadPressed(char key) {

  if (testMode) {
    Serial.print("k!");
    Serial.println(key);
  }
    
  if (key == '#')
    startColorInput();
  else if (key == '*')
    changeNumber(10);
  else if (key == '1')
    changeNumber(1);
  else if (key == '2')
    changeNumber(2);
  else if (key == '3')
    changeNumber(3);
  else if (key == '4')
    changeNumber(4);
  else if (key == '5')
    changeNumber(5);
  else if (key == '6')
    changeNumber(6);
  else if (key == '7')
    changeNumber(7);
  else if (key == '8')
    changeNumber(8);
  else if (key == '9')
    changeNumber(9);
  else if (key == '0')
    changeNumber(0);

}

void changeNumber(int newPatternNum) {
  changeLightPattern(newPatternNum);
}

void startColorInput() {
  keypadCounter=0;
  userColR=0;
  userColG=0;
  userColB=0;

  bool foundColor = false;
  while (!foundColor) {

    allOneColor(40, 0, 0);
    LEDS.show();

    char customKey = customKeypad.getKey();
    if (customKey != NO_KEY)
    {
      if (customKey == '#')
        foundColor = true;
      if (colGrabKeypadPressed(customKey)) {
        foundColor = true;
      }
    }
  }
  
}

bool colGrabKeypadPressed(char key) {

 int numberToAdd = 0;

 if (key == '0')
    numberToAdd=0;
  else if (key == '1')
    numberToAdd=1;
  else if (key == '2')
    numberToAdd=2;
  else if (key == '3')
    numberToAdd=3;
  else if (key == '4')
    numberToAdd=4;
  else if (key == '5')
    numberToAdd=5;
  else if (key == '6')
    numberToAdd=6;
  else if (key == '7')
    numberToAdd=7;
  else if (key == '8')
    numberToAdd=8;
  else if (key == '9')
    numberToAdd=9;

  if (keypadCounter == 0) {
    userColR = userColR + (100 * numberToAdd);
  }
  else if (keypadCounter == 1) {
    userColR = userColR + (10 * numberToAdd);
  }
  else if (keypadCounter == 2) {
    userColR = userColR + numberToAdd;
  }
  else if (keypadCounter == 3) {
    userColG = userColG + (100 * numberToAdd);
  }
  else if (keypadCounter == 4) {
    userColG = userColG + (10 * numberToAdd);
  }
  else if (keypadCounter == 5) {
    userColG = userColG + numberToAdd;
  }
  else if (keypadCounter == 6) {
    userColB = userColB + (100 * numberToAdd);
  }
  else if (keypadCounter == 7) {
    userColB = userColB + (10 * numberToAdd);
  }
  else if (keypadCounter == 8) {
    userColB = userColB + numberToAdd;
  }
      
  keypadCounter=keypadCounter+1;

    if (testMode) {
      Serial.print("r:");
      Serial.print(userColR);
      Serial.print(" g:");
      Serial.print(userColG);
      Serial.print(" b:");
      Serial.println(userColB);
    }

  if (keypadCounter == 9) {
    currentPattern == 0;
    return true;
  }  else {
    return false;
  }
}

