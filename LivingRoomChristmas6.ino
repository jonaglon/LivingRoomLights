
#include<Arduino.h>
#include<Wire.h>
#include<Keypad.h>
#include<FastLED.h>


const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
 {'1','2','3'},
 {'4','5','6'},
 {'7','8','9'},
 {'*','0','#'}
};

byte rowPins[ROWS] = {52, 50, 48, 46}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {44, 42, 40}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

const bool testMode = false;

unsigned long timey;
unsigned int lastBeatTime = 0;
unsigned int timeyInTime; // This is like timey but in time, counting 16384 per beat
int lastBeatLength = 1;
int percentThroughBeat = 0;  // Not really a percent, beat divides into 16384 parts
unsigned long fakeBeatCount = 0;

int currentDance = 0;
int keypadCounter;

int fakeBeatLengh = 420;

// Set by midi in to be 1-16 with beat.
int sixteenBeats = 0;

int mainVolume = 40; // 127 actual max but we won't exceed 100.
int tempMainVolume = 40; // 127 actual max but we won't exceed 100.
int currentBar = 0;
int mixCurrentBar = 0; // This counts from the start of a mix
int currentGenre = 0;
int currentTrack = 0;
int dropCountdown = 0;

const int numLedsStrip = 684;
const int numLedsTotal = numLedsStrip * 4;
CRGB rgbwLeds[numLedsTotal]; // 600 * 4

// LED Intensity
int ledIntensity = 10;
byte wheelR;
byte wheelG;
byte wheelB;

byte userColR=40;
byte userColG=20;
byte userColB=20;



void setup() {

  if (testMode) {
    Serial.begin(9600);
    Serial.println("thg help!");
  }
  
  // Make random more random
  randomSeed(analogRead(0));

  LEDS.addLeds<WS2811_PORTD, 4>(rgbwLeds, numLedsStrip); // Hardcoded to ports:25,26,27,28,14,15
  LEDS.setBrightness(128); // 128 good max, 255 actual /max

}

void loop() {
  
  timey = millis();

  setTimes();

  doKeypad();

  doLights();

  LEDS.show();

  delay(200);

}

void setTimes() {

  if (timey > (lastBeatTime + lastBeatLength)) {
    percentThroughBeat = 16383;
  } else {
    //percentThroughBeat = (((timey-lastBeatTime)*16384)/lastBeatLength)%16384;   // 16384 is a beat length
    percentThroughBeat = (((timey - lastBeatTime) * 16384) / lastBeatLength);
    if (percentThroughBeat > 16383)
      percentThroughBeat = 16383;
  }


  // this is a number to be used in animations, it counts up from the start of a tune, 16384 per beat.
  timeyInTime = ((sixteenBeats * 16384) + percentThroughBeat) + (currentBar * 65536);

  //if (newTimeyInTime > timeyInTime)
  //  timeyInTime = newTimeyInTime;

}



int ledSections[16] = {
  0,     // 0  bottom ring *
  172,   // 1  big heart
  516,   // 2  small heart
  688,   // 3 underarm left
  860,   // 4 overarm left
  1032,   // 5  eye left
  1205,   // 6  eye right
  1377,   // 7  mouth
  1549,   // 8  tape
  1721,   // 9  tuner *
  1893,   // 10 indiciator *
  2066,   // 11 underarm right
  2238,   // 12 overarm right
  2410,   // 13 tube bottomright *
  2582,   // 14 tube bottomleft *
  2754,  // 15 tube topleft *
};


