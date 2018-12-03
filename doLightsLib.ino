
void allOff() {
  for(int j = 0; j < numLedsStrip; j++) {
    setLedDirect(j, 0, 0, 0, 0);
  }
}

void allOn() {
  for(int j = 0; j < numLedsTotal; j++) {
    setLedDirect(j, 40, 20, 20, 0);
  }
}

void allOneColor(int r, int g, int b) {
  for(int j = 0; j < numLedsTotal; j++) {
      setLedDirect(j, r, g, b, 0);
  }
}

void setLedDirect(int ledNum, int rVal, int gVal, int bVal, int wVal) {
    rgbwLeds[ledNum].r = rVal; // + whitey;
    rgbwLeds[ledNum].g = gVal; // + whitey;
    rgbwLeds[ledNum].b = bVal; // + whitey;
}

/*
void setRgbwLed(int ledNumber, int rVal, int gVal, int bVal, int wVal) {
  int newNumber = (ledNumber * 4) / 3;
  short mod = ledNumber % 3;

  if (mod == 0)
  {
    rgbwLeds[newNumber].r = rVal % 256;
    rgbwLeds[newNumber].g = gVal % 256;
    rgbwLeds[newNumber].b = bVal % 256;
    rgbwLeds[newNumber+1].g =wVal % 256;
  }
  else if (mod == 1)
  {
    rgbwLeds[newNumber].r = gVal % 256;
    rgbwLeds[newNumber].b = rVal % 256;
    rgbwLeds[newNumber+1].r =wVal % 256;
    rgbwLeds[newNumber+1].g =bVal % 256;
  }
  else 
  {
    rgbwLeds[newNumber].b = gVal % 256;
    rgbwLeds[newNumber+1].r =bVal % 256;
    rgbwLeds[newNumber+1].g =rVal % 256;
    rgbwLeds[newNumber+1].b =wVal % 256;
  }
}*/


int getCoord(int ledNum, int xOrY) {
  if (ledNum < 2003)
     return 10;
/*  else if (ledNum < 378)
    return bigHeartCoords[ledNum-203][xOrY]+ledPosOffset[1][xOrY];
  else if (ledNum < 463)
    return smHeartCoords[ledNum-378][xOrY]+ledPosOffset[2][xOrY];
  else if (ledNum < 482)
    return armCoords[ledNum-463][xOrY]+ledPosOffset[3][xOrY];
  else if (ledNum < 506)
    return armCoords[ledNum-482][xOrY]+ledPosOffset[4][xOrY];
  else if (ledNum < 599)
    return eyeCoords[ledNum-506][xOrY]+ledPosOffset[5][xOrY];
  else if (ledNum < 692)
    return eyeCoords[ledNum-599][xOrY]+ledPosOffset[6][xOrY];
  else if (ledNum < 710)
    return horizCoords[ledNum-692][xOrY]+ledPosOffset[7][xOrY];
  else if (ledNum < 744)
    return tapeCoords[ledNum-710][xOrY]+ledPosOffset[8][xOrY];
  else if (ledNum < 770)
    return horizCoords[ledNum-744][xOrY]+ledPosOffset[9][xOrY];
  else if (ledNum < 774)
    return horizCoords[ledNum-770][xOrY]+ledPosOffset[10][xOrY];
  else if (ledNum < 797)
    return armCoords[ledNum-774][xOrY]+ledPosOffset[11][xOrY];
  else if (ledNum < 821)
    return armCoords[ledNum-797][xOrY]+ledPosOffset[12][xOrY];
  else if (ledNum < 911)
    return tubeCoords[ledNum-821][xOrY]+ledPosOffset[13][xOrY];
  else if (ledNum < 1001)
    return tubeCoords[ledNum-911][xOrY]+ledPosOffset[14][xOrY];
  else if (ledNum < 1090)
    return tubeCoords[ledNum-1001][xOrY]+ledPosOffset[15][xOrY];
  else if (ledNum < 1179)
    return tubeCoords[ledNum-1090][xOrY]+ledPosOffset[16][xOrY];
  else if (ledNum < 1302)
    return portLCoords[(ledNum-1179)%19][xOrY]+ledPosOffset[17][xOrY];
  else if (ledNum < 1441)
    return portRCoords[(ledNum-1302)%19][xOrY]+ledPosOffset[18][xOrY];  */
}


int quickAbsolute(int number) {
  if (number < 0)
    return number * (-1);
  else
    return number;
}



void SetRgbwWheelVars(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    wheelR = 255 - WheelPos * 3;
    wheelG = 0;
    wheelB = WheelPos * 3;
    return;
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    wheelR = 0;
    wheelG = WheelPos * 3;
    wheelB = 255 - WheelPos * 3;
    return;
  }
  WheelPos -= 170;
  wheelR = WheelPos * 3;
  wheelG = 255 - WheelPos * 3;
  wheelB = 0;
  return;
}

int goodColR, goodColG, goodColB, goodColW;
void setGoodRandomColorVars() {
  int randomNum = random(4);
  switch (randomNum) {
    case 0: 
      goodColR = 255;
      goodColG = 0;
      goodColB = 0;
      goodColW = 0;
      break;
    case 1: 
      goodColR = 0;
      goodColG = 255;
      goodColB = 0;
      goodColW = 0;
      break;
    case 2: 
      goodColR = 0;
      goodColG = 0;
      goodColB = 255;
      goodColW = 0;
      break;
    case 3: 
      goodColR = 0;
      goodColG = 0;
      goodColB = 0;
      goodColW = 255;
      break;
  }
}

void sectionsInTime() {
  int beat4 = sixteenBeats % 4;  
  if (beat4 == 0) {
    setSection(13, 255, 0, 0, 0);
    setSection(14, 0, 255, 0, 0);
    setSection(15, 0, 0, 255, 0);
    setSection(16, 0, 0, 0, 255);
  } else if (beat4 == 1) {
    setSection(14, 255, 0, 0, 0);
    setSection(15, 0, 255, 0, 0);
    setSection(16, 0, 0, 255, 0);
    setSection(13, 0, 0, 0, 255);  
  } else if (beat4 == 2) {
    setSection(15, 255, 0, 0, 0);
    setSection(16, 0, 255, 0, 0);
    setSection(13, 0, 0, 255, 0);
    setSection(14, 0, 0, 0, 255);  
  } else if (beat4 == 3) {
    setSection(16, 255, 0, 0, 0);
    setSection(13, 0, 255, 0, 0);
    setSection(14, 0, 0, 255, 0);
    setSection(15, 0, 0, 0, 255);  
  };
}


void setSection(int section, int r, int g, int b, int w) {
  for(int j = ledSections[section]; j < ledSections[section+1]; j++) { 
    setLedDirect(j, r, g, b, w);
  }
}

