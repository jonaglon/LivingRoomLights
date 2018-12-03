int currentPattern = 1;
int numPatterns = 10;

void doLights() {

  //allOff();
  testAllOn();
/*
  if (currentPattern == 0) {
    allOneColor(userColR,userColG,userColB);
  } else if (currentPattern == 1) {
    allOneColor(0, 0, 0);
  } else if (currentPattern == 2) {
    allOneColor(60, 20, 20);
  } else if (currentPattern == 3) {
    allOneColor(20, 20, 60);
  } else if (currentPattern == 4) {    
    allOneColor(20, 60, 20);
  } else if (currentPattern == 5) {    
    allOneColor(100, 0, 0);
  } else if (currentPattern == 6) {    
    allOneColor(0, 100, 0);
  } else if (currentPattern == 7) {    
    allOneColor(0, 0, 100);
  } else if (currentPattern == 8) {    
    allOneColor(50, 50, 50);
  } else if (currentPattern == 9) {    
    allOneColor(userColR,userColG,userColB);
  } else {
    doPatternBlobs();
  }*/
}

void testAllOn() {
  for(int j = 0; j < 690; j++) {
      rgbwLeds[j].r = 30;
      rgbwLeds[j].g = 20;
      rgbwLeds[j].b = 20;
  }
}



void changeLightPattern(int newPatternNum) {
  // choose a new pattern, different from the current one
  currentPattern = newPatternNum;
}

/////////////////////
// Generic patters //
/////////////////////



void horizontalRainbow(bool includeEyes, bool includeMouth, int speedFactor) {
  int ticko = (timey / speedFactor) % 1024;
  
  for(int j = 0; j < numLedsTotal; j++) {
    int xCoord = (getCoord(j,0)+ticko)%1024;
    setLedDirect(j, wheelR, wheelG, wheelB, 0);    
  }
}
